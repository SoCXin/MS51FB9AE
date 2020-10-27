/*--------------------------------------------------------------------------------------*/
/*  Function_Define_MS51_16K.H                                                          */
/*  All IP function define for Nuvoton MS51FB9AE / MS51XB9AE / MS51XB9BE                */
/*--------------------------------------------------------------------------------------*/

extern bit BIT_TMP;

typedef bit                   BIT;
typedef unsigned char         UINT8;
typedef unsigned int          UINT16;
typedef unsigned long         UINT32;

typedef unsigned char         uint8_t;
typedef unsigned int          uint16_t;
typedef unsigned long         uint32_t;

#define Disable  0  
#define Enable   1  
                    
#define TRUE     1  
#define FALSE    0  
                    
#define FAIL     1  
#define PASS     0  
                  
//16 --> 8 x 2
#define HIBYTE(v1)              ((UINT8)((v1)>>8))                      //v1 is UINT16
#define LOBYTE(v1)              ((UINT8)((v1)&0xFF))
//8 x 2 --> 16
#define MAKEWORD(v1,v2)         ((((UINT16)(v1))<<8)+(UINT16)(v2))      //v1,v2 is UINT8
//8 x 4 --> 32
#define MAKELONG(v1,v2,v3,v4)   (UINT32)((v1<<32)+(v2<<16)+(v3<<8)+v4)  //v1,v2,v3,v4 is UINT8
//32 --> 16 x 2
#define YBYTE1(v1)              ((UINT16)((v1)>>16))                    //v1 is UINT32
#define YBYTE0(v1)              ((UINT16)((v1)&0xFFFF))
//32 --> 8 x 4
#define TBYTE3(v1)              ((UINT8)((v1)>>24))                     //v1 is UINT32
#define TBYTE2(v1)              ((UINT8)((v1)>>16))
#define TBYTE1(v1)              ((UINT8)((v1)>>8)) 
#define TBYTE0(v1)              ((UINT8)((v1)&0xFF))

#define SET_BIT0        0x01
#define SET_BIT1        0x02
#define SET_BIT2        0x04
#define SET_BIT3        0x08
#define SET_BIT4        0x10
#define SET_BIT5        0x20
#define SET_BIT6        0x40
#define SET_BIT7        0x80

#define CLR_BIT0        0xFE
#define CLR_BIT1        0xFD
#define CLR_BIT2        0xFB
#define CLR_BIT3        0xF7
#define CLR_BIT4        0xEF
#define CLR_BIT5        0xDF
#define CLR_BIT6        0xBF
#define CLR_BIT7        0x7F

#define nop _nop_();            ((UINT8)((v1)>>8))   
/****************************************************************************/
/* Software loop delay by HIRC, about 3ms 
/****************************************************************************/
#define _delay_()                      \
{                                      \
  unsigned char data i,j;              \
    for (j=0;j<0x1A;j++)               \
    {                                  \
       for (i=0;i<0xff;i++)            \
       {                               \
          _nop_();                     \
       }                               \
    }                                  \
}  
/*****************************************************************************/
/*   POR/LVR/BOD Define                                                      */
/*****************************************************************************/
#define    ENABLE_BOD               BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS=0;TA=0xAA;TA=0x55;BODCON0|=0x80;EA=BIT_TMP
#define    ENABLE_BOD_RESET         BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=0x84;EA=BIT_TMP
#define    DISABLE_BOD              BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS=0;TA=0xAA;TA=0x55;BODCON0&=0x7B;EA=BIT_TMP
 
#define    ENABLE_LVR               BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS=1;TA=0xAA;TA=0x55;LVRDIS=0x00;EA=BIT_TMP
#define    DISABLE_LVR              BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS=1;TA=0xAA;TA=0x55;LVRDIS=0x5A;TA=0xAA;TA=0x55;LVRDIS=0xA5;EA=BIT_TMP

#define    ENABLE_POR               BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS=1;TA=0xAA;TA=0x55;PORDIS=0x00;EA=BIT_TMP;
#define    DISABLE_POR              BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS=1;TA=0xAA;TA=0x55;PORDIS=0x5A;TA=0xAA;TA=0x55;PORDIS=0xA5;EA=BIT_TMP
/*****************************************************************************************
* IAP function process 
*****************************************************************************************/
#define    READ_CID                0x0B
#define    READ_DID                0x0C
#define    READ_UID                0x04

#define    PAGE_ERASE_APROM        0x22
#define    BYTE_READ_APROM         0x00
#define    BYTE_PROGRAM_APROM      0x21

#define    PAGE_ERASE_LDROM        0x62
#define    BYTE_READ_LDROM         0x40
#define    BYTE_PROGRAM_LDROM      0x61

#define    PAGE_ERASE_SPROM        0xA2
#define    BYTE_READ_SPROM         0x80
#define    BYTE_PROGRAM_SPROM      0xA1

#define    PAGE_ERASE_CONFIG       0xE2
#define    BYTE_READ_CONFIG        0xC0
#define    BYTE_PROGRAM_CONFIG     0xE1

#define    CID_READ                0x0B
#define    DID_READ                0x0C
                                   
#define    PAGE_SIZE               128

/*****************************************************************************************
*interrupt function process 
*****************************************************************************************/
#define    ENABLE_GLOBAL_INTERRUPT       EA=1
#define    DISABLE_GLOBAL_INTERRUPT      EA=0
/*ENABLE INTERRUPT*/                     
#define    ENABLE_ADC_INTERRUPT          set_IE_EADC
#define    ENABLE_BOD_INTERRUPT          set_IE_EBOD
#define    ENABLE_UART0_INTERRUPT        set_IE_ES
#define    ENABLE_TIMER1_INTERRUPT       set_IE_ET1
#define    ENABLE_INT1_INTERRUPT         set_IE_EX1
#define    ENABLE_TIMER0_INTERRUPT       set_IE_ET0
#define    ENABLE_INT0_INTERRUPT         set_IE_EX0
                                         
#define    ENABLE_TIMER2_INTERRUPT       set_EIE_ET2
#define    ENABLE_SPI0_INTERRUPT         set_EIE_ESPI 
#define    ENABLE_PWM0_FB_INTERRUPT      set_EIE_EFB0  
#define    ENABLE_WDT_INTERRUPT          set_EIE_EWDT  
#define    ENABLE_PWMM0_INTERRUPT        set_EIE_EPWM0  
#define    ENABLE_CAPTURE_INTERRUPT      set_EIE_ECAP  
#define    ENABLE_PIN_INTERRUPT          set_EIE_EPI  
#define    ENABLE_I2C_INTERRUPT          set_EIE_EI2C
                                         
#define    ENABLE_WKT_INTERRUPT          set_EIE1_EWKT
#define    ENABLE_TIMER3_INTERRUPT       set_EIE1_ET3    
#define    ENABLE_UART1_INTERRUPT        set_EIE1_ES_1

/*DISABLE INTERRUPT*/ 
#define    DISABLE_ADC_INTERRUPT         clr_IE_EADC
#define    DISABLE_BOD_INTERRUPT         clr_IE_EBOD
#define    DISABLE_UART0_INTERRUPT       clr_IE_ES
#define    DISABLE_TIMER1_INTERRUPT      clr_IE_ET1
#define    DISABLE_INT1_INTERRUPT        clr_IE_EX1
#define    DISABLE_TIMER0_INTERRUPT      clr_IE_ET0
#define    DISABLE_INT0_INTERRUPT        clr_IE_EX0
          
#define    DISABLE_TIMER2_INTERRUPT      clr_EIE_ET2
#define    DISABLE_SPI0_INTERRUPT        clr_EIE_ESPI 
#define    DISABLE_PWM0_FB_INTERRUPT     clr_EIE_EFB0  
#define    DISABLE_WDT_INTERRUPT         clr_EIE_EWDT  
#define    DISABLE_PWMM0_INTERRUPT       clr_EIE_EPWM0  
#define    DISABLE_CAPTURE_INTERRUPT     clr_EIE_ECAP  
#define    DISABLE_PIN_INTERRUPT         clr_EIE_EPI  
#define    DISABLE_I2C_INTERRUPT         clr_EIE_EI2C
          
#define    DISABLE_WKT_INTERRUPT         clr_EIE1_EWKT
#define    DISABLE_TIMER3_INTERRUPT      clr_EIE1_ET3    
#define    DISABLE_UART1_INTERRUPT       clr_EIE1_ES_1

