# ECNG3006: Lab 3
This project is based off an example from the espressif ESP8266_RTOS_SDK (https://github.com/espressif/ESP8266_RTOS_SDK). The 'gpio' example was used to conduct the required exercises. The project contains four branches, namely: master, unit-test, integration-test, verification-test.

## Verification Testing
For the verification test, a task was created for the "gpio_on" function. The break at the end of top-level while loop of the "gpio_on" function was removed to allow the task to run continuously.

The test function configures the GPIO pin, following which a task is created for "gpio_on".

### Test
**Pre-Conditions:** 3.3V power supply to working ESP8266 circuit, and GPIO pin configured.

**Input:** Run "xTaskCreate(gpio_on, "gpio_on_task", 2048, NULL, 1, NULL)"

**Expected Output:** The LED on the ESP8266 will turn ON

**Output:** The LED on the ESP8266 turned ON.

### RISE Reflection
For the verification test, additional equipment was not required. The verification test utilised the "xTaskCreate" command, instead of calling the function. To verify the system worked as intended, the LED was observed. On RESET, the LED remained ON, and only turned off when the system was either reset or powered off. This test can also be done using an external LED, however, it must be noted that for the external LED to be in an ON state, the value of the GPIO pin must be 1 instead of 0.