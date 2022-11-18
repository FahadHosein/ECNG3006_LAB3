#include "user_tests.h"

void app_main(void)
{
//   unit_test_gpio_on(NULL);
//   integration_test_gpio_on(NULL);
   verification_test_gpio_on(NULL);         // Remove the "break;" at the end of "gpio_on" function in "user_main.h" for this to work
}