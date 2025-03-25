# Board-Designer-Competition
This repository present solution for the Board Designer Competition 

[Board Designer Competition](https://www.hackster.io/contests/board-designer).

## Introduction
**First of all thank you to Nordic Semiconductor, Autodesk, PCBWay and hackster.io for hosting this exciting competition.**

The main project is primarily summarized on hackster.io, so please refer to it there 

[Maker's nRF54L15 Debug Board](https://www.hackster.io/iotengineer22/maker-s-nrf54l15-debug-board-1a6a88)

In this project, we provide Maker's nRF54L15 Debug Board. We have designed a compact board featuring the powerful nRF54L15 Wireless SOC.

![3D1](imgs/3D1.png)

## Structure
    .
    ├── pcb                 # PCB files(autodesk, gerber, bom, schematics)   
    ├── src                 # Program files (board, program)   
    ├── LICENSE
    └── README.md


## Electrical Diagram overview

This is Main electrical diagram.

![schematics](pcb/schematics/hardware_ble_test v59-schematics.pdf)




### 1. PYNQ + GPIO(LED Blinking)
For details and specifications, please refer to the hackster.io Subproject below.

[Control GPIO from PYNQ and KR260](https://www.hackster.io/iotengineer22/control-gpio-from-pynq-and-kr260-0d3613)

In this Subproject, we experimented with controlling GPIO on the KR260 FPGA board.

Using Python (PYNQ) , we managed to perform LED output and switch input via the PMOD connector with custom-designed board.

The test .bit .hwh .ipynb files are available on GitHub.

[/jupyter_notebooks/pynq-gpio](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/tree/main/jupyter_notebooks/pynq-gpio)

![kr260-gpio](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/kr260-gpio.png)
