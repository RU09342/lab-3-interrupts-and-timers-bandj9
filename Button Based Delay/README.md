# Button Based Delay
## Summary
1. Stop Watchdog timer
2. Initialize registers(1 button, 1 LED, enable interrupts for buttons)
3. Enable interrupts
4. State what happens when button is pressed
## Description
The button had to be set up with an interrupt enable and would trigger on a falling edge.  CCR0 is used for the up counting mode.  The register compares itself to an LED blinking at 10 Hz.  The timer that was used is SMCLK and it was set to count in up mode.
## Board Differences
All of the boards had similar code to run the button blink program. There were three processors (5994, 2311, and 6989) that required one extra piece of code. For those boards the high-impedance mode pin is enabled by default. In order for the program to run this pin has to be disabled. The line that had to be added to these boards to disable this pin is as followed: PM5CTL0 &= ~LOCKLPM5
## Project Demonstration
It may be hard to see in the video demonstration, but the user presses the button and the LED blinks at the rate that the button is held down for.  Sometimes there are bouncing errors in the button which makes it look as though the LED is blinking at a different rate than it was intended to.

![](https://media.giphy.com/media/3ohhwCJWtjgfHUuALu/giphy.gif)