/*****************************************************************************************
* For GPIO INIT setting 
*****************************************************************************************/
//------------------- Define Port as Quasi mode  -------------------
#define    P00_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0xFE;P0M2&=0xFE
#define    P01_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0xFD;P0M2&=0xFD
#define    P02_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0xFB;P0M2&=0xFB
#define    P03_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0xF7;P0M2&=0xF7
#define    P04_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0xEF;P0M2&=0xEF
#define    P05_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0xDF;P0M2&=0xDF
#define    P06_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0xBF;P0M2&=0xBF
#define    P07_QUASI_MODE            clr_SFRS_SFRPAGE;P0M1&=0x7F;P0M2&=0x7F
#define    P10_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0xFE;P1M2&=0xFE
#define    P11_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0xFD;P1M2&=0xFD
#define    P12_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0xFB;P1M2&=0xFB
#define    P13_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0xF7;P1M2&=0xF7
#define    P14_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0xEF;P1M2&=0xEF
#define    P15_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0xDF;P1M2&=0xDF
#define    P16_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0xBF;P1M2&=0xBF
#define    P17_QUASI_MODE            clr_SFRS_SFRPAGE;P1M1&=0x7F;P1M2&=0x7F
#define    P30_QUASI_MODE            clr_SFRS_SFRPAGE;P3M1&=0xFE;P3M2&=0xFE
#define    ALL_GPIO_QUASI_MODE       clr_SFRS_SFRPAGE;P0M1=0;P0M2=0;P1M1=0;P1M2=0;P3M1=0;P3M2=0
//------------------- Define Port as Push Pull mode -------------------
#define    P00_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0xFE;P0M2|=0x01
#define    P01_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0xFD;P0M2|=0x02
#define    P02_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0xFB;P0M2|=0x04
#define    P03_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0xF7;P0M2|=0x08
#define    P04_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0xEF;P0M2|=0x10
#define    P05_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0xDF;P0M2|=0x20
#define    P06_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0xBF;P0M2|=0x40
#define    P07_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P0M1&=0x7F;P0M2|=0x80
#define    P10_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0xFE;P1M2|=0x01
#define    P11_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0xFD;P1M2|=0x02
#define    P12_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0xFB;P1M2|=0x04
#define    P13_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0xF7;P1M2|=0x08
#define    P14_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0xEF;P1M2|=0x10
#define    P15_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0xDF;P1M2|=0x20
#define    P16_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0xBF;P1M2|=0x40
#define    P17_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P1M1&=0x7F;P1M2|=0x80
#define    P30_PUSHPULL_MODE         clr_SFRS_SFRPAGE;P3M1&=0xFE;P3M2|=0x01
#define    ALL_GPIO_PUSHPULL_MODE    clr_SFRS_SFRPAGE;P0M1=0;P0M2=0xFF;P1M1=0;P1M2=0xFF;P3M1=0;P3M2=0xFF
//------------------- Define Port as Input Only mode -------------------
#define    P00_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x01;P0M2&=0xFE
#define    P01_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x02;P0M2&=0xFD
#define    P02_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x04;P0M2&=0xFB
#define    P03_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x08;P0M2&=0xF7
#define    P04_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x10;P0M2&=0xEF
#define    P05_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x20;P0M2&=0xDF
#define    P06_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x40;P0M2&=0xBF
#define    P07_INPUT_MODE            clr_SFRS_SFRPAGE;P0M1|=0x80;P0M2&=0x7F
#define    P10_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x01;P1M2&=0xFE
#define    P11_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x02;P1M2&=0xFD
#define    P12_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x04;P1M2&=0xFB
#define    P13_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x08;P1M2&=0xF7
#define    P14_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x10;P1M2&=0xEF
#define    P15_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x20;P1M2&=0xDF
#define    P16_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x40;P1M2&=0xBF
#define    P17_INPUT_MODE            clr_SFRS_SFRPAGE;P1M1|=0x80;P1M2&=0x7F
#define    P30_INPUT_MODE            clr_SFRS_SFRPAGE;P3M1|=0x01;P3M2&=0xFE
#define    ALL_GPIO_INPUT_MODE       clr_SFRS_SFRPAGE;P0M1=0xFF;P0M2=0;P1M1=0xFF;P1M2=0;P3M1=0xFF;P3M2=0
//-------------------Define Port as Open Drain mode -------------------
#define    P00_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x01;P0M2|=0x01
#define    P01_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x02;P0M2|=0x02
#define    P02_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x04;P0M2|=0x04
#define    P03_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x08;P0M2|=0x08
#define    P04_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x10;P0M2|=0x10
#define    P05_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x20;P0M2|=0x20
#define    P06_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x40;P0M2|=0x40
#define    P07_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P0M1|=0x80;P0M2|=0x80
#define    P10_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x01;P1M2|=0x01
#define    P11_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x02;P1M2|=0x02
#define    P12_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x04;P1M2|=0x04
#define    P13_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x08;P1M2|=0x08
#define    P14_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x10;P1M2|=0x10
#define    P15_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x20;P1M2|=0x20
#define    P16_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x40;P1M2|=0x40
#define    P17_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P1M1|=0x80;P1M2|=0x80
#define    P30_OPENDRAIN_MODE        clr_SFRS_SFRPAGE;P3M1|=0x01;P3M2|=0x01
#define    ALL_GPIO_OPENDRAIN_MODE   clr_SFRS_SFRPAGE;P0M1=0xFF;P0M2=0xFF;P1M1=0xFF;P1M2=0xFF;P3M1=0xFF;P3M2=0xFF

/****************************************************************************
   Enable INT port 0~3
***************************************************************************/
#define    ENABLE_INT_PORT0               PICON &= 0xFB;
#define    ENABLE_INT_PORT1               PICON |= 0x01;
#define    ENABLE_INT_PORT2               PICON |= 0x02;
#define    ENABLE_INT_PORT3               PICON |= 0x03;
/*****************************************************************************
 Enable each bit low level trig mode
*****************************************************************************/
#define    ENABLE_BIT7_LOWLEVEL_TRIG      PICON&=0x7F;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_BIT6_LOWLEVEL_TRIG      PICON&=0x7F;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_BIT5_LOWLEVEL_TRIG      PICON&=0xBF;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_BIT4_LOWLEVEL_TRIG      PICON&=0xBF;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_BIT3_LOWLEVEL_TRIG      PICON&=0xDF;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_BIT2_LOWLEVEL_TRIG      PICON&=0xEF;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_BIT1_LOWLEVEL_TRIG      PICON&=0xF7;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_BIT0_LOWLEVEL_TRIG      PICON&=0xFD;PINEN|=0x01;PIPEN&=0xFE
/*****************************************************************************
 Enable each bit high level trig mode
*****************************************************************************/
#define    ENABLE_BIT7_HIGHLEVEL_TRIG     PICON&=0x7F;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_BIT6_HIGHLEVEL_TRIG     PICON&=0x7F;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_BIT5_HIGHLEVEL_TRIG     PICON&=0xBF;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_BIT4_HIGHLEVEL_TRIG     PICON&=0xBF;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_BIT3_HIGHLEVEL_TRIG     PICON&=0xDF;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_BIT2_HIGHLEVEL_TRIG     PICON&=0xEF;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_BIT1_HIGHLEVEL_TRIG     PICON&=0xF7;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_BIT0_HIGHLEVEL_TRIG     PICON&=0xFD;PINEN&=0xFE;PIPEN|=0x01
/*****************************************************************************
 Enable each bit falling edge trig mode
*****************************************************************************/
#define    ENABLE_BIT7_FALLINGEDGE_TRIG   PICON|=0x80;PINEN|=0x80;PIPEN&=0x7F
#define    ENABLE_BIT6_FALLINGEDGE_TRIG   PICON|=0x80;PINEN|=0x40;PIPEN&=0xBF
#define    ENABLE_BIT5_FALLINGEDGE_TRIG   PICON|=0x40;PINEN|=0x20;PIPEN&=0xDF
#define    ENABLE_BIT4_FALLINGEDGE_TRIG   PICON|=0x40;PINEN|=0x10;PIPEN&=0xEF
#define    ENABLE_BIT3_FALLINGEDGE_TRIG   PICON|=0x20;PINEN|=0x08;PIPEN&=0xF7
#define    ENABLE_BIT2_FALLINGEDGE_TRIG   PICON|=0x10;PINEN|=0x04;PIPEN&=0xFB
#define    ENABLE_BIT1_FALLINGEDGE_TRIG   PICON|=0x08;PINEN|=0x02;PIPEN&=0xFD
#define    ENABLE_BIT0_FALLINGEDGE_TRIG   PICON|=0x04;PINEN|=0x01;PIPEN&=0xFE
/*****************************************************************************
 Enable each bit rasing edge trig mode
*****************************************************************************/
#define    ENABLE_BIT7_RISINGEDGE_TRIG    PICON|=0x80;PINEN&=0x7F;PIPEN|=0x80
#define    ENABLE_BIT6_RISINGEDGE_TRIG    PICON|=0x80;PINEN&=0xBF;PIPEN|=0x40
#define    ENABLE_BIT5_RISINGEDGE_TRIG    PICON|=0x40;PINEN&=0xDF;PIPEN|=0x20
#define    ENABLE_BIT4_RISINGEDGE_TRIG    PICON|=0x40;PINEN&=0xEF;PIPEN|=0x10
#define    ENABLE_BIT3_RISINGEDGE_TRIG    PICON|=0x20;PINEN&=0xF7;PIPEN|=0x08
#define    ENABLE_BIT2_RISINGEDGE_TRIG    PICON|=0x10;PINEN&=0xFB;PIPEN|=0x04
#define    ENABLE_BIT1_RISINGEDGE_TRIG    PICON|=0x08;PINEN&=0xFD;PIPEN|=0x02
#define    ENABLE_BIT0_RISINGEDGE_TRIG    PICON|=0x04;PINEN&=0xFE;PIPEN|=0x01

