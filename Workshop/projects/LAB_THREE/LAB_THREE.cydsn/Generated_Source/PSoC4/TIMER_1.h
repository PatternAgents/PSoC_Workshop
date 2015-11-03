/*******************************************************************************
* File Name: TIMER_1.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the TIMER_1
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_TIMER_1_H)
#define CY_TCPWM_TIMER_1_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} TIMER_1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  TIMER_1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define TIMER_1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define TIMER_1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define TIMER_1_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define TIMER_1_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define TIMER_1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define TIMER_1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define TIMER_1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define TIMER_1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define TIMER_1_QUAD_INDEX_SIGNAL_PRESENT      (1lu)
#define TIMER_1_QUAD_STOP_SIGNAL_PRESENT       (1lu)

/* Interrupt Mask */
#define TIMER_1_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define TIMER_1_TC_RUN_MODE                    (1lu)
#define TIMER_1_TC_COUNTER_MODE                (1lu)
#define TIMER_1_TC_COMP_CAP_MODE               (2lu)
#define TIMER_1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define TIMER_1_TC_RELOAD_SIGNAL_MODE          (1lu)
#define TIMER_1_TC_COUNT_SIGNAL_MODE           (3lu)
#define TIMER_1_TC_START_SIGNAL_MODE           (1lu)
#define TIMER_1_TC_STOP_SIGNAL_MODE            (0lu)
#define TIMER_1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define TIMER_1_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define TIMER_1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define TIMER_1_TC_START_SIGNAL_PRESENT        (1lu)
#define TIMER_1_TC_STOP_SIGNAL_PRESENT         (1lu)
#define TIMER_1_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TIMER_1_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define TIMER_1_PWM_KILL_EVENT                 (0lu)
#define TIMER_1_PWM_STOP_EVENT                 (0lu)
#define TIMER_1_PWM_MODE                       (4lu)
#define TIMER_1_PWM_OUT_N_INVERT               (1lu)
#define TIMER_1_PWM_OUT_INVERT                 (0lu)
#define TIMER_1_PWM_ALIGN                      (1lu)
#define TIMER_1_PWM_RUN_MODE                   (0lu)
#define TIMER_1_PWM_DEAD_TIME_CYCLE            (0lu)
#define TIMER_1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define TIMER_1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define TIMER_1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define TIMER_1_PWM_START_SIGNAL_MODE          (3lu)
#define TIMER_1_PWM_STOP_SIGNAL_MODE           (0lu)
#define TIMER_1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define TIMER_1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define TIMER_1_PWM_COUNT_SIGNAL_PRESENT       (1lu)
#define TIMER_1_PWM_START_SIGNAL_PRESENT       (1lu)
#define TIMER_1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define TIMER_1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TIMER_1_PWM_INTERRUPT_MASK             (0lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define TIMER_1_TC_PERIOD_VALUE                (24000lu)
#define TIMER_1_TC_COMPARE_VALUE               (65535lu)
#define TIMER_1_TC_COMPARE_BUF_VALUE           (65535lu)
#define TIMER_1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define TIMER_1_PWM_PERIOD_VALUE               (1500lu)
#define TIMER_1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define TIMER_1_PWM_PERIOD_SWAP                (0lu)
#define TIMER_1_PWM_COMPARE_VALUE              (750lu)
#define TIMER_1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define TIMER_1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define TIMER_1__LEFT 0
#define TIMER_1__RIGHT 1
#define TIMER_1__CENTER 2
#define TIMER_1__ASYMMETRIC 3

#define TIMER_1__X1 0
#define TIMER_1__X2 1
#define TIMER_1__X4 2

#define TIMER_1__PWM 4
#define TIMER_1__PWM_DT 5
#define TIMER_1__PWM_PR 6

#define TIMER_1__INVERSE 1
#define TIMER_1__DIRECT 0

#define TIMER_1__CAPTURE 2
#define TIMER_1__COMPARE 0

#define TIMER_1__TRIG_LEVEL 3
#define TIMER_1__TRIG_RISING 0
#define TIMER_1__TRIG_FALLING 1
#define TIMER_1__TRIG_BOTH 2

#define TIMER_1__INTR_MASK_TC 1
#define TIMER_1__INTR_MASK_CC_MATCH 2
#define TIMER_1__INTR_MASK_NONE 0
#define TIMER_1__INTR_MASK_TC_CC 3

