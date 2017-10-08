#include <msp430g2553.h>

 //Button Interrupt
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //watchdog timer control
    P1DIR = BIT0 + BIT6; //make P1.0 the output pin
    P1REN = BIT3; //internal resistor is enabled, P1.3 connects to either Vcc (3.6V) or ground
    P1OUT = ~(BIT0 + BIT6); //P1.3 is an input pin

    P1IE |= BIT3;         // P1.3 interrupt enabled
    P1IFG &= ~BIT3;       // P1.3 IFG cleared
    __enable_interrupt();   // intrinsic function

    while(1)
    {}
}


    // Port 1 interrupt service routine
    #pragma vector=PORT1_VECTOR
    __interrupt void Port_1(void)
    {
    // Add INTERRUPT SERVICE ROUTINE HERE.
        P1OUT ^=BIT0+BIT6;
        P1IFG &= ~BIT3; // P1.3 IFG cleared
        P1IES ^=BIT3;
    }
