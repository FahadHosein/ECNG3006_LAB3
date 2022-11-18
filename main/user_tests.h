#include "user_main.h"

void verification_test_gpio_on(void *arg)
{
    // Configure GPIO prior to testing
    gpio_config_t io_conf;

    // GPIO OUTPUT Configuration
    io_conf.intr_type = GPIO_INTR_DISABLE;           // disable interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;                 // set as output mode
    io_conf.pin_bit_mask = (1ULL << GPIO_OUTPUT_IO); // bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pull_down_en = 0;                        // disable pull-down mode
    io_conf.pull_up_en = 0;                          // disable pull-up mode
    gpio_config(&io_conf);                           // configure GPIO with the given settings
    xSemaphore = xSemaphoreCreateMutex();
    xSemaphoreGive(xSemaphore);

    xTaskCreate(gpio_on, "gpio_on_task", 2048, NULL, 1, NULL);
}
