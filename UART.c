#include "UART.h"

void UART_RX_config (uint16_t baudrate)
{
    TXSTAbits.BRGH = 0;     // Baja velocidad
    BAUDCTLbits.BRG16 = 0;  // 8 bits
    
    // Configuracion dependiendo del baudrate deseado
    if (baudrate == 1200)
    {
        SPBRG = 103;
        SPBRGH = 0;
    }
    
    else if (baudrate == 2400)
    {
        SPBRG = 51;
        SPBRGH = 0;
    }
    else if (baudrate == 9600)
    {
        SPBRG = 12;
        SPBRGH = 0;
    }
    
    RCSTAbits.SPEN = 1; // Habilitar el RX y TX
    TXSTAbits.SYNC = 0; // Activar el modo asincrono
    
    // Habilitar las interrupciones
    PIE1bits.RCIE = 1;
    PIR1bits.RCIF = 1;
    
    RCSTAbits.RX9 = 0; // Recepcion de 8bits
    RCSTAbits.CREN = 1; // Habilitar el receptor
    
    return;
        
}
void UART_TX_config (uint16_t baudrate)
{
    TXSTAbits.BRGH = 0; 
    BAUDCTLbits.BRG16 = 0;
    
    if (baudrate == 1200)
    {
        SPBRG = 103;
        SPBRGH = 0;
    }
    
    else if (baudrate == 2400)
    {
        SPBRG = 51;
        SPBRGH = 0;
    }
    else if (baudrate == 9600)
    {
        SPBRG = 12;
        SPBRGH = 0;
    }
    
    RCSTAbits.SPEN = 1; // Habilitar el RX y TX
    TXSTAbits.SYNC = 0; // Modo asincrono
    TXSTAbits.TXEN = 1; // Habilitar la transmision
    PIR1bits.TXIF = 0;
    return;
    
}
void UART_write_char(char *c)
{
    while (*c != '\0') {
        while (!TXSTAbits.TRMT); // Esperamos a que el registro de transmisión esté vacío
        TXREG = *c; // Enviamos el caracter
        c++; // Movemos el puntero al siguiente carácter
    }
}
char UART_read_char ()
{
    char recibido = RCREG;
    return recibido;
}