/****************************************************************************************************************/
/* USE Define in option For TIMER VALUE setting is base on " option -> C51 -> Preprocesser Symbols -> Define "  */
/****************************************************************************************************************/
#ifdef FOSC_160000    // if Fsys = 16MHz 
    #define TIMER_DIV12_VALUE_10us       65536-13    //13*12/16000000 = 10 uS,        // Timer divider = 12 for TM0/TM1
    #define TIMER_DIV12_VALUE_100us      65536-130    //130*12/16000000 = 10 uS,      // Timer divider = 12 
    #define TIMER_DIV12_VALUE_1ms        65536-1334  //1334*12/16000000 = 1 mS,       // Timer divider = 12 
    #define TIMER_DIV12_VALUE_10ms       65536-13334  //13334*12/16000000 = 10 mS     // Timer divider = 12 
    #define TIMER_DIV12_VALUE_40ms       65536-53336  //53336*12/16000000 = 40 ms      // Timer divider = 12 
    #define TIMER_DIV4_VALUE_10us        65536-40    //40*4/16000000 = 10 uS,        // Timer divider = 4  for TM2/TM3
    #define TIMER_DIV4_VALUE_100us       65536-400    //400*4/16000000 = 100 us        // Timer divider = 4
    #define TIMER_DIV4_VALUE_200us       65536-800    //800*4/16000000 = 200 us        // Timer divider = 4
    #define TIMER_DIV4_VALUE_416us       65536-1620  //416us
    #define TIMER_DIV4_VALUE_500us       65536-2000  //2000*4/16000000 = 500 us      // Timer divider = 4
    #define TIMER_DIV4_VALUE_1ms         65536-4000  //4000*4/16000000 = 1 mS,       // Timer divider = 4
    #define TIMER_DIV16_VALUE_10ms       65536-10000  //10000*16/16000000 = 10 ms      // Timer  divider = 16
    #define TIMER_DIV64_VALUE_30ms       65536-7500  //7500*64/16000000 = 30 ms      // Timer divider = 64
    #define TIMER_DIV128_VALUE_100ms     65536-12500  //12500*128/16000000 = 100 ms    // Timer divider = 128
    #define TIMER_DIV128_VALUE_200ms     65536-25000  //25000*128/16000000 = 200 ms    // Timer divider = 128
    #define TIMER_DIV256_VALUE_500ms     65536-31250  //31250*256/16000000 = 500 ms   // Timer divider = 256
    #define TIMER_DIV512_VALUE_1s        65536-31250  //31250*512/16000000 = 1 s.      // Timer Divider = 512
#endif
#ifdef FOSC_166000    // if Fsys = 16.6MHz 
    #define TIMER_DIV12_VALUE_10us       65536-14    //14*12/16600000 = 10 uS,        // Timer divider = 12 for TM0/TM1
    #define TIMER_DIV12_VALUE_100us      65536-138    //138*12/16600000 = 100 uS,      // Timer divider = 12 
    #define TIMER_DIV12_VALUE_1ms        65536-1384  //1384*12/16600000 = 1 mS,       // Timer divider = 12 
    #define TIMER_DIV12_VALUE_10ms       65536-13834  //13834*12/16600000 = 10 mS     // Timer divider = 12 
    #define TIMER_DIV12_VALUE_40ms       65536-55333  //55333*12/16600000 = 40 ms      // Timer divider = 12 
    #define TIMER_DIV4_VALUE_10us        65536-41    //41*4/16600000 = 10 uS,        // Timer divider = 4  for TM2/TM3
    #define TIMER_DIV4_VALUE_100us       65536-415    //415*4/16600000 = 100 us        // Timer divider = 4
    #define TIMER_DIV4_VALUE_200us       65536-830    //830*4/16600000 = 200 us        // Timer divider = 4
    #define TIMER_DIV4_VALUE_500us       65536-2075  //2075*4/16600000 = 500 us      // Timer divider = 4
    #define TIMER_DIV4_VALUE_1ms         65536-4150  //4150*4/16600000 = 1 mS,       // Timer divider = 4
    #define TIMER_DIV16_VALUE_10ms       65536-10375  //10375*16/16600000 = 10 ms      // Timer  divider = 16
    #define TIMER_DIV64_VALUE_30ms       65536-7781  //7781*64/16600000 = 30 ms      // Timer divider = 64
    #define TIMER_DIV128_VALUE_100ms     65536-12969  //12969*128/16600000 = 100 ms    // Timer divider = 128
    #define TIMER_DIV128_VALUE_200ms     65536-25937  //25937*128/16600000 = 200 ms    // Timer divider = 128
    #define TIMER_DIV256_VALUE_500ms     65536-32422  //32422*256/16600000 = 500 ms   // Timer divider = 256
    #define TIMER_DIV512_VALUE_1s        65536-32421  //32421*512/16600000 = 1 s.      // Timer Divider = 512
#endif
#ifdef FOSC_240000    // if Fsys = 24MHz 
    #define TIMER_DIV12_VALUE_10us       65536-14    //14*12/16600000 = 10 uS,        // Timer divider = 12 for TM0/TM1
    #define TIMER_DIV12_VALUE_100us      65536-138    //138*12/16600000 = 100 uS,      // Timer divider = 12 
    #define TIMER_DIV12_VALUE_1ms        65536-1384  //1384*12/16600000 = 1 mS,       // Timer divider = 12 
    #define TIMER_DIV12_VALUE_10ms       65536-13834  //13834*12/16600000 = 10 mS     // Timer divider = 12 
    #define TIMER_DIV12_VALUE_40ms       65536-55333  //55333*12/16600000 = 40 ms      // Timer divider = 12 
    #define TIMER_DIV4_VALUE_10us        65536-41    //41*4/16600000 = 10 uS,        // Timer divider = 4  for TM2/TM3
    #define TIMER_DIV4_VALUE_100us       65536-415    //415*4/16600000 = 100 us        // Timer divider = 4
    #define TIMER_DIV4_VALUE_200us       65536-830    //830*4/16600000 = 200 us        // Timer divider = 4
    #define TIMER_DIV4_VALUE_500us       65536-2075  //2075*4/16600000 = 500 us      // Timer divider = 4
    #define TIMER_DIV4_VALUE_1ms         65536-4150  //4150*4/16600000 = 1 mS,       // Timer divider = 4
    #define TIMER_DIV16_VALUE_10ms       65536-10375  //10375*16/16600000 = 10 ms      // Timer  divider = 16
    #define TIMER_DIV64_VALUE_30ms       65536-7781  //7781*64/16600000 = 30 ms      // Timer divider = 64
    #define TIMER_DIV128_VALUE_100ms     65536-12969  //12969*128/16600000 = 100 ms    // Timer divider = 128
    #define TIMER_DIV128_VALUE_200ms     65536-25937  //25937*128/16600000 = 200 ms    // Timer divider = 128
    #define TIMER_DIV256_VALUE_500ms     65536-32422  //32422*256/16600000 = 500 ms   // Timer divider = 256
    #define TIMER_DIV512_VALUE_1s        65536-32421  //32421*512/16600000 = 1 s.      // Timer Divider = 512
#endif

