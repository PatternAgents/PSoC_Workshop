/*******************************************************************************
* File Name: ResetISR.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <ResetISR.h>

#if !defined(ResetISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ResetISR_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ResetISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_Start(void)
{
    /* For all we know the interrupt is active. */
    ResetISR_Disable();

    /* Set the ISR to point to the ResetISR Interrupt. */
    ResetISR_SetVector(&ResetISR_Interrupt);

    /* Set the priority. */
    ResetISR_SetPriority((uint8)ResetISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ResetISR_Enable();
}


/*******************************************************************************
* Function Name: ResetISR_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ResetISR_Disable();

    /* Set the ISR to point to the ResetISR Interrupt. */
    ResetISR_SetVector(address);

    /* Set the priority. */
    ResetISR_SetPriority((uint8)ResetISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ResetISR_Enable();
}


/*******************************************************************************
* Function Name: ResetISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_Stop(void)
{
    /* Disable this interrupt. */
    ResetISR_Disable();

    /* Set the ISR to point to the passive one. */
    ResetISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ResetISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ResetISR.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(ResetISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ResetISR_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: ResetISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ResetISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ResetISR_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ResetISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ResetISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress ResetISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ResetISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ResetISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ResetISR_Start
*   or ResetISR_StartEx will override any effect this method would 
*   have had. This method should only be called after ResetISR_Start or 
*   ResetISR_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ResetISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ResetISR_INTC_PRIOR = (*ResetISR_INTC_PRIOR & (uint32)(~ResetISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ResetISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 ResetISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ResetISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ResetISR_INTC_PRIOR & ResetISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ResetISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_Enable(void)
{
    /* Enable the general interrupt. */
    *ResetISR_INTC_SET_EN = ResetISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ResetISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 ResetISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ResetISR_INTC_SET_EN & (uint32)ResetISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ResetISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_Disable(void)
{
    /* Disable the general interrupt. */
    *ResetISR_INTC_CLR_EN = ResetISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ResetISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_SetPending(void)
{
    *ResetISR_INTC_SET_PD = ResetISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ResetISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ResetISR_ClearPending(void)
{
    *ResetISR_INTC_CLR_PD = ResetISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
