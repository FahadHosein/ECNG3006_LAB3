# ECNG3006: Lab 3
This project is based off an example from the espressif ESP8266_RTOS_SDK (https://github.com/espressif/ESP8266_RTOS_SDK). The 'gpio' example was used to conduct the required exercises. The project contains four branches, namely: master, unit-test, integration-test, verification-test.

## Integration Testing
For integration testing, a custom function was created to test the "gpio_on" function within the project. This test required a single modification of the "gpio_on" function, whereby a break was added at the end of the top-level while loop within the function. This was done to allow for the function to terminate, and allow the test function to continue running. "gpio_on" was nested within another function, "gpio_main" which was called by the test function.

The test function calls "gpio_main". Within "gpio_main", the GPIO pin is configured, following which "gpio_on" is called. It is expected that after this runs, the level of the GPIO should be "0" (NOTE: For the on-board LED of the ESP, 0 corresponds with LED ON, and 1 corresponds to LED OFF). The test function then calls "gpio_get_level" If the value of "gpio_get_level" is 0, then the test passes, otherwise, the test fails.

### Test
**Pre-Conditions:** 3.3V power supply to working ESP8266 circuit, and GPIO pin configured.

**Input:** Call "gpio_main()", followed by "gpio_get_level".

**Expected Output:** "gpio_get_level" returns a value of 0.

**Output:** "gpio_get_level" returns a value of 0.

### RISE Reflection
For integration testing, a driver function was used to call the "gpio_on" function, which was previously unit-tested. The driver function, namely, "gpio_main" was used to configure the GPIO pin, following which, the function "gpio_on" was called. The test function for the integration test was similar to that of the test function for the unit test, with the difference being that the function called "gpio_main" instead of "gpio_on", and the GPIO configuration was removed from the test function and placed within "gpio_main". Following this, the same boolean check was used as that of the unit test function to determine whether the value of the GPIO pin was successfully changed. This can be improved by integrating additional functions such as "gpio_off" within the driver function to determine if the system functions as expected with multiple integrated units.