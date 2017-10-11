# TIMER A Blink
Each processor had a different PxSel.  The MSP430FR2311 did not have a Timer A, so the other time Timer B was used instead.  The capture control register had to be used so that one could compare the timer to the register to see if it reached its goal yet.  This register is called TA0CCTL0.  It was set to 60000.  The timer had to be cleared each time.  The LED is toggled when the interrupt is triggered.
![](https://media.giphy.com/media/l1J9qsbVBMJBgnUOs/giphy.gif)
