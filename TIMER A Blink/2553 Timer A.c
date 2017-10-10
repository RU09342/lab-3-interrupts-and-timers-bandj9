#include <msp430.h> 

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed to reset device
    P1SEL = 0x00; //sets P1 to GPIO
    P1SEL2 = 0x00; //sets P1 to GPIO
    P1DIR = BIT0; //sets LED at P1.0 to output

    __bis_SR_register(GIE); //global interupt enable (enables all maskable interupts)

    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CCR0 = 60000; //register that timer will compare itself too
    TA0CTL = TASSEL_2 + MC_1 + TACLR; // SMCLK, upmode, clear TAR

    for(;;){}
    return 0;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void){
            P1OUT ^= BIT0; //toggles LED when interupt triggered
}