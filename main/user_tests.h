#include "user_main.h"

static const char *TEST = "test";

void integration_test_gpio_on(void *arg)
{
    int status;
    gpio_main();
    status = gpio_get_level(GPIO_OUTPUT_IO);
    if (status == 0)
    {
        ESP_LOGI(TEST, "Integration Test: gpio_on PASSED!");
    }
    else
    {
        ESP_LOGI(TEST, "Integration Test: gpio_on FAILED!");
    }
}