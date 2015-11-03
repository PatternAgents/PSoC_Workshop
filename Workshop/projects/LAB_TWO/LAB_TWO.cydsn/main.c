/*-------------------------------------------------------------*/
/* PatternAgents & PDXElectroHax                               */
/* Intro to Programmable Logic                                 */
/* Lab One - Reset Bootloader using TIMER_1                    */
/*-------------------------------------------------------------*/

#include <project.h>

/* Prototype the ISR handler */
CY_ISR_PROTO( TIMER_1_IRQ_Handler );

/* Implementation of the ISR handler */
CY_ISR( TIMER_1_IRQ_Handler )
{
    Bootloadable_Load(); /* Start the bootloader running now */       
}
 
int main()
{
    /* Start TIMER_1 - it only counts when SW1 is pressed */
    TIMER_1_Start();
    /* Clear any pending Interrupts for TIMER_1 */
    TIMER_1_IRQ_ClearPending();
    /* Install the Interrupt Service Handler Routine for TIMER_1 */
    TIMER_1_IRQ_StartEx( TIMER_1_IRQ_Handler );
    
    /* Start the "Breathing" PWMs */
    PWM_1_Start();
    PWM_2_Start();
    
    /* Enable All Interrupts (Global) */
    CyGlobalIntEnable;

    /* Main (infinite) loop - Does nothing! it's all Hardware! */
    for(;;)
    {
    }
}