/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//***********************************************************************************************************

#include "MS51_16K.h"


struct
{
    unsigned int a;
    unsigned long b;
    unsigned char  c;

} StructData;

unsigned char ArrayData[50];
unsigned char i;

/**
 * @brief       IAP program dataflash as EEPROM
 * @param       None
 * @return      None
 * @details     define dataflash need be modify address and value,
 */

void main(void)
{
    unsigned int system16highsite;
	
/* UART0 initial setting
  * include sys.c in Library for modify HIRC value to 24MHz
  * include uart.c in Library for UART initial setting
*/
    MODIFY_HIRC(HIRC_24);
    P06_PUSHPULL_MODE;
    UART_Open(24000000,UART0_Timer3,115200);
    ENABLE_UART0_PRINTF;

    /*loop here while P46 = 1; */
    P17_QUASI_MODE;
    while (P17);

    /** IAP program APROM as EEPROM way * include eeprom.c in Library       */
    for (i = 0; i < 50; i++)
    {
        ArrayData[i] = i;
    }

    StructData.a = 0x5555;
    StructData.b = 0x55555555;
    StructData.c = 0x55;

    Write_SPROM_DATAFLASH_ARRAY(1, ArrayData, 50); //write 50 bytes
    Write_SPROM_DATAFLASH_ARRAY(40, (unsigned char *)&StructData, sizeof(StructData)); //write structure

    /*call read byte */
    system16highsite = Read_SPROM_BYTE(31);
    system16highsite = (Read_SPROM_BYTE(31) << 8)+ Read_SPROM_BYTE(32);

    printf("\n system16highsite = 0x%X", system16highsite);
    DISABLE_UART0_PRINTF;

    while (1);
}



