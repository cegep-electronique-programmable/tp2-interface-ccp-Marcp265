/**
 * Fait par : Marc Pilon
 * Date : 10/02/2025
 * Description : trouver la valeur a partir d'un capture d'un hall effect sensor
 */



#include "mcc_generated_files/mcc.h"
#include "ecran.h"

void Capture_CallBack(uint16_t capturedValue);

static uint16_t capture;

/*
                         Main application
 */
void main(void)
{
    float periode = 0;
    
    // Initialize the device
    SYSTEM_Initialize();
    
    

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    // set the custom callback
    CCP2_SetCallBack(Capture_CallBack);
    
    //Setup ecran
    ecranAllume();
    videEcran();
    curseurPosition(0x00);
    backlightAllume(8);

    printf("Periode:");
    while (1)
    {
        __delay_ms(500);
        curseurPosition(0x08);
        periode = capture /5;   //car valeur ÷ 5MHz(fosc/4)
        printf("%0.2fus\n\r", periode);
        
    }
}

void Capture_CallBack(uint16_t capturedValue)
    {
    //mettre la valeur capturé dans une variable et restart le timer
        capture = capturedValue;
        TMR1_Reload();
        
    }
/**
 End of File
*/