/* 
 * File:   ADC.h
 * Author: Luis Antunez
 *
 * Created on 20 de julio de 2023, 02:22 AM
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h>
// Configuracion del ADC
void adc_init(int channel);
int adc_read ();
void adc_change_channel(int channel);
int adc_get_channel();

#endif	/* ADC_H */

