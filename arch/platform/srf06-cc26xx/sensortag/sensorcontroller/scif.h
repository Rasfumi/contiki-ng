/** \mainpage Driver Overview
  *
  * \section section_drv_info Driver Information
  * This Sensor Controller Interface driver has been generated by the Texas Instruments Sensor Controller
  * Studio tool:
  * - <b>Project name</b>:     Capacitive Soil Humidity Sensor
  * - <b>Project file</b>:     C:/Users/Mihi/Documents/Capacitive Soil Humidity/cap_sensor.scp
  * - <b>Code prefix</b>:      -
  * - <b>Operating system</b>: None
  * - <b>Tool version</b>:     2.0.0.324
  * - <b>Tool patches</b>:     None
  * - <b>Target chip</b>:      CC2650, revision -, package QFN48 7x7 RGZ
  * - <b>Created</b>:          2018-01-20 21:46:25.572
  * - <b>Computer</b>:         WIN-4BBEDC4NT59
  * - <b>User</b>:             Mihi
  *
  * No user-provided resource definitions were used to generate this driver.
  *
  * No user-provided procedure definitions were used to generate this driver.
  *
  * Do not edit the generated source code files other than temporarily for debug purposes. Any
  * modifications will be overwritten by the Sensor Controller Studio when generating new output.
  *
  * \section section_drv_modules Driver Modules
  * The driver is divided into three modules:
  * - \ref module_scif_generic_interface, providing the API for:
  *     - Initializing and uninitializing the driver
  *     - Task control (for starting, stopping and executing Sensor Controller tasks)
  *     - Task data exchange (for producing input data to and consume output data from Sensor Controller
  *       tasks)
  * - \ref module_scif_driver_setup, containing:
  *     - The AUX RAM image (Sensor Controller code and data)
  *     - I/O mapping information
  *     - Task data structure information
  *     - Driver setup data, to be used in the driver initialization
  *     - Project-specific functionality
  * - \ref module_scif_osal, for flexible OS support:
  *     - Interfaces with the selected operating system
  *
  * It is possible to use output from multiple Sensor Controller Studio projects in one application. Only
  * one driver setup may be active at a time, but it is possible to switch between these setups. When
  * using this option, there is one instance of the \ref module_scif_generic_interface and
  * \ref module_scif_osal modules, and multiple instances of the \ref module_scif_driver_setup module.
  * This requires that:
  * - The outputs must be generated using the same version of Sensor Controller Studio
  * - The outputs must use the same operating system
  * - The outputs must use different source code prefixes (inserted into all globals of the
  *   \ref module_scif_driver_setup)
  *
  *
  * \section section_project_info Project Description
  * Demonstrates capacitive touch data sampling on the CC2650 SensorTag with Capacitive Touch skin.
  * 
  * The TDC values (time used to charge up each capacitive area from 0 to 0.8 V) for button and slider
  * are output to the System CPU application.
  * The System CPU application transfers the TDC data over UART, so that the data can be logged and
  * processed on the PC.
  * 
  * See the header in the application source file ("main.c" or similar) for further details and
  * instructions. This file is located in the source code output directory.
  *
  *
  * \subsection section_io_mapping I/O Mapping
  * Task I/O functions are mapped to the following pins:
  * - Capacitive Soil Humidity Sensor:
  *     - <b>AXD: Capacitive touch area 0</b>: DIO25
  *
  *
  * \section section_task_info Task Description(s)
  * This driver supports the following task(s):
  *
  *
  * \subsection section_task_desc_capacitive_soil_humidity_sensor Capacitive Soil Humidity Sensor
  * Samples all capacitive touch areas on the CC2650 SensorTag with Capacitive Touch skin.
  * 
  * The TDC values (time used to charge up each capacitive area from 0 to 0.8 V) are output to the System
  * CPU. This includes raw data and IIR-filtered data.
  *
  */




/** \addtogroup module_scif_driver_setup Driver Setup
  *
  * \section section_driver_setup_overview Overview
  *
  * This driver setup instance has been generated for:
  * - <b>Project name</b>:     Capacitive Soil Humidity Sensor
  * - <b>Code prefix</b>:      -
  *
  * The driver setup module contains the generated output from the Sensor Controller Studio project:
  * - Location of task control and scheduling data structures in AUX RAM
  * - The AUX RAM image, and the size the image
  * - Task data structure information (location, size and buffer count)
  * - I/O pin mapping translation table
  * - Task resource initialization and uninitialization functions
  * - Hooks for run-time logging
  *
  * @{
  */
#ifndef SCIF_H
#define SCIF_H

#include <stdint.h>
#include <stdbool.h>
#include "scif_framework.h"
#include "scif_osal_none.h"


/// Target chip name
#define SCIF_TARGET_CHIP_NAME_CC2650
/// Target chip package
#define SCIF_TARGET_CHIP_PACKAGE_QFN48_7X7_RGZ

/// Number of tasks implemented by this driver
#define SCIF_TASK_COUNT 1

/// Capacitive Soil Humidity Sensor: Task ID
#define SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_TASK_ID 0


/// Capacitive Soil Humidity Sensor: Capactive touch pin count
#define SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_PIN_COUNT 1
/// Capacitive Soil Humidity Sensor: 
#define SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_SAMPLE_COUNT 8
/// Capacitive Soil Humidity Sensor I/O mapping: Capacitive touch area
#define SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_DIO_AXD_CAP_TOUCH { 25 }


// All shared data structures in AUX RAM need to be packed
#pragma pack(push, 2)


/// Capacitive Soil Humidity Sensor: Task configuration structure
typedef struct {
    uint16_t pAuxioAxdCapTouch[1]; ///< I/O mapping: Capacitive touch area
} SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_CFG_T;


/// Capacitive Soil Humidity Sensor: Task output data structure
typedef struct {
    uint16_t pTdcValueFilt[1]; ///< TDC value, filtered
    uint16_t pTdcValueRaw[1];  ///< TDC value, raw
} SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_OUTPUT_T;


/// Capacitive Soil Humidity Sensor: Task state structure
typedef struct {
    uint16_t filtInitDone; ///< Has the value filtering been initialized?
} SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_STATE_T;


/// Sensor Controller task data (configuration, input buffer(s), output buffer(s) and internal state)
typedef struct {
    struct {
        SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_CFG_T cfg;
        uint16_t outputSceBufferCtrl;
        uint16_t outputDrvBufferCtrl;
        uint16_t outputScePtr;
        SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_OUTPUT_T pOutput[2];
        SCIF_CAPACITIVE_SOIL_HUMIDITY_SENSOR_STATE_T state;
    } capacitiveSoilHumiditySensor;
} SCIF_TASK_DATA_T;

/// Sensor Controller task generic control (located in AUX RAM)
#define scifTaskData    (*((volatile SCIF_TASK_DATA_T*) 0x400E00EA))


// Initialized internal driver data, to be used in the call to \ref scifInit()
extern const SCIF_DATA_T scifDriverSetup;


// Restore previous struct packing setting
#pragma pack(pop)


// AUX I/O re-initialization functions
void scifReinitTaskIo(uint32_t bvTaskIds);


// RTC-based tick generation control
void scifStartRtcTicks(uint32_t tickStart, uint32_t tickPeriod);
void scifStartRtcTicksNow(uint32_t tickPeriod);
void scifStopRtcTicks(void);


#endif
//@}


// Generated by WIN-4BBEDC4NT59 at 2018-01-20 21:46:25.572