# ECNG3006: Lab 3
This project is based off an example from the espressif ESP8266_RTOS_SDK (https://github.com/espressif/ESP8266_RTOS_SDK). The 'gpio' example was used to conduct the required exercises. The project contains four branches, namely: master, unit-test, integration-test, verification-test.

## Unit Testing
For unit testing, a custom function was created to test the "gpio_on" function within the project. This test required a single modification of the "gpio_on" function, whereby a break was added at the end of the top-level while loop within the function. This was done to allow for the function to terminate, and allow the test function to continue running.

The test function firstly configures the GPIO pin, calls the "gpio_on" function. It is expected that after this runs, the level of the GPIO should be "0" (NOTE: For the on-board LED of the ESP, 0 corresponds with LED ON, and 1 corresponds to LED OFF). If the value of "gpio_get_level" is 0, then the test passes, otherwise, the test fails.

### Test
**Pre-Conditions:** 3.3V power supply to working ESP8266 circuit, and GPIO pin configured.

**Input:** Call "gpio_on(NULL)", followed by "gpio_get_level".

**Expected Output:** "gpio_get_level" returns a value of 0.

**Output:** "gpio_get_level" returns a value of 0.