/****************************************************************************************************************/
/* Define TIMER VALUE setting is base on name with Fsys value
/****************************************************************************************************************/
/* define timer base value Fsys = 16MHz */
#define    TIMER_DIV12_VALUE_10us_FOSC_160000       65536-8    //13*12/16000000 = 10 uS,        // Timer divider = 12 for TM0/TM1
#define    TIMER_DIV12_VALUE_100us_FOSC_160000      65536-130    //130*12/16000000 = 10 uS,      // Timer divider = 12 
#define    TIMER_DIV12_VALUE_1ms_FOSC_160000        65536-1334    //1334*12/16000000 = 1 mS,       // Timer divider = 12 
#define    TIMER_DIV12_VALUE_10ms_FOSC_160000       65536-13334    //13334*12/16000000 = 10 mS     // Timer divider = 12 
#define    TIMER_DIV12_VALUE_40ms_FOSC_160000       65536-53336    //53336*12/16000000 = 40 ms      // Timer divider = 12 
#define    TIMER_DIV4_VALUE_10us_FOSC_160000        65536-30    //40*4/16000000 = 10 uS,        // Timer divider = 4  for TM2/TM3
#define    TIMER_DIV4_VALUE_100us_FOSC_160000       65536-400    //400*4/16000000 = 100 us        // Timer divider = 4
#define    TIMER_DIV4_VALUE_200us_FOSC_160000       65536-800    //800*4/16000000 = 200 us        // Timer divider = 4
#define    TIMER_DIV4_VALUE_416us_FOSC_160000       65536-1650
#define    TIMER_DIV4_VALUE_500us_FOSC_160000       65536-2000    //2000*4/16000000 = 500 us      // Timer divider = 4
#define    TIMER_DIV4_VALUE_1ms_FOSC_160000         65536-4000    //4000*4/16000000 = 1 mS,       // Timer divider = 4
#define    TIMER_DIV4_VALUE_10ms_FOSC_160000        65536-40000    //40000*4/16000000 = 10 mS,       // Timer divider = 4
#define    TIMER_DIV16_VALUE_10ms_FOSC_160000       65536-10000    //10000*16/16000000 = 10 ms      // Timer  divider = 16
#define    TIMER_DIV64_VALUE_30ms_FOSC_160000       65536-7500    //7500*64/16000000 = 30 ms      // Timer divider = 64
#define    TIMER_DIV128_VALUE_1ms_FOSC_160000       65536-125      //125*128/16000000 = 1 ms    // Timer divider = 128
#define    TIMER_DIV128_VALUE_10ms_FOSC_160000      65536-1250    //1250*128/16000000 = 10 ms    // Timer divider = 128
#define    TIMER_DIV128_VALUE_100ms_FOSC_160000     65536-12500    //12500*128/16000000 = 100 ms    // Timer divider = 128
#define    TIMER_DIV128_VALUE_200ms_FOSC_160000     65536-25000    //25000*128/16000000 = 200 ms    // Timer divider = 128
#define    TIMER_DIV256_VALUE_500ms_FOSC_160000     65536-31250    //31250*256/16000000 = 500 ms   // Timer divider = 256
#define    TIMER_DIV512_VALUE_100ms_FOSC_160000     65536-3125    //3125*512/16000000 = 100ms.      // Timer Divider = 512
#define    TIMER_DIV512_VALUE_1s_FOSC_160000        65536-31250    //31250*512/16000000 = 1 s.      // Timer Divider = 512
/* define timer base value Fsys = 16.6MHz */
#define    TIMER_DIV12_VALUE_10us_FOSC_166000       65536-14    //14*12/16600000 = 10 uS,        // Timer divider = 12 for TM0/TM1
#define    TIMER_DIV12_VALUE_100us_FOSC_166000      65536-138    //138*12/16600000 = 100 uS,      // Timer divider = 12 
#define    TIMER_DIV12_VALUE_1ms_FOSC_166000        65536-1384  //1384*12/16600000 = 1 mS,       // Timer divider = 12 
#define    TIMER_DIV12_VALUE_10ms_FOSC_166000       65536-13834  //13834*12/16600000 = 10 mS     // Timer divider = 12 
#define    TIMER_DIV12_VALUE_40ms_FOSC_166000       65536-55333  //55333*12/16600000 = 40 ms      // Timer divider = 12 
#define    TIMER_DIV4_VALUE_10us_FOSC_166000        65536-41    //41*4/16600000 = 10 uS,        // Timer divider = 4  for TM2/TM3
#define    TIMER_DIV4_VALUE_100us_FOSC_166000       65536-415    //415*4/16600000 = 100 us        // Timer divider = 4
#define    TIMER_DIV4_VALUE_200us_FOSC_166000       65536-830    //830*4/16600000 = 200 us        // Timer divider = 4
#define    TIMER_DIV4_VALUE_500us_FOSC_166000       65536-2075  //2075*4/16600000 = 500 us      // Timer divider = 4
#define    TIMER_DIV4_VALUE_1ms_FOSC_166000         65536-4150  //4150*4/16600000 = 1 mS,       // Timer divider = 4
#define    TIMER_DIV16_VALUE_10ms_FOSC_166000       65536-10375  //10375*16/16600000 = 10 ms      // Timer  divider = 16
#define    TIMER_DIV64_VALUE_30ms_FOSC_166000       65536-7781  //7781*64/16600000 = 30 ms      // Timer divider = 64
#define    TIMER_DIV128_VALUE_100ms_FOSC_166000     65536-12969  //12969*128/16600000 = 100 ms    // Timer divider = 128
#define    TIMER_DIV128_VALUE_200ms_FOSC_166000     65536-25937  //25937*128/16600000 = 200 ms    // Timer divider = 128
#define    TIMER_DIV256_VALUE_500ms_FOSC_166000     65536-32422  //32422*256/16600000 = 500 ms   // Timer divider = 256
#define    TIMER_DIV512_VALUE_1s_FOSC_166000        65536-32421  //32421*512/16600000 = 1 s.      // Timer Divider = 512
/* define timer base value Fsys = 24 MHz*/
#define    TIMER_DIV12_VALUE_10us_FOSC_240000       65536-20        //20*12/24000000 = 10 uS,        // Timer divider = 12
#define    TIMER_DIV12_VALUE_100us_FOSC_240000      65536-200        //130*12/16000000 = 10 uS,      // Timer divider = 12 
#define    TIMER_DIV12_VALUE_1ms_FOSC_240000        65536-2000      //2000*12/24000000 = 1 mS,       // Timer divider = 12
#define    TIMER_DIV12_VALUE_10ms_FOSC_240000       65536-20000      //2000*12/24000000 = 10 mS       // Timer divider = 12
#define    TIMER_DIV4_VALUE_10us_FOSC_240000        65536-60        //60*4/24000000 = 10 uS,          // Timer divider = 4
#define    TIMER_DIV4_VALUE_100us_FOSC_240000       65536-600        //600*4/24000000 = 100 us      // Timer divider = 4
#define    TIMER_DIV4_VALUE_200us_FOSC_240000       65536-1200      //1200*4/24000000 = 200 us      // Timer divider = 4
#define    TIMER_DIV4_VALUE_500us_FOSC_240000       65536-3000      //3000*4/24000000 = 500 us      // Timer divider = 4
#define    TIMER_DIV4_VALUE_1ms_FOSC_240000         65536-6000      //6000*4/24000000 = 1 mS,         // Timer divider = 4
#define    TIMER_DIV4_VALUE_10ms_FOSC_240000        65536-60000      //60000*4/2400000 = 10 ms
#define    TIMER_DIV16_VALUE_10ms_FOSC_240000       65536-15000      //15000*16/24000000 = 10 ms      // Timer divider = 16
#define    TIMER_DIV64_VALUE_30ms_FOSC_240000       65536-11250      //11250*64/24000000 = 30 ms      // Timer divider = 64
#define    TIMER_DIV128_VALUE_1ms_FOSC_240000       65536-187        //187*128/24000000 = 1 ms      // Timer divider = 128
#define    TIMER_DIV128_VALUE_10ms_FOSC_240000      65536-1875      //1875*128/24000000 = 10 ms      // Timer divider = 128
#define    TIMER_DIV128_VALUE_100ms_FOSC_240000     65536-18750      //18750*128/24000000 = 100 ms      // Timer divider = 128
#define    TIMER_DIV128_VALUE_200ms_FOSC_240000     65536-37500      //37500*128/24000000 = 200 ms      // Timer divider = 128
#define    TIMER_DIV256_VALUE_500ms_FOSC_240000     65536-46875      //46875*256/24000000 = 500 ms       // Timer divider = 256
#define    TIMER_DIV512_VALUE_10ms_FOSC_240000      65536-468        //468*512/24000000 = 100 ms       // Timer divider = 512  
#define    TIMER_DIV512_VALUE_100ms_FOSC_240000     65536-4687      //4687*512/24000000 = 100 ms       // Timer divider = 512
#define    TIMER_DIV512_VALUE_500ms_FOSC_240000     65536-23437      //4687*512/24000000 = 500 ms       // Timer divider = 512
#define    TIMER_DIV512_VALUE_1s_FOSC_240000        65536-46875      //46875*512/24000000 = 1 s.        // Timer Divider = 512

