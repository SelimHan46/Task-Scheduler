# STM32 Software Timer Based Task Scheduler
This repository contains a custom-developed software-based timer API and task scheduling algorithm for STM32 microcontrollers.
The task scheduler algorithm built on the specially designed timer API creates 4 independent tasks 
running at different periods and verifies their correct timing through UART outputs.

# Features
Software timer API developed from scratch

Custom-designed multi-task scheduling algorithm

4 tasks running at different periods (500ms, 1s, 2s, 5s)

Task execution monitoring via UART

Support for periodic and one-shot timers

Software timer usage for debounce operations

![image_alt](https://github.com/SelimHan46/Task-Scheduler/blob/d96ed2115c25ff435f044c1bc0be7f5cfba10dfd/Task_Scheduler.png)
