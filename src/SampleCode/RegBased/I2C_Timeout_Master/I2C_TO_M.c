/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/29/2020
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: MS51 I2C master mode demo code, the Slave address = 0xA4
//
//   ____________            _____________ 
//  |            |   SDA    |             |
//  |            |<-------->|             |
//  |            |          |             |
//  |MS51(M)     |          | MS51(S)     |
//  |(I2C_Master)|          | (I2C_Slave) |
//  |            |   SCL    |             |
//  |            |--------->|             |
//  |____________|          |_____________|
//
//  The protocol of I2C is master: start -> write 10 byte(ACK) ->stop -> start ->read 10 byte(ACK) -> stop
//  Setting break point in I2C slave to check time out function 
//***********************************************************************************************************


#include "MS51_16K.h"


#define I2C_CLOCK                 13
#define I2C_SLAVE_ADDRESS         0xA4
#define I2C_WR                    0
#define I2C_RD                    1

#define LOOP_SIZE                 10

void I2C_ISR(void) interrupt 6
{
   if (I2TOC&SET_BIT0)    
      while(1);                     /* When into this loop means I2C transmit time out */
}


//========================================================================================================
void Init_I2C(void)
{
    P13_OPENDRAIN_MODE;          // Modify SCL pin to Open drain mode. don't forget the pull high resister in circuit
    P14_OPENDRAIN_MODE;          // Modify SDA pin to Open drain mode. don't forget the pull high resister in circuit

    /* Set I2C clock rate */
    I2CLK = I2C_CLOCK;
   /* Enable I2C time out divier as clock base is Fsys/4, the time out is about 4ms when Fsys = 16MHz */
    set_I2TOC_DIV;
    clr_I2TOC_I2TOF;
   /* Enable I2C intterupt for I2C time out */
    set_EIE_EI2C;                               //enable I2C interrupt by setting IE1 bit 0
    set_IE_EA;

    /* Enable I2C */
    set_I2CON_I2CEN;
}
//========================================================================================================
void I2C_Error(void)
{
    while (1);    
}
//========================================================================================================

//--------------------------------------------------------------------------------------------
//----  Page Write----------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
void I2C_Write_Process(UINT8 u8DAT)
{
    unsigned char  u8Count;

    set_I2TOC_I2TOCEN;                           /* Enable I2C time out */

    /* Write Step1 */
    set_I2CON_STA;                              /* Send Start bit to I2C EEPROM */
    clr_I2CON_SI;
    while (!SI);                                /*Check SI set or not  */
    if (I2STAT != 0x08)                         /*Check status value after every step   */
        I2C_Error();
    
    /* Write Step2 */
    clr_I2CON_STA;                              /*STA=0*/
    I2DAT = (I2C_SLAVE_ADDRESS | I2C_WR);
    clr_I2CON_SI;
    while (!SI);                                /*Check SI set or not */
    if (I2STAT != 0x18)              
        I2C_Error();

    /* Write Step3 */
    for (u8Count = 0; u8Count < LOOP_SIZE; u8Count++)
    {
        I2DAT = u8DAT;
        clr_I2CON_SI;
        while (!SI);                            /*Check SI set or not*/
        if (I2STAT != 0x28)              
            I2C_Error();

        u8DAT = ~u8DAT;        
    }

    /* Write Step4 */
    set_I2CON_STO;
    clr_I2CON_SI;
    while (STO);                                /* Check STOP signal */
  }
  
//--------------------------------------------------------------------------------------------
//----  Page Read ----------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
void I2C_Read_Process(UINT8 u8DAT)
{
    unsigned char  u8Count;
    /* Read Step1 */
    set_I2CON_STA;
    clr_I2CON_SI;          
    while (!SI);                                //Check SI set or not
    if (I2STAT != 0x08)                         //Check status value after every step
        I2C_Error();

    /* Step13 */
    clr_I2CON_STA;                                    //STA needs to be cleared after START codition is generated
    I2DAT = (I2C_SLAVE_ADDRESS | I2C_RD);
    clr_I2CON_SI;
    while (!SI);                                //Check SI set or not
    if (I2STAT != 0x40)              
        I2C_Error();
    
    /* Step14 */
    for (u8Count = 0; u8Count <LOOP_SIZE; u8Count++)
    {
        set_I2CON_AA;
        clr_I2CON_SI;        
        while (!SI);                            //Check SI set or not

        if (I2STAT != 0x50)              
            I2C_Error();
        
        if (I2DAT != u8DAT)             
            I2C_Error();
        u8DAT = ~u8DAT; 
    } 
    
    /* Step15 */
    clr_I2CON_AA;
    clr_I2CON_SI;
    while (!SI);                                //Check SI set or not
    if (I2STAT != 0x58)              
        I2C_Error();

    /* Step16 */
    set_I2CON_STO;
    clr_I2CON_SI;
    while (STO);                                /* Check STOP signal */ 
}
//========================================================================================================
void main(void)
{
    /* Note
       MCU power on system clock is HIRC (22.1184MHz), so Fsys = 22.1184MHz
    */
    
    Init_I2C();                                 /* initial I2C circuit  */
    I2C_Write_Process(0x55);                          /* I2C Master will send 10 byte 0x55,0xAA,.... to slave */
    I2C_Read_Process(0x55);

    while (1);
/* =================== */
}

