Embedded System design and IOT 

LCD in ESD's
e

how to setup LCD 

1. Introduction to LCD.
2. Pin details and Descriptions.
3. Schematics 
4. Program.


What is LCD :

Liquid Crystal Display. This is an optical device that has light-modulating properties of liquid crystals combined with polarizers.
Liquid crystals don't emit light directly. They use a backlight or reflector to produce images in color or monochrome…Has a back light.

The LCD can work in two different modes :
Nibble : A nibble is a group of four bits, so the lower four bits (D0-D3) of a byte form the lower nibble while the upper four bits (D4-D7) of a byte form the higher nibble.
The 4-bit mode and the 8-bit mode. In 4 bit mode we send the data nibble by nibble, first upper nibble and then lower nibble.

In 8 bit mode we can send the 8-bit data directly in one stroke since we use all the 8 data lines.

8-bit mode is faster and flawless than 4-bit mode. But the major drawback is that it needs 8 data lines connected to the microcontroller. This will make us run out of I/O pins on our MCU, so 4-bit mode is widely used. No control pins are used to set these modes. It's just the way of programming that change.