/*******************************************************************************
*   TIMER Function Define
********************************************************************************/
#define    ENABLE_CLOCK_OUT             set_CKCON_CLOEN;
/*-------------------- Timer0 basic define --------------------*/
#define    ENABLE_TIMER0_MODE0           TMOD&=0xF0
#define    ENABLE_TIMER0_MODE1           TMOD&=0xF0;TMOD|=0x01
#define    ENABLE_TIMER0_MODE2           TMOD&=0xF0;TMOD|=0x02
#define    ENABLE_TIMER0_MODE3           TMOD&=0xF0;TMOD|=0x03
#define    TIMER0_FSYS                   set_CKCON_T0M
#define    TIMER0_FSYS_DIV12             clr_CKCON_T0M
                                         
#define    TIMER0_MODE0_ENABLE           TMOD&=0xF0
#define    TIMER0_MODE1_ENABLE           TMOD&=0xF0;TMOD|=0x01
#define    TIMER0_MODE2_ENABLE           TMOD&=0xF0;TMOD|=0x02
#define    TIMER0_MODE3_ENABLE           TMOD&=0xF0;TMOD|=0x03
/*-------------------- Timer1 basic define --------------------*/
#define    ENABLE_TIMER1_MODE0           TMOD&=0x0F
#define    ENABLE_TIMER1_MODE1           TMOD&=0x0F;TMOD|=0x10
#define    ENABLE_TIMER1_MODE2           TMOD&=0x0F;TMOD|=0x20
#define    ENABLE_TIMER1_MODE3           TMOD&=0x0F;TMOD|=0x30
#define    TIMER1_FSYS                   set_CKCON_T1M
#define    TIMER1_FSYS_DIV12             clr_CKCON_T1M
                                         
#define    TIMER1_MODE0_ENABLE           TMOD&=0x0F
#define    TIMER1_MODE1_ENABLE           TMOD&=0x0F;TMOD|=0x10
#define    TIMER1_MODE2_ENABLE           TMOD&=0x0F;TMOD|=0x20
#define    TIMER1_MODE3_ENABLE           TMOD&=0x0F;TMOD|=0x30
//-------------------- Timer2 function define --------------------
#define    TIMER2_DIV_4                  T2MOD|=0x10;T2MOD&=0x9F
#define    TIMER2_DIV_16                 T2MOD|=0x20;T2MOD&=0xAF
#define    TIMER2_DIV_32                 T2MOD|=0x30;T2MOD&=0xBF
#define    TIMER2_DIV_64                 T2MOD|=0x40;T2MOD&=0xCF
#define    TIMER2_DIV_128                T2MOD|=0x50;T2MOD&=0xDF
#define    TIMER2_DIV_256                T2MOD|=0x60;T2MOD&=0xEF
#define    TIMER2_DIV_512                T2MOD|=0x70
#define    TIMER2_Auto_Reload_Delay_Mode        T2CON&=0xFE;T2MOD|=0x80;T2MOD|=0x08
#define    TIMER2_Compare_Capture_Mode          T2CON|=0x01;T2MOD&=0x7F;T2MOD|=0x04
           
#define    TIMER2_CAP0_Capture_Mode      T2CON&=0xFE;T2MOD=0x89
#define    TIMER2_CAP1_Capture_Mode      T2CON&=0xFE;T2MOD=0x8A
#define    TIMER2_CAP2_Capture_Mode      T2CON&=0xFE;T2MOD=0x8B
//-------------------- Timer2 Capture define --------------------
//--- Falling Edge -----
#define    IC0_P12_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC1_P11_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC2_P10_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC3_P00_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC3_P04_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC4_P01_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC5_P03_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC6_P05_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC7_P15_CAP0_FALLINGEDGE_CAPTURE    CAPCON1&=0xFC;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=0x10;CAPCON2|=0x10
           
#define    IC0_P12_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC1_P11_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=0x20;CAPCON0|=0x20
#define    IC2_P10_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC3_P00_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC3_P04_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC4_P01_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC5_P03_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC6_P05_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC7_P15_CAP1_FALLINGEDGE_CAPTURE    CAPCON1&=0xF3;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=0x20;CAPCON2|=0x20
           
#define    IC0_P12_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC1_P11_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x10;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC2_P10_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x20;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC3_P00_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x30;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC3_P04_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x40;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC4_P01_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x50;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC5_P03_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x60;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC6_P05_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x70;CAPCON0|=0x40;CAPCON2|=0x40
#define    IC7_P15_CAP2_FALLINGEDGE_CAPTURE    CAPCON1&=0x0F;CAPCON4&=0xF0;CAPCON4|=0x80;CAPCON0|=0x40;CAPCON2|=0x40

//----- Rising edge ----
#define    IC0_P12_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC1_P11_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC2_P10_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC3_P00_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC3_P04_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC4_P01_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC5_P03_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC6_P05_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=0x10;CAPCON2|=0x10;
#define    IC7_P15_CAP0_RISINGEDGE_CAPTRUE     CAPCON1&=0xFC;CAPCON1|=0x01;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=0x10;CAPCON2|=0x10;
           
#define    IC0_P12_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0FCAPCON0|=0x20;CAPCON2|=0x20;
#define    IC1_P11_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC2_P10_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC3_P00_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC3_P04_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC4_P01_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC5_P03_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC6_P05_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC7_P15_CAP1_RISINGEDGE_CAPTRUE     CAPCON1&=0xF3;CAPCON1|=0x04;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=0x20;CAPCON2|=0x20;
           
#define    IC0_P12_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC1_P11_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x01;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC2_P10_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x02;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC3_P00_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x03;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC3_P04_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x04;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC4_P01_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x05;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC5_P03_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x06;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC6_P05_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x07;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC7_P15_CAP3_RISINGEDGE_CAPTRUE     CAPCON1&=0x0F;CAPCON1|=0x10;CAPCON4&=0xF0;CAPCON4|=0x08;CAPCON0|=0x40;CAPCON2|=0x40;

//-----BOTH  edge ----
#define    IC0_P12_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC1_P11_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x01;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC2_P10_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x02;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC3_P00_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x03;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC3_P04_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x04;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC4_P01_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x05;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC5_P03_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x06;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC6_P05_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x07;CAPCON0|=0x10;CAPCON2|=0x10
#define    IC7_P15_CAP0_BOTHEDGE_CAPTURE       CAPCON1&=0xFC;CAPCON1|=0x02;CAPCON3&=0xF0;CAPCON3|=0x08;CAPCON0|=0x10;CAPCON2|=0x10
           
#define    IC0_P12_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON0|=0x20;CAPCON2|=0x20
#define    IC1_P11_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x10;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC2_P10_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x20;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC3_P00_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x30;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC3_P04_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x40;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC4_P01_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x50;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC5_P03_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x60;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC6_P05_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x70;CAPCON0|=0x20;CAPCON2|=0x20;
#define    IC7_P15_CAP1_BOTHEDGE_CAPTURE       CAPCON1&=0xF3;CAPCON1|=0x08;CAPCON3&=0x0F;CAPCON3|=0x80;CAPCON0|=0x20;CAPCON2|=0x20;
           
#define    IC0_P12_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC1_P11_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x01;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC2_P10_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x02;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC3_P00_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x03;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC3_P04_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x04;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC4_P01_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x05;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC5_P03_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x06;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC6_P05_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x07;CAPCON0|=0x40;CAPCON2|=0x40;
#define    IC7_P15_CAP3_BOTHEDGE_CAPTURE       CAPCON1&=0x0F;CAPCON1|=0x20;CAPCON4&=0xF0;CAPCON4|=0x08;CAPCON0|=0x40;CAPCON2|=0x40;

#define    TIMER2_IC2_DISABLE                  CAPCON0&=0xBF       
#define    TIMER2_IC1_DISABLE                  CAPCON0&=0xDF      
#define    TIMER2_IC0_DISABLE                  CAPCON0&=0xEF  

