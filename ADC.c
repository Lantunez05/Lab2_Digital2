#include "ADC.h"
#define _XTAL_FREQ 4000000

void adc_init(int channel)
{
    //Activar el ADC
    ADCON0bits.ADON = 1;
    
    __delay_ms(2);
    
      if(channel == 0)
          ADCON0bits.CHS = 0b0000;  //AN0
      else if(channel == 1)
          ADCON0bits.CHS = 0b0001;  //AN1
      else if(channel == 2)
          ADCON0bits.CHS = 0b0010;    //AN2
      else if(channel == 3)
          ADCON0bits.CHS = 0b0011;    //AN3
      else if(channel == 4)
          ADCON0bits.CHS = 0b0100;    //AN4
      else if(channel == 5)
          ADCON0bits.CHS = 0b0101;    //AN5
      else if(channel == 6)
          ADCON0bits.CHS = 0b0110;  //AN6
    
    //voltaje de referencia
    ADCON1bits.VCFG1 = 0;      // Volatje de referencia 0
    ADCON1bits.VCFG0 = 0;      // Volatje de referencia 0   
    
    //interrupciones
    PIE1bits.ADIE = 1;
    ADIF = 0;
 
    ADCON0bits.ADCS = 0b01; // divisor de reloj de 32
    ADCON1bits.ADFM = 0;    // Justificado a la izquierda 
}

int adc_read()
{
    
    return ADRESH;
}

void adc_change_channel(int channel)
{
    if(channel < 14) 
        ADCON0bits.CHS = channel;  
    else 
        ADCON0bits.CHS = 0b0000;  
   
    return;
}

int adc_get_channel()
{
    char chan = ADCON0bits.CHS;
    return chan; 
}
