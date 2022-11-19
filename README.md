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

### RISE Reflection
For unit testing, my own structure was used as opposed to the Unity framework, as this allowed test functions to be custom-made to suit the units under test. For the unit test, the "gpio_on" function was tested, however, this was a void function and did not return any values. As a result, this made it more difficult to implement the Unity test framework. The test function instead made use of the "gpio_get_level" command, to determine whether the "gpio_on" function executed successfully. A simple boolean check was used along with a conditional statement to check if the GPIO level was either 1 or 0. Since these tests made use of the onboard LED on the ESP8266, a GPIO level of 0 indicates the LED is ON, and 1 indicates OFF. The Unity test framework can be implemented to test functions that return a value. For example, "esp_err_t" functions can be implemented and if successfully executed, the test functions can assert "ESP_OK".