/*****************************************************************************************
* For PWM setting (From N76E00)
*****************************************************************************************/
//--------- PMW clock source select define ---------------------
#define    PWM_CLOCK_FSYS                    CKCON&=0xBF
#define    PWM_CLOCK_TIMER1                  CKCON|=0x40
/*--------- PWM type define ------------------------------------*/ 
#define    PWM_EDGE_TYPE                     PWMCON1&=0xEF
#define    PWM_CENTER_TYPE                   PWMCON1|=0x10      
/*--------- PWM mode define ------------------------------------*/ 
#define    PWM_IMDEPENDENT_MODE              PWMCON1&=0x3F                
#define    PWM_COMPLEMENTARY_MODE            PWMCON1&=0x3F;PWMCON1|=0x40 
#define    PWM_SYNCHRONIZED_MODE             PWMCON1&=0x3F;PWMCON1|=0x80 
#define    PWM_GP_MODE_ENABLE                PWMCON1|=0x20                
#define    PWM_GP_MODE_DISABLE               PWMCON1&=0xDF
//--------- PWM clock devide define ----------------------------
#define    PWM_CLOCK_DIV_2                   PWMCON1&=0xF8;PWMCON1|=0x01
#define    PWM_CLOCK_DIV_4                   PWMCON1&=0xF8;PWMCON1|=0x02
#define    PWM_CLOCK_DIV_8                   PWMCON1&=0xF8;PWMCON1|=0x03
#define    PWM_CLOCK_DIV_16                  PWMCON1&=0xF8;PWMCON1|=0x04
#define    PWM_CLOCK_DIV_32                  PWMCON1&=0xF8;PWMCON1|=0x05
#define    PWM_CLOCK_DIV_64                  PWMCON1&=0xF8;PWMCON1|=0x06
#define    PWM_CLOCK_DIV_128                 PWMCON1|=0x07                                        
/* --------- PWM I/O select define ------------------------------*/ 
#define    PWM5_P15_OUTPUT_ENABLE            set_SFRS_SFRPAGE;PIOCON1|=0x20;clr_SFRS_SFRPAGE        //P1.5 as PWM5 output enable
#define    PWM5_P03_OUTPUT_ENABLE            PIOCON0|=0x20                                                                                 //P0.3 as PWM5
#define    PWM4_P01_OUTPUT_ENABLE            PIOCON0|=0x10                                                                                 //P0.1 as PWM4 output enable
#define    PWM3_P04_OUTPUT_ENABLE            set_SFRS_SFRPAGE;PIOCON1|=0x08;clr_SFRS_SFRPAGE        //P0.4 as PWM3 output enable
#define    PWM3_P00_OUTPUT_ENABLE            PIOCON0|=0x08                                                                                 //P0.0 as PWM3 
#define    PWM2_P05_OUTPUT_ENABLE            set_SFRS_SFRPAGE;PIOCON1|=0x04;clr_SFRS_SFRPAGE        //P1.0 as PWM2 output enable
#define    PWM2_P10_OUTPUT_ENABLE            PIOCON0|=0x04                                                                                 //P1.0 as PWM2
#define    PWM1_P14_OUTPUT_ENABLE            set_SFRS_SFRPAGE;PIOCON1|=0x02;clr_SFRS_SFRPAGE        //P1.4 as PWM1 output enable
#define    PWM1_P11_OUTPUT_ENABLE            PIOCON0|=0x02                                                                                 //P1.1 as PWM1 
#define    PWM0_P12_OUTPUT_ENABLE            PIOCON0|=0x01                                                                                 //P1.2 as PWM0 output enable
#define    ALL_PWM_OUTPUT_ENABLE             PIOCON0=0xFF;PIOCON1=0xFF

#define    PWM5_P15_OUTPUT_DISABLE           set_SFRS_SFRPAGE;PIOCON1&=0xDF;clr_SFRS_SFRPAGE        //P1.5 as PWM5 output disable
#define    PWM5_P03_OUTPUT_DISABLE           PIOCON0&=0xDF                                                                                 //P0.3 as PWM5
#define    PWM4_P01_OUTPUT_DISABLE           PIOCON0&=0xEF                                                                                 //P0.1 as PWM4 output disable
#define    PWM3_P04_OUTPUT_DISABLE           set_SFRS_SFRPAGE;PIOCON1&=0xF7;clr_SFRS_SFRPAGE        //P0.4 as PWM3 output disable
#define    PWM3_P00_OUTPUT_DISABLE           PIOCON0&=0xF7                                                                                 //P0.0 as PWM3 
#define    PWM2_P05_OUTPUT_DISABLE           set_SFRS_SFRPAGE;PIOCON1&=0xFB;clr_SFRS_SFRPAGE        //P1.0 as PWM2 output disable
#define    PWM2_P10_OUTPUT_DISABLE           PIOCON0&=0xFB                                                                                 //P1.0 as PWM2
#define    PWM1_P14_OUTPUT_DISABLE           set_SFRS_SFRPAGE;PIOCON1&=0xFD;clr_SFRS_SFRPAGE        //P1.4 as PWM1 output disable
#define    PWM1_P11_OUTPUT_DISABLE           PIOCON0&=0xFD                                                                                 //P1.1 as PWM1 
#define    PWM0_P12_OUTPUT_DISABLE           PIOCON0&=0xFE                                                                                 //P1.2 as PWM0 output disable
#define    ALL_PWM_OUTPUT_DISABLE            PIOCON0=0x00;PIOCON1=0x00
//--------- PWM I/O Polarity Control ---------------------------
#define    PWM5_OUTPUT_INVERSE               PNP|=0x20        
#define    PWM4_OUTPUT_INVERSE               PNP|=0x10        
#define    PWM3_OUTPUT_INVERSE               PNP|=0x08        
#define    PWM2_OUTPUT_INVERSE               PNP|=0x04        
#define    PWM1_OUTPUT_INVERSE               PNP|=0x02        
#define    PWM0_OUTPUT_INVERSE               PNP|=0x01        
#define    PWM_OUTPUT_ALL_INVERSE            PNP|=0xFF
#define    PWM5_OUTPUT_NORMAL                PNP&=0xDF        
#define    PWM4_OUTPUT_NORMAL                PNP&=0xEF        
#define    PWM3_OUTPUT_NORMAL                PNP&=0xF7        
#define    PWM2_OUTPUT_NORMAL                PNP&=0xFB        
#define    PWM1_OUTPUT_NORMAL                PNP&=0xFD        
#define    PWM0_OUTPUT_NORMAL                PNP&=0xFE        
#define    PWM_OUTPUT_ALL_NORMAL             PNP&=0x00

//--------- PMW interrupt setting ------------------------------
#define    PWM_FALLING_INT                   set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x00;clr_SFRS_SFRPAGE
#define    PWM_RISING_INT                    set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x10;clr_SFRS_SFRPAGE
#define    PWM_CENTRAL_POINT_INT             set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x20;clr_SFRS_SFRPAGE
#define    PWM_PERIOD_END_INT                set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x30;clr_SFRS_SFRPAGE
//--------- PWM interrupt pin select ---------------------------
#define    PWM_INT_PWM0                      set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x00;clr_SFRS_SFRPAGE
#define    PWM_INT_PWM1                      set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x01;clr_SFRS_SFRPAGE
#define    PWM_INT_PWM2                      set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x02;clr_SFRS_SFRPAGE
#define    PWM_INT_PWM3                      set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x03;clr_SFRS_SFRPAGE
#define    PWM_INT_PWM4                      set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x04;clr_SFRS_SFRPAGE
#define    PWM_INT_PWM5                      set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x05;clr_SFRS_SFRPAGE
//--------- PWM Dead time setting ------------------------------
#define    PWM45_DEADTIME_ENABLE             BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x04;EA=BIT_TMP
#define    PWM23_DEADTIME_ENABLE             BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x02;EA=BIT_TMP
#define    PWM01_DEADTIME_ENABLE             BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x01;EA=BIT_TMP

