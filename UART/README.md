UART -  Universal Asynchronous Receiver and transmitter.


This is how to configure UART in C programming

- UART parameters:
1. Baud Rate( 9600,19200,115200). - how many bits per second can be transmitted- depends on the number of clocks.
2. Number of Data Bits (7,8).
3. Parity Bits (On,Off). Whether parity check is enabled.
4. Stop bits (0,1,2).
5. Flow control (None, On, Hardware).


- The process to configure a UART:
1. Initialize the UART
2. Declare a timer.
3. Transmit a single character - Using SBUF
4. Receive from input and process it for output.
5. Interrupt.


