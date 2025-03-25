# Board-Designer-Competition
This repository present solution for the Board Designer Competition 

[Board Designer Competition](https://www.hackster.io/contests/board-designer).

## Introduction
**First of all thank you to Nordic Semiconductor, Autodesk, PCBWay and hackster.io for hosting this exciting competition.**

The main project is primarily summarized on hackster.io, so please refer to it there 

[Maker's nRF54L15 Debug Board](https://www.hackster.io/iotengineer22/maker-s-nrf54l15-debug-board-1a6a88)

In this project, we provide Maker's nRF54L15 Debug Board. We have designed a compact board featuring the powerful nRF54L15 Wireless SOC.

![overview](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/overview.png)

## Structure
    .
    ├── bom                 # BOM file (BOM list)
    ├── jupyter_notebooks   # Jupyter Notebooks (pre-Test Program)
    ├── pcb                 # PCB link files   
    ├── src                 # Python files (Test Program)   
    ├── LICENSE
    └── README.md

## Solution overview

Using KR260 and PYNQ, 360° object detection is processed on the PL (FPGA).

The PL also handles PWM and GPIO for driving the Robot Car and Arm.

By integrating PL and PS, the robot achieves 360-degree AI vision.

![Using KR260 and PYNQ](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/Using-KR260-and-PYNQ.png)

## Electrical Diagram overview

This is Main electrical diagram.

![Main-electrical-diagram](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/Main-electrical-diagram.png)

These are PMOD diagrams.

![PMOD1-diagram](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/PMOD1-diagram.png)

![PMOD2-diagram](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/PMOD2-diagram.png)

![PMOD4-diagram](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/PMOD4-diagram.png)

### 1. PYNQ + GPIO(LED Blinking)
For details and specifications, please refer to the hackster.io Subproject below.

[Control GPIO from PYNQ and KR260](https://www.hackster.io/iotengineer22/control-gpio-from-pynq-and-kr260-0d3613)

In this Subproject, we experimented with controlling GPIO on the KR260 FPGA board.

Using Python (PYNQ) , we managed to perform LED output and switch input via the PMOD connector with custom-designed board.

The test .bit .hwh .ipynb files are available on GitHub.

[/jupyter_notebooks/pynq-gpio](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/tree/main/jupyter_notebooks/pynq-gpio)

![kr260-gpio](https://github.com/iotengineer22/AMD-Pervasive-AI-Developer-Contest/blob/main/imgs/kr260-gpio.png)
