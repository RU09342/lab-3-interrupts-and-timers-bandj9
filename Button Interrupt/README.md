# Button Interrupt
## Objective
The purpose of this lab was to create an LED-blinking microcontroller that changes the speed every time a certain button is pressed.  Whenever the button is pressed the LED changes states.  Once the button is pressed enough times to be at its maximum speed the button is pressed once more to turn off.  When the button is pressed it triggers an interrupt which looks for a falling edge on each pin that is attached to a button.  Once the interrupt is triggered the speed is toggled.  To reduce the boucing effect a while loop continues while the button is held followed by a delay.
![](https://media.giphy.com/media/l1J9PbAA97nCNRTtS/giphy.gif)
