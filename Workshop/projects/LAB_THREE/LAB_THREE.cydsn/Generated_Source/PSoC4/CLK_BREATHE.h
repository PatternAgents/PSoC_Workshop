/*******************************************************************************
* File Name: CLK_BREATHE.h
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

#if !defined(CY_CLOCK_CLK_BREATHE_H)
#define CY_CLOCK_CLK_BREATHE_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void CLK_BREATHE_StartEx(uint32 alignClkDiv);
#define CLK_BREATHE_Start() \
    CLK_BREATHE_StartEx(CLK_BREATHE__PA_DIV_ID)

#else

void CLK_BREATHE_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void CLK_BREATHE_Stop(void);

void CLK_BREATHE_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CLK_BREATHE_GetDividerRegister(void);
uint8  CLK_BREATHE_GetFractionalDividerRegister(void);

#define CLK_BREATHE_Enable()                         CLK_BREATHE_Start()
#define CLK_BREATHE_Disable()                        CLK_BREATHE_Stop()
#define CLK_BREATHE_SetDividerRegister(clkDivider, reset)  \
    CLK_BREATHE_SetFractionalDividerRegister((clkDivider), 0u)
#define CLK_BREATHE_SetDivider(clkDivider)           CLK_BREATHE_SetDividerRegister((clkDivider), 1u)
#define CLK_BREATHE_SetDividerValue(clkDivider)      CLK_BREATHE_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define CLK_BREATHE_DIV_ID     CLK_BREATHE__DIV_ID

#define CLK_BREATHE_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define CLK_BREATHE_CTRL_REG   (*(reg32 *)CLK_BREATHE__CTRL_REGISTER)
#define CLK_BREATHE_DIV_REG    (*(reg32 *)CLK_BREATHE__DIV_REGISTER)

#define CLK_BREATHE_CMD_DIV_SHIFT          (0u)
#define CLK_BREATHE_CMD_PA_DIV_SHIFT       (8u)
#define CLK_BREATHE_CMD_DISABLE_SHIFT      (30u)
#define CLK_BREATHE_CMD_ENABLE_SHIFT       (31u)

#define CLK_BREATHE_CMD_DISABLE_MASK       ((uint32)((uint32)1u << CLK_BREATHE_CMD_DISABLE_SHIFT))
#define CLK_BREATHE_CMD_ENABLE_MASK        ((uint32)((uint32)1u << CLK_BREATHE_CMD_ENABLE_SHIFT))

#define CLK_BREATHE_DIV_FRAC_MASK  (0x000000F8u)
#define CLK_BREATHE_DIV_FRAC_SHIFT (3u)
#define CLK_BREATHE_DIV_INT_MASK   (0xFFFFFF00u)
#define CLK_BREATHE_DIV_INT_SHIFT  (8u)

#else 

#define CLK_BREATHE_DIV_REG        (*(reg32 *)CLK_BREATHE__REGISTER)
#define CLK_BREATHE_ENABLE_REG     CLK_BREATHE_DIV_REG
#define CLK_BREATHE_DIV_FRAC_MASK  CLK_BREATHE__FRAC_MASK
#define CLK_BREATHE_DIV_FRAC_SHIFT (16u)
#define CLK_BREATHE_DIV_INT_MASK   CLK_BREATHE__DIVIDER_MASK
#define CLK_BREATHE_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_CLK_BREATHE_H) */

/* [] END OF FILE */
