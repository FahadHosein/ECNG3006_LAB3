# ECNG3006: Lab 2
This repository consists of three projects based off the example from the espressif ESP8266_RTOS_SDK (https://github.com/espressif/ESP8266_RTOS_SDK). The 'gpio' example was used to conduct the required exercises.

# P1

## sdkconfig
This configuration file is generated for each project created. It contains various configuration parameters required for the device to function correctly. Such parameters include the baud rate, and COM ports. These are namely CONFIG_ESPTOOLPY_BAUD, and CONFIG_ESPTOOLPY_PORT respectively. Incorrect changes to this file can impact the functionality of the device. For example, if the baud rate or COM port is incorrectly defined, the device may not be able to communicate with the host machine.

## sdokconfig.h
This configuration file is generated following a successful build of the project. The parameters specified in 'sdkconfig' are reflected here and are defined as macros using the #DEFINE preprocessor directive. Any changes to the 
'sdkconfig.h' file would have the same effects as if changes were made to the 'sdkconfig' file.

## FreeRTOSConfig.h
This file utilises the 'sdkconfig.h' file, and further specifies application specific definitions for the required hardware and application. It specifies which API functions of the FreeRTOS Kernel should be used. Any changes to this file would take precedence over changes in the 'sdkconfig' and 'sdkconfig.h' files. For example, functions such as 'vTaskDelay' can be implemented by setting the value of "#define INCLUDE_vTaskDelay" to 1, or to 0 if not implemented.

# P2
Task performance can be analysed using the built-in API function which can collect information on the processing time per task. (Source: https://www.freertos.org/rtos-run-time-stats.html)

The Run Time Statistics can be enabled by defining certain macros in the 'FreeRTOSConfig.h' file.
These are:

### 1) #define configGENERATE_RUN_TIME_STATS
This can be enabled by setting the macro to 1.

### 2) #define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
This should be 10 to 100 times faster than the specified tic interrupt. Faster times corresponds to more accurate statistics.

### 3) #define portGET_RUN_TIME_COUNTER_VALUE()
This returns the time configured in the previous macro.

### vTaskGetRunTimeStats()
This API function is used to display the gathered informastion.