/*-------------------------------------------------------------*/
/* PatternAgents & PDXElectroHax                               */
/* Intro to Programmable Logic                                 */
/* Lab Three - ADC, PWM, UART Example                          */
/*-------------------------------------------------------------*/

#include <project.h>
#include <stdio.h>
#include <ADC_1.h>

#define CH0_N               (0x00u)
#define TEMP_CH             (0x01u)
#define DELAY_1SEC          (1000u)

/* Get actual Vref. value from ADC SAR sequencer */
#define ADC_VREF_VALUE_V    ((float)ADC_1_DEFAULT_VREF_MV_VALUE/1000.0)

volatile uint32 dataReady = 0u;
volatile int16 result[ADC_1_TOTAL_CHANNELS_NUM];
volatile uint32 timer_delay = 0u;


/* Prototype the TIMER_1 Interrupt Handler */
CY_ISR_PROTO( TIMER_1_IRQ_Handler );

/* TIMER_1 Interrupt Handler */
CY_ISR( TIMER_1_IRQ_Handler )
{
    Bootloadable_Load(); /* Start the bootloader running now */       
}

/* Prototype the PWM_1 Interrupt Handler */
CY_ISR_PROTO( PWM_1_IRQ_Handler );

/* PWM_1 Interrupt Handler */
CY_ISR( PWM_1_IRQ_Handler )
{
    timer_delay++;
    
    /* Measures temperature once per second */
    if(timer_delay > DELAY_1SEC)
    {
        /* Enables injection channel for next scan */
        ADC_1_EnableInjection();
        timer_delay = 0u;
    }    
    
    /* Clears interrupt request from terminal count */
    PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
}

/* Prototype the ADC_1 Interrupt Handler */
CY_ISR_PROTO( ADC_1_IRQ_Handler );

/* ADC_1 Interrupt Handler */
CY_ISR( ADC_1_IRQ_Handler )
{
    uint32 intr_status;
    uint32 range_status;

    /* Read interrupt status registers */
    intr_status = ADC_1_SAR_INTR_MASKED_REG;
    /* Check for End of Scan interrupt */
    if((intr_status & ADC_1_EOS_MASK) != 0u)
    {
        /* Read range detect status */
        range_status = ADC_1_SAR_RANGE_INTR_MASKED_REG;
        /* Verify that the conversion result met the condition Low_Limit <= Result < High_Limit  */
        if((range_status & (uint32)(1ul << CH0_N)) != 0u) 
        {
            /* Read conversion result */
            result[CH0_N] = ADC_1_GetResult16(CH0_N);
            /* Set PWM compare from channel0 */
            PWM_1_WriteCompare(result[CH0_N]);
        }    

        /* Clear range detect status */
        ADC_1_SAR_RANGE_INTR_REG = range_status;
        dataReady |= ADC_1_EOS_MASK;
    }    

    /* Check for Injection End of Conversion */
    if((intr_status & ADC_1_INJ_EOC_MASK) != 0u)
    {
        result[TEMP_CH] = ADC_1_GetResult16(TEMP_CH);
        dataReady |= ADC_1_INJ_EOC_MASK;
    }    

    /* Clear handled interrupt */
    ADC_1_SAR_INTR_REG = intr_status;    
}

int main()
{
    int16 res = 0;
    int32 temperature;
    char  uartLine[250];
    int16 ADCCountsCorrected;

    /* Start TIMER_1 - it only counts when SW1 is pressed */
    TIMER_1_Start();
    /* Clear any pending Interrupts for TIMER_1 */
    TIMER_1_IRQ_ClearPending();
    /* Install the Interrupt Service Handler Routine for TIMER_1 */
    TIMER_1_IRQ_StartEx( TIMER_1_IRQ_Handler );

    /* Initialize the UART */
    UART_1_Start();
    UART_1_UartPutString("\r\n Starting temperature measurement... \r\n");

    /* Start the PWM */
    PWM_1_Start();
    PWM_1_TriggerCommand(PWM_1_MASK, PWM_1_CMD_START);
    /* Clear any pending Interrupts for PWM_1 */
    PWM_1_IRQ_ClearPending();
    /* Install the Interrupt Service Handler Routine for PWM_1 */
    PWM_1_IRQ_StartEx( PWM_1_IRQ_Handler );

    /* Init and start sequencing SAR ADC */
    ADC_1_Start();
    ADC_1_StartConvert();
    /* Enable interrupt and set interrupt handler to local routine */
    ADC_1_IRQ_StartEx(ADC_1_IRQ_Handler);
    
    /* Enable All Interrupts (Global) */
    CyGlobalIntEnable;

    /* Main (infinite) loop - Does nothing! it's all Hardware! */
    for(;;)
    {
        /* When conversion of sequencing channels has completed */
        if((dataReady & ADC_1_EOS_MASK) != 0u)
        {
            /* Get voltage, measured by ADC */
            dataReady &= ~ADC_1_EOS_MASK;
            res = ADC_1_CountsTo_mVolts(CH0_N, result[CH0_N]);
        }    
        
        /* When conversion of the injection channel has completed */
        if((dataReady & ADC_1_INJ_EOC_MASK) != 0u)
        {
            dataReady &= ~ADC_1_INJ_EOC_MASK;

            /******************************************************************************
            * Adjust data from ADC with respect to Vref value.
            * This adjustment is to be done if Vref is set to any other than
            * internal 1.024V.
            * For more detailed description see Functional Description section
            * of DieTemp P4 datasheet.
            *******************************************************************************/
            ADCCountsCorrected = result[TEMP_CH]*((int16)((float)ADC_VREF_VALUE_V/1.024));
            
            temperature = DieTemp_CountsTo_Celsius(ADCCountsCorrected);

            /* Print temperature value to UART */
            sprintf(
                    uartLine, "Temperature value: %dC \r\n",
                    (int16) temperature
                    );
            
            UART_1_UartPutString(uartLine);
            
            /* Print voltage value to UART */
            sprintf(
                uartLine, "ADC measured voltage: %dmV \r\n",
                (uint16) res
                );
            
            UART_1_UartPutString(uartLine);
        }
    }
}


/* [] END OF FILE */