#define TIMER_1__UNCONFIG 8
#define TIMER_1__TIMER 1
#define TIMER_1__QUAD 3
#define TIMER_1__PWM_SEL 7

#define TIMER_1__COUNT_UP 0
#define TIMER_1__COUNT_DOWN 1
#define TIMER_1__COUNT_UPDOWN0 2
#define TIMER_1__COUNT_UPDOWN1 3


/* Prescaler */
#define TIMER_1_PRESCALE_DIVBY1                ((uint32)(0u << TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_PRESCALE_DIVBY2                ((uint32)(1u << TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_PRESCALE_DIVBY4                ((uint32)(2u << TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_PRESCALE_DIVBY8                ((uint32)(3u << TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_PRESCALE_DIVBY16               ((uint32)(4u << TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_PRESCALE_DIVBY32               ((uint32)(5u << TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_PRESCALE_DIVBY64               ((uint32)(6u << TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_PRESCALE_DIVBY128              ((uint32)(7u << TIMER_1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define TIMER_1_MODE_TIMER_COMPARE             ((uint32)(TIMER_1__COMPARE         <<  \
                                                                  TIMER_1_MODE_SHIFT))
#define TIMER_1_MODE_TIMER_CAPTURE             ((uint32)(TIMER_1__CAPTURE         <<  \
                                                                  TIMER_1_MODE_SHIFT))
#define TIMER_1_MODE_QUAD                      ((uint32)(TIMER_1__QUAD            <<  \
                                                                  TIMER_1_MODE_SHIFT))
#define TIMER_1_MODE_PWM                       ((uint32)(TIMER_1__PWM             <<  \
                                                                  TIMER_1_MODE_SHIFT))
#define TIMER_1_MODE_PWM_DT                    ((uint32)(TIMER_1__PWM_DT          <<  \
                                                                  TIMER_1_MODE_SHIFT))
#define TIMER_1_MODE_PWM_PR                    ((uint32)(TIMER_1__PWM_PR          <<  \
                                                                  TIMER_1_MODE_SHIFT))

/* Quad Modes */
#define TIMER_1_MODE_X1                        ((uint32)(TIMER_1__X1              <<  \
                                                                  TIMER_1_QUAD_MODE_SHIFT))
#define TIMER_1_MODE_X2                        ((uint32)(TIMER_1__X2              <<  \
                                                                  TIMER_1_QUAD_MODE_SHIFT))
#define TIMER_1_MODE_X4                        ((uint32)(TIMER_1__X4              <<  \
                                                                  TIMER_1_QUAD_MODE_SHIFT))

/* Counter modes */
#define TIMER_1_COUNT_UP                       ((uint32)(TIMER_1__COUNT_UP        <<  \
                                                                  TIMER_1_UPDOWN_SHIFT))
#define TIMER_1_COUNT_DOWN                     ((uint32)(TIMER_1__COUNT_DOWN      <<  \
                                                                  TIMER_1_UPDOWN_SHIFT))
#define TIMER_1_COUNT_UPDOWN0                  ((uint32)(TIMER_1__COUNT_UPDOWN0   <<  \
                                                                  TIMER_1_UPDOWN_SHIFT))
#define TIMER_1_COUNT_UPDOWN1                  ((uint32)(TIMER_1__COUNT_UPDOWN1   <<  \
                                                                  TIMER_1_UPDOWN_SHIFT))

/* PWM output invert */
#define TIMER_1_INVERT_LINE                    ((uint32)(TIMER_1__INVERSE         <<  \
                                                                  TIMER_1_INV_OUT_SHIFT))
#define TIMER_1_INVERT_LINE_N                  ((uint32)(TIMER_1__INVERSE         <<  \
                                                                  TIMER_1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define TIMER_1_TRIG_RISING                    ((uint32)TIMER_1__TRIG_RISING)
#define TIMER_1_TRIG_FALLING                   ((uint32)TIMER_1__TRIG_FALLING)
#define TIMER_1_TRIG_BOTH                      ((uint32)TIMER_1__TRIG_BOTH)
#define TIMER_1_TRIG_LEVEL                     ((uint32)TIMER_1__TRIG_LEVEL)