/*****************************************************************************************
* For PWM0 setting 
*****************************************************************************************/
//--------- PMW0 clock source select define ---------------------
#define    PWM0_CLOCK_FSYS                   CKCON&=0xBF
#define    PWM0_CLOCK_TIMER1                 CKCON|=0x40
/*--------- PWM type define ------------------------------------*/ 
#define    PWM0_EDGE_TYPE                    PWMCON1&=0xEF
#define    PWM0_CENTER_TYPE                  PWMCON1|=0x10      
/*--------- PWM mode define ------------------------------------*/ 
#define    PWM0_IMDEPENDENT_MODE             PWMCON1&=0x3F                
#define    PWM0_COMPLEMENTARY_MODE           PWMCON1&=0x3F;PWMCON1|=0x40 
#define    PWM0_SYNCHRONIZED_MODE            PWMCON1&=0x3F;PWMCON1|=0x80 
#define    PWM0_GP_MODE_ENABLE               PWMCON1|=0x20                
#define    PWM0_GP_MODE_DISABLE              PWMCON1&=0xDF
//--------- PWM0 clock devide define ----------------------------
#define    PWM0_CLOCK_DIV_2                  PWMCON1|=0x01;PWMCON1&=0xF9
#define    PWM0_CLOCK_DIV_4                  PWMCON1|=0x02;PWMCON1&=0xFA
#define    PWM0_CLOCK_DIV_8                  PWMCON1|=0x03;PWMCON1&=0xFB
#define    PWM0_CLOCK_DIV_16                 PWMCON1|=0x04;PWMCON1&=0xFC
#define    PWM0_CLOCK_DIV_32                 PWMCON1|=0x05;PWMCON1&=0xFD
#define    PWM0_CLOCK_DIV_64                 PWMCON1|=0x06;PWMCON1&=0xFE
#define    PWM0_CLOCK_DIV_128                PWMCON1|=0x07
/* --------- PWM0 I/O select define ------------------------------*/ 
#define    ENABLE_PWM0_CH5_P15_OUTPUT        set_SFRS_SFRPAGE;PIOCON1|=0x20;clr_SFRS_SFRPAGE        //P1.5 as PWM5 output enable 
#define    ENABLE_PWM0_CH5_P03_OUTPUT        PIOCON0|=0x20                                                                                 //P0.3 as PWM5               
#define    ENABLE_PWM0_CH4_P01_OUTPUT        PIOCON0|=0x10                                                                                 //P0.1 as PWM4 output enable 
#define    ENABLE_PWM0_CH3_P04_OUTPUT        set_SFRS_SFRPAGE;PIOCON1|=0x08;clr_SFRS_SFRPAGE        //P0.4 as PWM3 output enable 
#define    ENABLE_PWM0_CH3_P00_OUTPUT        PIOCON0|=0x08                                                                                 //P0.0 as PWM3               
#define    ENABLE_PWM0_CH2_P05_OUTPUT        set_SFRS_SFRPAGE;PIOCON1|=0x04;clr_SFRS_SFRPAGE        //P1.0 as PWM2 output enable 
#define    ENABLE_PWM0_CH2_P10_OUTPUT        PIOCON0|=0x04                                                                                 //P1.0 as PWM2               
#define    ENABLE_PWM0_CH1_P14_OUTPUT        set_SFRS_SFRPAGE;PIOCON1|=0x02;clr_SFRS_SFRPAGE        //P1.4 as PWM1 output enable 
#define    ENABLE_PWM0_CH1_P11_OUTPUT        PIOCON0|=0x02                                                                                 //P1.1 as PWM1               
#define    ENABLE_PWM0_CH0_P12_OUTPUT        PIOCON0|=0x01                                                                                 //P1.2 as PWM0 output enable 
#define    ENABLE_ALL_PWM0_OUTPUT            PIOCON0=0xFF;PIOCON1=0xFF
                                                                                                  
#define    DISABLE_PWM0_CH5_P15_OUTPUT       set_SFRS_SFRPAGE;PIOCON1&=0xDF;clr_SFRS_SFRPAGE        //P1.5 as PWM5 output disable
#define    DISABLE_PWM0_CH5_P03_OUTPUT       PIOCON0&=0xDF                                                                                 //P0.3 as PWM5               
#define    DISABLE_PWM0_CH4_P01_OUTPUT       PIOCON0&=0xEF                                                                                 //P0.1 as PWM4 output disable
#define    DISABLE_PWM0_CH3_P04_OUTPUT       set_SFRS_SFRPAGE;PIOCON1&=0xF7;clr_SFRS_SFRPAGE        //P0.4 as PWM3 output disable
#define    DISABLE_PWM0_CH3_P00_OUTPUT       PIOCON0&=0xF7                                                                                 //P0.0 as PWM3               
#define    DISABLE_PWM0_CH2_P05_OUTPUT       set_SFRS_SFRPAGE;PIOCON1&=0xFB;clr_SFRS_SFRPAGE        //P1.0 as PWM2 output disable
#define    DISABLE_PWM0_CH2_P10_OUTPUT       PIOCON0&=0xFB                                                                                 //P1.0 as PWM2               
#define    DISABLE_PWM0_CH1_P14_OUTPUT       set_SFRS_SFRPAGE;PIOCON1&=0xFD;clr_SFRS_SFRPAGE        //P1.4 as PWM1 output disable
#define    DISABLE_PWM0_CH1_P11_OUTPUT       PIOCON0&=0xFD                                                                                 //P1.1 as PWM1               
#define    DISABLE_PWM0_CH0_P12_OUTPUT       PIOCON0&=0xFE                                                                                 //P1.2 as PWM0 output disable
#define    DISABLE_ALL_PWM0_OUTPUT           PIOCON0=0x00;PIOCON1=0x00                                                                                                  
//--------- PWM0 I/O Polarity Control ---------------------------
#define    PWM0_CH5_OUTPUT_INVERSE           PNP|=0x20        
#define    PWM0_CH4_OUTPUT_INVERSE           PNP|=0x10        
#define    PWM0_CH3_OUTPUT_INVERSE           PNP|=0x08        
#define    PWM0_CH2_OUTPUT_INVERSE           PNP|=0x04        
#define    PWM0_CH1_OUTPUT_INVERSE           PNP|=0x02        
#define    PWM0_CH0_OUTPUT_INVERSE           PNP|=0x01        
#define    PWM0_OUTPUT_ALL_INVERSE           PNP|=0xFF
#define    PWM0_CH5_OUTPUT_NORMAL            PNP&=0xDF        
#define    PWM0_CH4_OUTPUT_NORMAL            PNP&=0xEF        
#define    PWM0_CH3_OUTPUT_NORMAL            PNP&=0xF7        
#define    PWM0_CH2_OUTPUT_NORMAL            PNP&=0xFB        
#define    PWM0_CH1_OUTPUT_NORMAL            PNP&=0xFD        
#define    PWM0_CH0_OUTPUT_NORMAL            PNP&=0xFE        
#define    PWM0_OUTPUT_ALL_NORMAL            PNP&=0x00

//--------- PMW0 interrupt setting ------------------------------
#define    PWM0_FALLING_INT                  set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x00;clr_SFRS_SFRPAGE
#define    PWM0_RISING_INT                   set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x10;clr_SFRS_SFRPAGE
#define    PWM0_CENTRAL_POINT_INT            set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x20;clr_SFRS_SFRPAGE
#define    PWM0_PERIOD_END_INT               set_SFRS_SFRPAGE;PWMINTC&=0xCF;PWMINTC|=0x30;clr_SFRS_SFRPAGE
//--------- PWM0 interrupt pin select ---------------------------
#define    PWM0_INT_PWM0                     set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x00;clr_SFRS_SFRPAGE
#define    PWM0_INT_PWM1                     set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x01;clr_SFRS_SFRPAGE
#define    PWM0_INT_PWM2                     set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x02;clr_SFRS_SFRPAGE
#define    PWM0_INT_PWM3                     set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x03;clr_SFRS_SFRPAGE
#define    PWM0_INT_PWM4                     set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x04;clr_SFRS_SFRPAGE
#define    PWM0_INT_PWM5                     set_SFRS_SFRPAGE;PWMINTC&=0xF8;PWMINTC|=0x05;clr_SFRS_SFRPAGE
//--------- PWM0 Dead time setting ------------------------------
#define    ENABLE_PWM0_CH45_DEADTIME         BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x04;EA=BIT_TMP
#define    ENABLE_PWM0_CH23_DEADTIME         BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x02;EA=BIT_TMP
#define    ENABLE_PWM0_CH01_DEADTIME         BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;PDTEN|=0x01;EA=BIT_TMP

