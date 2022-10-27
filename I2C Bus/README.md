Inter-Integrated Circuit :: I2C


How to configure an I2C in C programming:

- You can connect multiple slaves to a single master.
- Can connect many devices to other peripherals.
- Require 2 wires. To connect.
- A better alternative to UART - no limitations.
- The Serial peripheral interface(SPI) requires many GPIOS
- Is open drain - can damage drivers and excess power dissipation.


* ACK : Acknowledgement, control of SDA line(slave / master) - send and receive..
* SDA (Serial Data) – The line for the master and slave to send and receive data.
* SCL (Serial Clock) – The line that carries the clock signal.

