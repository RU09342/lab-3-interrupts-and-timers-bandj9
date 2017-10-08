#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed to reset device
    P1SEL0 = 0x00; //sets P1 to GPIO
    P1SEL1 = 0x00; //sets P1 to GPIO
    P1DIR = BIT0; //sets LED at P1.0 to output
    P5REN = BIT6; //Resistor enabled for button P5.6
    P5OUT = BIT6; //Sets resistor to pull up for button, 1 when not pressed

    PM5CTL0 &= ~LOCKLPM5;

    P5IE |= BIT6; //interupt enable for button P1.1
    P5IES |= BIT6; //sets interupt to trigger on falling edge (button press)
    P5IFG &= ~BIT6; //Clears interupt flag register

    __bis_SR_register(GIE); //global interupt enable (enables all maskable interupts)

    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CCR0 = 6000; //register that timer will compare itself too
    TA0CTL = TASSEL_2 + ID_3 + MC_1 + TACLR; // SMCLK, divide clock by 8, up mode, clear TAR

    for(;;){}
    return 0;
}

#pragma vector=PORT5_VECTOR
__interrupt void Port_5(void){
    if ((P5IN&BIT6)==0x0000) //if button pressed
    {
    P5IES &= ~BIT6; //sets interupt to trigger on rising edge (button release)
    TA0CTL = TASSEL_2 + ID_3 + MC_2 + TACLR; // SMCLK, divide clock by 8, continous mode, clear TAR
    P5IFG &= ~BIT6; //clear interupt flag
    }
    else //if button released
    {
    P5IES |= BIT6; //sets interupt to trigger on falling edge (button press)
    TA0CCR0 = TA0R; //changes ccr0 to value of timer
    TA0CTL = TASSEL_2 + ID_3 + MC_1 + TACLR; // SMCLK, divide clock by 8, up mode, clear TAR
    P5IFG &= ~BIT6; //clears interupt flag
    }
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void){
            P1OUT ^= BIT0; //toggles LED when interupt triggered
}