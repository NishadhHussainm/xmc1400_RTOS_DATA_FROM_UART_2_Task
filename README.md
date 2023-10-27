# xmc1400_RTOS_DATA_FROM_UART_2_Task

# FreeRTOS-based Application with DAVE Apps

This repository contains a FreeRTOS-based embedded application developed using DAVE Apps. It demonstrates two tasks running concurrently with different functionality using an XMC microcontroller. Task 1 handles CAN communication, and Task 2 deals with UART and SPI communication.

## Prerequisites

Before using this application, make sure you have the following:

- DAVE Apps installed and configured for your development environment.
- An XMC microcontroller compatible with the provided code.
- An appropriate hardware setup, including LEDs, CAN, UART, and SPI interfaces, as required by your application.

## Usage

1. Clone or download this repository to your development environment.
2. Open the project in your DAVE Apps IDE.
3. Configure your development environment to match the target hardware and connections.
4. Build and flash the application to your XMC microcontroller.

The application consists of two tasks:

### Task 1

Task 1 handles CAN communication. It periodically sends and receives data over the CAN interface. The data received from UART is transmitted over CAN.

### Task 2

Task 2 handles UART and SPI communication. It reads data from UART and forwards it to a SPI interface.

You can customize the tasks and their functionality according to your project requirements.

## Contributing

If you'd like to contribute to this project, please follow these steps:

1. Fork this repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them to your branch.
4. Create a pull request to submit your changes for review.

## License

This code is provided under an open-source license. Please refer to the LICENSE file for details.

## Contact

If you have any questions or need assistance with this project, feel free to contact the maintainers:

nishadh2000@gmail.com

## Acknowledgments

This project is based on the [FreeRTOS](https://www.freertos.org/) real-time operating system.

---


