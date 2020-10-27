/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Jan/21/2020
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: MS51 Timer 0 mode 3 demo
//***********************************************************************************************************
#include "MS51_16K.H"



/* if define TIMER0_FSYS_DIV12, Timer0 = (256-56)*12/16MHz = 150us , 
                                Timer1 = (256-200)*12/16MHz = 42us ,
/* if define TIMER0_FSYS, Timer = (256-56)/16MHz = 12.5us
                          Timer = (256-200)/16MHz = 3.5us*/
#define TH0_INIT        56
#define TL0_INIT        200

/************************************************************************************************************
*    TIMER 0 interrupt subroutine
************************************************************************************************************/
void Timer0_ISR (void) interrupt 1              // interrupt address is 0x000B
{
    _push_(SFRS);
                
    TL0 = TL0_INIT;                              
    TF0=0;

    _pop_(SFRS);
}	

void Timer1_ISR (void) interrupt 3              // interrupt address is 0x000B
{
    _push_(SFRS);
                
    TH0 = TH0_INIT;
    TF1=0;

    _pop_(SFRS);
}	

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
    ENABLE_TIMER0_MODE3;
    TIMER0_FSYS;
  
    P05_PUSHPULL_MODE;
    P00_PUSHPULL_MODE;
    set_P2S_T0OE;        /*output at T0 */
    set_P2S_T1OE;        /*Output at T1 */
    
    TH0 = TH0_INIT;                             /*initial counter values  */
    TL0 = TL0_INIT;    
 
    ENABLE_TIMER0_INTERRUPT;                                  /* enable Timer0 interrupt */
    ENABLE_TIMER1_INTERRUPT;                                  /* Enable Timer1 interrupt for T1 output*/
    ENABLE_GLOBAL_INTERRUPT;                    /*enable interrupts*/
    set_TCON_TR0;                               /*Timer0 run */
    set_TCON_TR1;

    while(1);
}