/* Interrupt mask */
#define TIMER_1_INTR_MASK_TC                   ((uint32)TIMER_1__INTR_MASK_TC)
#define TIMER_1_INTR_MASK_CC_MATCH             ((uint32)TIMER_1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define TIMER_1_CC_MATCH_SET                   (0x00u)
#define TIMER_1_CC_MATCH_CLEAR                 (0x01u)
#define TIMER_1_CC_MATCH_INVERT                (0x02u)
#define TIMER_1_CC_MATCH_NO_CHANGE             (0x03u)
#define TIMER_1_OVERLOW_SET                    (0x00u)
#define TIMER_1_OVERLOW_CLEAR                  (0x04u)
#define TIMER_1_OVERLOW_INVERT                 (0x08u)
#define TIMER_1_OVERLOW_NO_CHANGE              (0x0Cu)
#define TIMER_1_UNDERFLOW_SET                  (0x00u)
#define TIMER_1_UNDERFLOW_CLEAR                (0x10u)
#define TIMER_1_UNDERFLOW_INVERT               (0x20u)
#define TIMER_1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define TIMER_1_PWM_MODE_LEFT                  (TIMER_1_CC_MATCH_CLEAR        |   \
                                                         TIMER_1_OVERLOW_SET           |   \
                                                         TIMER_1_UNDERFLOW_NO_CHANGE)
#define TIMER_1_PWM_MODE_RIGHT                 (TIMER_1_CC_MATCH_SET          |   \
                                                         TIMER_1_OVERLOW_NO_CHANGE     |   \
                                                         TIMER_1_UNDERFLOW_CLEAR)
#define TIMER_1_PWM_MODE_ASYM                  (TIMER_1_CC_MATCH_INVERT       |   \
                                                         TIMER_1_OVERLOW_SET           |   \
                                                         TIMER_1_UNDERFLOW_CLEAR)

#if (TIMER_1_CY_TCPWM_V2)
    #if(TIMER_1_CY_TCPWM_4000)
        #define TIMER_1_PWM_MODE_CENTER                (TIMER_1_CC_MATCH_INVERT       |   \
                                                                 TIMER_1_OVERLOW_NO_CHANGE     |   \
                                                                 TIMER_1_UNDERFLOW_CLEAR)
    #else
        #define TIMER_1_PWM_MODE_CENTER                (TIMER_1_CC_MATCH_INVERT       |   \
                                                                 TIMER_1_OVERLOW_SET           |   \
                                                                 TIMER_1_UNDERFLOW_CLEAR)
    #endif /* (TIMER_1_CY_TCPWM_4000) */
#else
    #define TIMER_1_PWM_MODE_CENTER                (TIMER_1_CC_MATCH_INVERT       |   \
                                                             TIMER_1_OVERLOW_NO_CHANGE     |   \
                                                             TIMER_1_UNDERFLOW_CLEAR)
#endif /* (TIMER_1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define TIMER_1_CMD_CAPTURE                    (0u)
#define TIMER_1_CMD_RELOAD                     (8u)
#define TIMER_1_CMD_STOP                       (16u)
#define TIMER_1_CMD_START                      (24u)

/* Status */
#define TIMER_1_STATUS_DOWN                    (1u)
#define TIMER_1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   TIMER_1_Init(void);
void   TIMER_1_Enable(void);
void   TIMER_1_Start(void);
void   TIMER_1_Stop(void);

void   TIMER_1_SetMode(uint32 mode);
void   TIMER_1_SetCounterMode(uint32 counterMode);
void   TIMER_1_SetPWMMode(uint32 modeMask);
void   TIMER_1_SetQDMode(uint32 qdMode);

void   TIMER_1_SetPrescaler(uint32 prescaler);
void   TIMER_1_TriggerCommand(uint32 mask, uint32 command);
void   TIMER_1_SetOneShot(uint32 oneShotEnable);
uint32 TIMER_1_ReadStatus(void);

void   TIMER_1_SetPWMSyncKill(uint32 syncKillEnable);
void   TIMER_1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   TIMER_1_SetPWMDeadTime(uint32 deadTime);
void   TIMER_1_SetPWMInvert(uint32 mask);

void   TIMER_1_SetInterruptMode(uint32 interruptMask);
uint32 TIMER_1_GetInterruptSourceMasked(void);
uint32 TIMER_1_GetInterruptSource(void);
void   TIMER_1_ClearInterrupt(uint32 interruptMask);
void   TIMER_1_SetInterrupt(uint32 interruptMask);

