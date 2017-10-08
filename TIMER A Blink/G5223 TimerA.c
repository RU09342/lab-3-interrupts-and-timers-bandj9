#include <msp430.h>

int rollover = 0;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  P1OUT &= ~BIT0;                           //LED 1 OFF
  P1DIR |= BIT6;                            // P1.6 output
  P1OUT &= ~BIT6;                           //LED 2 OFF
  CCTL0 = CCIE;                             // CCR0 interrupt enabled
  CCR0 = 50000;                             //overflow every 50ms
  TACTL = TASSEL_2 + MC_1;                  // SMCLK, up mode

  __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt

}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
      if(rollover>=10) // 50ms * num, where rollover>=num (50ms * 20 = 1s)
      {
          P1OUT ^= BIT0;                            // Toggle P1.0
          rollover=0;
      }
      else
      {
          rollover++;
      }
  P1OUT ^= BIT6;       //blinks every interrupt
}
