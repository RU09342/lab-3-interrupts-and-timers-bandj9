# TIMER A Blink
## Summary
1. Disable Watchdog timer
2. Intialize registers (1 button, 1 LED, enable interrupts for timer)
3. Set CCR register to Timer A
4. Blink LED at default frequency
5. When button is pressed, the rate of the LED should increase
6. Once rate of blink reaches maximum, it is reset back down to a slower spped.
## Description
Each processor had a different PxSel.  The MSP430FR2311 did not have a Timer A, so the other time Timer B was used instead.  The capture control register had to be used so that one could compare the timer to the register to see if it reached its goal yet.  This register is called TA0CCTL0.  It was set to 60000.  The timer had to be cleared each time.  The LED is toggled when the interrupt is triggered.
## Board Differences
All of the boards had similar code to run the button blink program. There were three processors (5994, 2311, and 6989) that required one extra piece of code. For those boards the high-impedance mode pin is enabled by default. In order for the program to run this pin has to be disabled. The line that had to be added to these boards to disable this pin is as followed: PM5CTL0 &= ~LOCKLPM5
## Project Demonstration
![](https://media.giphy.com/media/l1J9qsbVBMJBgnUOs/giphy.gif)
