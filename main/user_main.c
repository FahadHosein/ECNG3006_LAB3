#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

#include "driver/gpio.h"

#include "sys/time.h"

#include "esp_log.h"
#include "esp_system.h"

#define GPIO_OUTPUT_IO      2   // LED

#define LOW_PRIORITY    1
#define MEDIUM_PRIORITY 2
#define HIGH_PRIORITY   3

static const char *TAG = "main";

SemaphoreHandle_t xSemaphore;

static void gpio_wait()
{
    struct timeval p_tv;

    gettimeofday(&p_tv, NULL);
    int64_t startTime = (int64_t)p_tv.tv_sec * 1000000L + (int64_t)p_tv.tv_usec;

    while (1)
    {
        gettimeofday(&p_tv, NULL);
        int64_t currTime = (int64_t)p_tv.tv_sec * 1000000L + (int64_t)p_tv.tv_usec;

        if ((currTime - startTime) >= 500000)
        {
            break;
        }
    }
}

static void gpio_on(void *pvParameters)
{
    while(1)
    {
        while(1)
        {
            if(xSemaphoreTake(xSemaphore, (TickType_t)15 == pdTRUE))
            {
                ESP_LOGI(TAG, "GPIO ON\n");
                gpio_set_level(GPIO_OUTPUT_IO, 1);
                break;
            }
            else continue;
        }
        gpio_wait();
        xSemaphoreGive(xSemaphore);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void gpio_off(void *pvParameters)
{
    while (1)
    {
        while (1)
        {
            if (xSemaphoreTake(xSemaphore, (TickType_t)15 == pdTRUE))
            {
                ESP_LOGI(TAG, "GPIO OFF\n");
                gpio_set_level(GPIO_OUTPUT_IO, 0);
                break;
            }
            else
                continue;
        }
        gpio_wait();
        xSemaphoreGive(xSemaphore);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void gpio_status(void *pvParameters)
{
    while(1)
    {
        ESP_LOGI(TAG, "GPIO STATUS: %d\n", gpio_get_level(GPIO_OUTPUT_IO));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    gpio_config_t io_conf;

    // GPIO OUTPUT Configuration
    io_conf.intr_type = GPIO_INTR_DISABLE;           // disable interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;                 // set as output mode
    io_conf.pin_bit_mask = (1ULL << GPIO_OUTPUT_IO); // bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pull_down_en = 0;                        // disable pull-down mode
    io_conf.pull_up_en = 0;                          // disable pull-up mode
    gpio_config(&io_conf);                           // configure GPIO with the given settings
    xSemaphore = xSemaphoreCreateMutex();

    if (xSemaphore != NULL)
    {
        xTaskCreate(gpio_on, "gpio_on_task", 2048, NULL, MEDIUM_PRIORITY, NULL);
        xTaskCreate(gpio_off, "gpio_off_task", 2048, NULL, LOW_PRIORITY, NULL);
    }

    xTaskCreate(gpio_status, "gpio_status_task", 2048, NULL, HIGH_PRIORITY, NULL);
    for (;;)
        ;
}