void   TIMER_1_WriteCounter(uint32 count);
uint32 TIMER_1_ReadCounter(void);

uint32 TIMER_1_ReadCapture(void);
uint32 TIMER_1_ReadCaptureBuf(void);

void   TIMER_1_WritePeriod(uint32 period);
uint32 TIMER_1_ReadPeriod(void);
void   TIMER_1_WritePeriodBuf(uint32 periodBuf);
uint32 TIMER_1_ReadPeriodBuf(void);

void   TIMER_1_WriteCompare(uint32 compare);
uint32 TIMER_1_ReadCompare(void);
void   TIMER_1_WriteCompareBuf(uint32 compareBuf);
uint32 TIMER_1_ReadCompareBuf(void);

void   TIMER_1_SetPeriodSwap(uint32 swapEnable);
void   TIMER_1_SetCompareSwap(uint32 swapEnable);

void   TIMER_1_SetCaptureMode(uint32 triggerMode);
void   TIMER_1_SetReloadMode(uint32 triggerMode);
void   TIMER_1_SetStartMode(uint32 triggerMode);
void   TIMER_1_SetStopMode(uint32 triggerMode);
void   TIMER_1_SetCountMode(uint32 triggerMode);

void   TIMER_1_SaveConfig(void);
void   TIMER_1_RestoreConfig(void);
void   TIMER_1_Sleep(void);
void   TIMER_1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define TIMER_1_BLOCK_CONTROL_REG              (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TIMER_1_BLOCK_CONTROL_PTR              ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TIMER_1_COMMAND_REG                    (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TIMER_1_COMMAND_PTR                    ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TIMER_1_INTRRUPT_CAUSE_REG             (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TIMER_1_INTRRUPT_CAUSE_PTR             ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TIMER_1_CONTROL_REG                    (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__CTRL )
#define TIMER_1_CONTROL_PTR                    ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__CTRL )
#define TIMER_1_STATUS_REG                     (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__STATUS )
#define TIMER_1_STATUS_PTR                     ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__STATUS )
#define TIMER_1_COUNTER_REG                    (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__COUNTER )
#define TIMER_1_COUNTER_PTR                    ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__COUNTER )
#define TIMER_1_COMP_CAP_REG                   (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__CC )
#define TIMER_1_COMP_CAP_PTR                   ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__CC )
#define TIMER_1_COMP_CAP_BUF_REG               (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__CC_BUFF )
#define TIMER_1_COMP_CAP_BUF_PTR               ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__CC_BUFF )
#define TIMER_1_PERIOD_REG                     (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__PERIOD )
#define TIMER_1_PERIOD_PTR                     ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__PERIOD )
#define TIMER_1_PERIOD_BUF_REG                 (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TIMER_1_PERIOD_BUF_PTR                 ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TIMER_1_TRIG_CONTROL0_REG              (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TIMER_1_TRIG_CONTROL0_PTR              ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TIMER_1_TRIG_CONTROL1_REG              (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TIMER_1_TRIG_CONTROL1_PTR              ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TIMER_1_TRIG_CONTROL2_REG              (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TIMER_1_TRIG_CONTROL2_PTR              ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TIMER_1_INTERRUPT_REQ_REG              (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR )
#define TIMER_1_INTERRUPT_REQ_PTR              ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR )
#define TIMER_1_INTERRUPT_SET_REG              (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR_SET )
#define TIMER_1_INTERRUPT_SET_PTR              ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR_SET )
#define TIMER_1_INTERRUPT_MASK_REG             (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR_MASK )
#define TIMER_1_INTERRUPT_MASK_PTR             ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR_MASK )
#define TIMER_1_INTERRUPT_MASKED_REG           (*(reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define TIMER_1_INTERRUPT_MASKED_PTR           ( (reg32 *) TIMER_1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define TIMER_1_MASK                           ((uint32)TIMER_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define TIMER_1_RELOAD_CC_SHIFT                (0u)
#define TIMER_1_RELOAD_PERIOD_SHIFT            (1u)
#define TIMER_1_PWM_SYNC_KILL_SHIFT            (2u)
#define TIMER_1_PWM_STOP_KILL_SHIFT            (3u)
#define TIMER_1_PRESCALER_SHIFT                (8u)
#define TIMER_1_UPDOWN_SHIFT                   (16u)
#define TIMER_1_ONESHOT_SHIFT                  (18u)
#define TIMER_1_QUAD_MODE_SHIFT                (20u)
#define TIMER_1_INV_OUT_SHIFT                  (20u)
#define TIMER_1_INV_COMPL_OUT_SHIFT            (21u)
#define TIMER_1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define TIMER_1_RELOAD_CC_MASK                 ((uint32)(TIMER_1_1BIT_MASK        <<  \
                                                                            TIMER_1_RELOAD_CC_SHIFT))
#define TIMER_1_RELOAD_PERIOD_MASK             ((uint32)(TIMER_1_1BIT_MASK        <<  \
                                                                            TIMER_1_RELOAD_PERIOD_SHIFT))
