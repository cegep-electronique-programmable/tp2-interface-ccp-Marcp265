/**
 * Fait par : Marc Pilon
 * Date : 03/02/2025
 * Description : faire tourner un servo moteur avec le PWM
 */



#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("Lock(L) or Unlock(U)?");
    PWM2_LoadDutyValue(46);

    while (1)
    {
        switch(EUSART1_Read())
        {
            case 'L':
            printf("\n\rLock");
            PWM2_LoadDutyValue(22);
            break;
            
            case 'U':
            printf("\n\rUnlock");
            PWM2_LoadDutyValue(71);
            break;
            
            default:
            printf("\n\rReset\n\rPesez L ou U");
            PWM2_LoadDutyValue(46);
        }
    }
}
/**
 End of File
*/