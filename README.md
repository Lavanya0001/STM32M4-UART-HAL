# MinimalRTOS-Kernel

A minimal RTOS kernel implemented from scratch on ARM Cortex-M to understand core scheduling and kernel concepts beyond using existing RTOS libraries.

## Overview
This project demonstrates the internal working of a small RTOS kernel, including task management and scheduling decisions.  
The implementation is intentionally minimal and educational, focusing on clarity and correctness rather than feature completeness.

## Features
- Cooperative scheduling
- Round-Robin scheduling using SysTick time slicing
- Compile-time scheduler selection using macros
- Basic task creation and management
- Demonstration using multiple tasks

## Scheduler Selection
The scheduler is selected at compile time via configuration macros, allowing easy comparison between different scheduling strategies without changing application code.

## File Structure
- `main.c` – Application entry point and task definitions
- `osKernel.c` – Core kernel and scheduler logic
- `rtos_config.h` – RTOS configuration and scheduler selection
- `timebase.c` – Time base support (optional/future use)

## Target Platform
- ARM Cortex-M microcontrollers  
(Tested on STM32 / similar MCUs)

## Motivation
This project was built to gain a deeper understanding of RTOS internals, such as scheduling behavior, time slicing, and kernel design, rather than relying solely on existing RTOS implementations like FreeRTOS.

## Future Work
- Priority-based preemptive scheduler
- Improved task state management
- Architecture-specific port separation