#define TIMER_1_PWM_SYNC_KILL_MASK             ((uint32)(TIMER_1_1BIT_MASK        <<  \
                                                                            TIMER_1_PWM_SYNC_KILL_SHIFT))
#define TIMER_1_PWM_STOP_KILL_MASK             ((uint32)(TIMER_1_1BIT_MASK        <<  \
                                                                            TIMER_1_PWM_STOP_KILL_SHIFT))
#define TIMER_1_PRESCALER_MASK                 ((uint32)(TIMER_1_8BIT_MASK        <<  \
                                                                            TIMER_1_PRESCALER_SHIFT))
#define TIMER_1_UPDOWN_MASK                    ((uint32)(TIMER_1_2BIT_MASK        <<  \
                                                                            TIMER_1_UPDOWN_SHIFT))
#define TIMER_1_ONESHOT_MASK                   ((uint32)(TIMER_1_1BIT_MASK        <<  \
                                                                            TIMER_1_ONESHOT_SHIFT))
#define TIMER_1_QUAD_MODE_MASK                 ((uint32)(TIMER_1_3BIT_MASK        <<  \
                                                                            TIMER_1_QUAD_MODE_SHIFT))
#define TIMER_1_INV_OUT_MASK                   ((uint32)(TIMER_1_2BIT_MASK        <<  \
                                                                            TIMER_1_INV_OUT_SHIFT))
#define TIMER_1_MODE_MASK                      ((uint32)(TIMER_1_3BIT_MASK        <<  \
                                                                            TIMER_1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define TIMER_1_CAPTURE_SHIFT                  (0u)
#define TIMER_1_COUNT_SHIFT                    (2u)
#define TIMER_1_RELOAD_SHIFT                   (4u)
#define TIMER_1_STOP_SHIFT                     (6u)
#define TIMER_1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define TIMER_1_CAPTURE_MASK                   ((uint32)(TIMER_1_2BIT_MASK        <<  \
                                                                  TIMER_1_CAPTURE_SHIFT))
#define TIMER_1_COUNT_MASK                     ((uint32)(TIMER_1_2BIT_MASK        <<  \
                                                                  TIMER_1_COUNT_SHIFT))
#define TIMER_1_RELOAD_MASK                    ((uint32)(TIMER_1_2BIT_MASK        <<  \
                                                                  TIMER_1_RELOAD_SHIFT))
#define TIMER_1_STOP_MASK                      ((uint32)(TIMER_1_2BIT_MASK        <<  \
                                                                  TIMER_1_STOP_SHIFT))
#define TIMER_1_START_MASK                     ((uint32)(TIMER_1_2BIT_MASK        <<  \
                                                                  TIMER_1_START_SHIFT))

/* MASK */
#define TIMER_1_1BIT_MASK                      ((uint32)0x01u)
#define TIMER_1_2BIT_MASK                      ((uint32)0x03u)
#define TIMER_1_3BIT_MASK                      ((uint32)0x07u)
#define TIMER_1_6BIT_MASK                      ((uint32)0x3Fu)
#define TIMER_1_8BIT_MASK                      ((uint32)0xFFu)
#define TIMER_1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define TIMER_1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define TIMER_1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(TIMER_1_QUAD_ENCODING_MODES     << TIMER_1_QUAD_MODE_SHIFT))       |\
         ((uint32)(TIMER_1_CONFIG                  << TIMER_1_MODE_SHIFT)))