/*****************************************************************************************
* For ADC INIT setting 
*****************************************************************************************/
#define    ENABLE_ADC_AIN0                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x00;P17_INPUT_MODE;AINDIDS=0;AINDIDS|=0x01;ADCCON1|=1    //P17
#define    ENABLE_ADC_AIN1                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x01;P30_INPUT_MODE;AINDIDS=0;AINDIDS|=0x02;ADCCON1|=1    //P30
#define    ENABLE_ADC_AIN2                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x02;P07_INPUT_MODE;AINDIDS=0;AINDIDS|=0x04;ADCCON1|=1    //P07
#define    ENABLE_ADC_AIN3                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x03;P06_INPUT_MODE;AINDIDS=0;AINDIDS|=0x08;ADCCON1|=1    //P06
#define    ENABLE_ADC_AIN4                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x04;P05_INPUT_MODE;AINDIDS=0;AINDIDS|=0x10;ADCCON1|=1    //P05
#define    ENABLE_ADC_AIN5                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x05;P04_INPUT_MODE;AINDIDS=0;AINDIDS|=0x20;ADCCON1|=1    //P04
#define    ENABLE_ADC_AIN6                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x06;P03_INPUT_MODE;AINDIDS=0;AINDIDS|=0x40;ADCCON1|=1    //P03
#define    ENABLE_ADC_AIN7                   clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x07;P11_INPUT_MODE;AINDIDS=0;AINDIDS|=0x80;ADCCON1|=1    //P11

#define    ENABLE_ADC_CH0                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x00;P17_INPUT_MODE;AINDIDS=0;AINDIDS|=0x01;ADCCON1|=1    //P17
#define    ENABLE_ADC_CH1                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x01;P30_INPUT_MODE;AINDIDS=0;AINDIDS|=0x02;ADCCON1|=1    //P30
#define    ENABLE_ADC_CH2                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x02;P07_INPUT_MODE;AINDIDS=0;AINDIDS|=0x04;ADCCON1|=1    //P07
#define    ENABLE_ADC_CH3                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x03;P06_INPUT_MODE;AINDIDS=0;AINDIDS|=0x08;ADCCON1|=1    //P06
#define    ENABLE_ADC_CH4                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x04;P05_INPUT_MODE;AINDIDS=0;AINDIDS|=0x10;ADCCON1|=1    //P05
#define    ENABLE_ADC_CH5                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x05;P04_INPUT_MODE;AINDIDS=0;AINDIDS|=0x20;ADCCON1|=1    //P04
#define    ENABLE_ADC_CH6                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x06;P03_INPUT_MODE;AINDIDS=0;AINDIDS|=0x40;ADCCON1|=1    //P03
#define    ENABLE_ADC_CH7                    clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x07;P11_INPUT_MODE;AINDIDS=0;AINDIDS|=0x80;ADCCON1|=1    //P11

#define    ENABLE_ADC_BANDGAP                clr_SFRS_SFRPAGE;ADCCON0&=0xF0;ADCCON0|=0x08;ADCCON0&=0xF8;ADCCON1|=1                             //Band-gap 1.22V
#define    DISABLE_ADC                       clr_SFRS_SFRPAGE;ADCCON1&=0xFE;

/* PWM trig ADC start define */ 

/* PWM0 trig ADC start define */
#define    PWM0_FALLINGEDGE_TRIG_ADC         clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x00;ADCCON1|=0x02
#define    PWM2_FALLINGEDGE_TRIG_ADC         clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x00;ADCCON1|=0x02
#define    PWM4_FALLINGEDGE_TRIG_ADC         clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM0_RISINGEDGE_TRIG_ADC          clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM2_RISINGEDGE_TRIG_ADC          clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM4_RISINGEDGE_TRIG_ADC          clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x06;ADCCON1|=0x02
#define    PWM0_CENTRAL_TRIG_ADC             clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x08;ADCCON1|=0x02
#define    PWM2_CENTRAL_TRIG_ADC             clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x08;ADCCON1|=0x02
#define    PWM4_CENTRAL_TRIG_ADC             clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x08;ADCCON1|=0x02
#define    PWM0_END_TRIG_ADC                 clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x0C;ADCCON1|=0x02
#define    PWM2_END_TRIG_ADC                 clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x0C;ADCCON1|=0x02
#define    PWM4_END_TRIG_ADC                 clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x0C;ADCCON1|=0x02
          
#define    PWM0_CH0_FALLINGEDGE_TRIG_ADC     clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x00;ADCCON1|=0x02
#define    PWM0_CH2_FALLINGEDGE_TRIG_ADC     clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x00;ADCCON1|=0x02
#define    PWM0_CH4_FALLINGEDGE_TRIG_ADC     clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM0_CH0_RISINGEDGE_TRIG_ADC      clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM0_CH2_RISINGEDGE_TRIG_ADC      clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02
#define    PWM0_CH4_RISINGEDGE_TRIG_ADC      clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x06;ADCCON1|=0x02
#define    PWM0_CH0_CENTRAL_TRIG_ADC         clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x08;ADCCON1|=0x02
#define    PWM0_CH2_CENTRAL_TRIG_ADC         clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x08;ADCCON1|=0x02
#define    PWM0_CH4_CENTRAL_TRIG_ADC         clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x08;ADCCON1|=0x02
#define    PWM0_CH0_END_TRIG_ADC             clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x00;ADCCON1&=0xF3;ADCCON1|=0x0C;ADCCON1|=0x02
#define    PWM0_CH2_END_TRIG_ADC             clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x10;ADCCON1&=0xF3;ADCCON1|=0x0C;ADCCON1|=0x02
#define    PWM0_CH4_END_TRIG_ADC             clr_SFRS_SFRPAGE;ADCCON0&=0xCF;ADCCON0|=0x20;ADCCON1&=0xF3;ADCCON1|=0x0C;ADCCON1|=0x02

/* GPIO trig ADC start define*/
#define    P04_FALLINGEDGE_TRIG_ADC          clr_SFRS_SFRPAGE;ADCCON0|=0x30;ADCCON1&=0xBF;ADCCON1&=0xF3;ADCCON1|=0x00;ADCCON1|=0x02
#define    P13_FALLINGEDGE_TRIG_ADC          clr_SFRS_SFRPAGE;ADCCON0|=0x30;ADCCON1|=0x40;ADCCON1&=0xF3;ADCCON1|=0x00;ADCCON1|=0x02
#define    P04_RISINGEDGE_TRIG_ADC           clr_SFRS_SFRPAGE;ADCCON0|=0x30;ADCCON1&=0xBF;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02
#define    P13_RISINGEDGE_TRIG_ADC           clr_SFRS_SFRPAGE;ADCCON0|=0x30;ADCCON1&=0xF7;ADCCON1&=0xF3;ADCCON1|=0x04;ADCCON1|=0x02

/*****************************************************************************************
* For SPI INIT setting 
*****************************************************************************************/
#define    SPICLK_FSYS_DIV2                  clr_SFRS_SFRPAGE;SPCR&=0xFC
#define    SPICLK_FSYS_DIV4                  clr_SFRS_SFRPAGE;SPCR&=0xFC;SPCR|=0x01
#define    SPICLK_FSYS_DIV8                  clr_SFRS_SFRPAGE;SPCR&=0xFC;SPCR|=0x02
#define    SPICLK_FSYS_DIV16                 clr_SFRS_SFRPAGE;SPCR&=0xFC;SPCR|=0x03

#define    SS    P15
/*****************************************************************************************
* For BOD enable/disable setting 
*****************************************************************************************/
#define    BOD_DISABLE                        BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=0x7B;EA=BIT_TMP
#define    BOD_ENABLE                         BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=0x80;EA=BIT_TMP
#define    BOD_RESET_ENABLE                   BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=0x84;EA=BIT_TMP
/*****************************************************************************************
* For UART0 and UART1 and printf funcion 
*****************************************************************************************/
#define    ENABLE_UART0_PRINTF                set_SCON_TI;PRINTFG=1            //For printf function must setting TI = 1
#define    DISABLE_UART0_PRINTF               clr_SCON_TI;PRINTFG=0
#define    ENABLE_UART1_PRINTF                set_SCON_1_TI_1;PRINTFG=1
#define    DISABLE_UART1_PRINTF               clr_SCON_1_TI_1;PRINTFG=0
/*****************************************************************************************
* INT0 setting
*****************************************************************************************/
#define    INT0_FALLING_EDGE_TRIG             set_TCON_IT0
#define    INT0_LOW_LEVEL_TRIG                clr_TCON_IT0

/*****************************************************************************************
* INT1 setting
*****************************************************************************************/
#define    INT1_FALLING_EDGE_TRIG             set_TCON_IT1
#define    INT1_LOW_LEVEL_TRIG                clr_TCON_IT1

/**********************************/
#define    TIMER0_FSYS                        set_CKCON_T0M
#define    TIMER0_FSYS_DIV12                  clr_CKCON_T0M
                                              
#define    TIMER1_FSYS                        set_CKCON_T1M
#define    TIMER1_FSYS_DIV12                  clr_CKCON_T1M