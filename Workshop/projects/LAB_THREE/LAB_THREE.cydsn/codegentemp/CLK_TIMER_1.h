/*******************************************************************************
* File Name: CLK_TIMER_1.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CLK_TIMER_1_H)
#define CY_CLOCK_CLK_TIMER_1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void CLK_TIMER_1_StartEx(uint32 alignClkDiv);
#define CLK_TIMER_1_Start() \
    CLK_TIMER_1_StartEx(CLK_TIMER_1__PA_DIV_ID)

#else

void CLK_TIMER_1_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void CLK_TIMER_1_Stop(void);

void CLK_TIMER_1_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CLK_TIMER_1_GetDividerRegister(void);
uint8  CLK_TIMER_1_GetFractionalDividerRegister(void);

#define CLK_TIMER_1_Enable()                         CLK_TIMER_1_Start()
#define CLK_TIMER_1_Disable()                        CLK_TIMER_1_Stop()
#define CLK_TIMER_1_SetDividerRegister(clkDivider, reset)  \
    CLK_TIMER_1_SetFractionalDividerRegister((clkDivider), 0u)
#define CLK_TIMER_1_SetDivider(clkDivider)           CLK_TIMER_1_SetDividerRegister((clkDivider), 1u)
#define CLK_TIMER_1_SetDividerValue(clkDivider)      CLK_TIMER_1_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define CLK_TIMER_1_DIV_ID     CLK_TIMER_1__DIV_ID

#define CLK_TIMER_1_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define CLK_TIMER_1_CTRL_REG   (*(reg32 *)CLK_TIMER_1__CTRL_REGISTER)
#define CLK_TIMER_1_DIV_REG    (*(reg32 *)CLK_TIMER_1__DIV_REGISTER)

#define CLK_TIMER_1_CMD_DIV_SHIFT          (0u)
#define CLK_TIMER_1_CMD_PA_DIV_SHIFT       (8u)
#define CLK_TIMER_1_CMD_DISABLE_SHIFT      (30u)
#define CLK_TIMER_1_CMD_ENABLE_SHIFT       (31u)

#define CLK_TIMER_1_CMD_DISABLE_MASK       ((uint32)((uint32)1u << CLK_TIMER_1_CMD_DISABLE_SHIFT))
#define CLK_TIMER_1_CMD_ENABLE_MASK        ((uint32)((uint32)1u << CLK_TIMER_1_CMD_ENABLE_SHIFT))

#define CLK_TIMER_1_DIV_FRAC_MASK  (0x000000F8u)
#define CLK_TIMER_1_DIV_FRAC_SHIFT (3u)
#define CLK_TIMER_1_DIV_INT_MASK   (0xFFFFFF00u)
#define CLK_TIMER_1_DIV_INT_SHIFT  (8u)

#else 

#define CLK_TIMER_1_DIV_REG        (*(reg32 *)CLK_TIMER_1__REGISTER)
#define CLK_TIMER_1_ENABLE_REG     CLK_TIMER_1_DIV_REG
#define CLK_TIMER_1_DIV_FRAC_MASK  CLK_TIMER_1__FRAC_MASK
#define CLK_TIMER_1_DIV_FRAC_SHIFT (16u)
#define CLK_TIMER_1_DIV_INT_MASK   CLK_TIMER_1__DIVIDER_MASK
#define CLK_TIMER_1_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_CLK_TIMER_1_H) */

/* [] END OF FILE */