#define TIMER_1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(TIMER_1_PWM_STOP_EVENT          << TIMER_1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(TIMER_1_PWM_OUT_INVERT          << TIMER_1_INV_OUT_SHIFT))         |\
         ((uint32)(TIMER_1_PWM_OUT_N_INVERT        << TIMER_1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(TIMER_1_PWM_MODE                << TIMER_1_MODE_SHIFT)))

#define TIMER_1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(TIMER_1_PWM_RUN_MODE         << TIMER_1_ONESHOT_SHIFT))
            
#define TIMER_1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(TIMER_1_PWM_ALIGN            << TIMER_1_UPDOWN_SHIFT))

#define TIMER_1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(TIMER_1_PWM_KILL_EVENT      << TIMER_1_PWM_SYNC_KILL_SHIFT))

#define TIMER_1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(TIMER_1_PWM_DEAD_TIME_CYCLE  << TIMER_1_PRESCALER_SHIFT))

#define TIMER_1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(TIMER_1_PWM_PRESCALER        << TIMER_1_PRESCALER_SHIFT))

#define TIMER_1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(TIMER_1_TC_PRESCALER            << TIMER_1_PRESCALER_SHIFT))       |\
         ((uint32)(TIMER_1_TC_COUNTER_MODE         << TIMER_1_UPDOWN_SHIFT))          |\
         ((uint32)(TIMER_1_TC_RUN_MODE             << TIMER_1_ONESHOT_SHIFT))         |\
         ((uint32)(TIMER_1_TC_COMP_CAP_MODE        << TIMER_1_MODE_SHIFT)))
        
#define TIMER_1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(TIMER_1_QUAD_PHIA_SIGNAL_MODE   << TIMER_1_COUNT_SHIFT))           |\
         ((uint32)(TIMER_1_QUAD_INDEX_SIGNAL_MODE  << TIMER_1_RELOAD_SHIFT))          |\
         ((uint32)(TIMER_1_QUAD_STOP_SIGNAL_MODE   << TIMER_1_STOP_SHIFT))            |\
         ((uint32)(TIMER_1_QUAD_PHIB_SIGNAL_MODE   << TIMER_1_START_SHIFT)))

#define TIMER_1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(TIMER_1_PWM_SWITCH_SIGNAL_MODE  << TIMER_1_CAPTURE_SHIFT))         |\
         ((uint32)(TIMER_1_PWM_COUNT_SIGNAL_MODE   << TIMER_1_COUNT_SHIFT))           |\
         ((uint32)(TIMER_1_PWM_RELOAD_SIGNAL_MODE  << TIMER_1_RELOAD_SHIFT))          |\
         ((uint32)(TIMER_1_PWM_STOP_SIGNAL_MODE    << TIMER_1_STOP_SHIFT))            |\
         ((uint32)(TIMER_1_PWM_START_SIGNAL_MODE   << TIMER_1_START_SHIFT)))

#define TIMER_1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(TIMER_1_TC_CAPTURE_SIGNAL_MODE  << TIMER_1_CAPTURE_SHIFT))         |\
         ((uint32)(TIMER_1_TC_COUNT_SIGNAL_MODE    << TIMER_1_COUNT_SHIFT))           |\
         ((uint32)(TIMER_1_TC_RELOAD_SIGNAL_MODE   << TIMER_1_RELOAD_SHIFT))          |\
         ((uint32)(TIMER_1_TC_STOP_SIGNAL_MODE     << TIMER_1_STOP_SHIFT))            |\
         ((uint32)(TIMER_1_TC_START_SIGNAL_MODE    << TIMER_1_START_SHIFT)))
        
#define TIMER_1_TIMER_UPDOWN_CNT_USED                                                          \
                ((TIMER_1__COUNT_UPDOWN0 == TIMER_1_TC_COUNTER_MODE)                  ||\
                 (TIMER_1__COUNT_UPDOWN1 == TIMER_1_TC_COUNTER_MODE))

#define TIMER_1_PWM_UPDOWN_CNT_USED                                                            \
                ((TIMER_1__CENTER == TIMER_1_PWM_ALIGN)                               ||\
                 (TIMER_1__ASYMMETRIC == TIMER_1_PWM_ALIGN))               
        
#define TIMER_1_PWM_PR_INIT_VALUE              (1u)
#define TIMER_1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_TIMER_1_H */

/* [] END OF FILE */
