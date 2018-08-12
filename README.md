# max32660-evkit

This example initializes UART and drives on-board LED.

Connect UART pins as follows:

| MAX32660-EVKIT    | UART-to-USB adapter  |
| ----------------- | -------------------- |
| P0.10 (UART1 TX)  | RX                   |
| P0.11 (UART1 RX)  | TX                   |

UART baud rate: 115200

### Build under Linux

    $ export CROSS_COMPILE=arm-none-eabi-
    $ git clone --recursive https://github.com/osfive/max32660-evkit
    $ cd max32660-evkit
    $ bmake

### Build under FreeBSD

    $ setenv CROSS_COMPILE arm-none-eabi-
    $ git clone --recursive https://github.com/osfive/max32660-evkit
    $ cd max32660-evkit
    $ make

![alt text](https://raw.githubusercontent.com/osfive/max32660-evkit/master/images/max32660-evkit.jpg)
