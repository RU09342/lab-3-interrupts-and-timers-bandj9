# Button Interrupt
## Summary
1. Disable Watchdog timer
2. Initialize Registers(1 LED, 1 button, enable interrupts for button)
3. Blink LED at initial rate
4. When button is pressed increase frequency of blink
5. Once rate of blink has rached maximum, reset to slow speed
## Description
The purpose of this lab was to create an LED-blinking microcontroller that changes the speed every time a certain button is pressed.  Whenever the button is pressed the LED changes states.  Once the button is pressed enough times to be at its maximum speed the button is pressed once more to turn off.  When the button is pressed it triggers an interrupt which looks for a falling edge on each pin that is attached to a button.  Once the interrupt is triggered the speed is toggled.  To reduce the boucing effect a while loop continues while the button is held followed by a delay.

## Board Differences
All of the boards had similar code to run the button blink program. There were three processors (5994, 2311, and 6989) that required one extra piece of code. For those boards the high-impedance mode pin is enabled by default. In order for the program to run this pin has to be disabled. The line that had to be added to these boards to disable this pin is as followed: PM5CTL0 &= ~LOCKLPM5
## Project Demonstration
The board that is demonstrated for the button blink project is MSP430G2553.  The video shows that a button is pressed to toggle on and the same button is pressed to toggle off.

![](https://media.giphy.com/media/l1J9PbAA97nCNRTtS/giphy.gif)
