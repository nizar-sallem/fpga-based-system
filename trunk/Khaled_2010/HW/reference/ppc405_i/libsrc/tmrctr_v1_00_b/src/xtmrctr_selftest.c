/* $Id: xtmrctr_selftest.c,v 1.7 2005/01/04 17:59:37 moleres Exp $ */
/******************************************************************************
*
*       XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"
*       AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND
*       SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,
*       OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,
*       APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION
*       THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,
*       AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE
*       FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY
*       WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE
*       IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR
*       REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF
*       INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*       FOR A PARTICULAR PURPOSE.
*
*       (c) Copyright 2002 Xilinx Inc.
*       All rights reserved.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xtmrctr_selftest.c
*
* Contains diagnostic/self-test functions for the XTmrCtr component.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.00b jhl  02/06/02 First release
* </pre>
*
******************************************************************************/

/***************************** Include Files *********************************/

#include "xbasic_types.h"
#include "xio.h"
#include "xtmrctr.h"
#include "xtmrctr_i.h"

/************************** Constant Definitions *****************************/


/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/


/************************** Function Prototypes ******************************/


/************************** Variable Definitions *****************************/


/*****************************************************************************/
/**
*
* Runs a self-test on the driver/device. This test verifies that the specified
* timer counter of the device can be enabled and increments.
*
* @param    InstancePtr is a pointer to the XTmrCtr instance to be worked on.
* @param    TmrCtrNumber is the timer counter of the device to operate on. Each
*           device may contain multiple timer counters. The timer number is a
*           zero based number with a range of 0 - (XTC_DEVICE_TIMER_COUNT - 1).
*
* @return
*
* XST_SUCCESS if self-test was successful, or XST_FAILURE if the timer is not
* incrementing.
*
* @note
*
* This is a destructive test using the provided timer. The current settings
* of the timer are returned to the initialized values and all settings at the
* time this function is called are overwritten.
*
******************************************************************************/
XStatus XTmrCtr_SelfTest(XTmrCtr *InstancePtr, Xuint8 TmrCtrNumber)
{
    Xuint32 TimerCount1 = 0;
    Xuint32 TimerCount2 = 0;
    Xuint16 Count = 0;

    XASSERT_NONVOID(InstancePtr != XNULL);
    XASSERT_NONVOID(TmrCtrNumber < XTC_DEVICE_TIMER_COUNT);
    XASSERT_NONVOID(InstancePtr->IsReady == XCOMPONENT_IS_READY);

    /*
     * set the Capture register to 0
     */

    XTmrCtr_mWriteReg(InstancePtr->BaseAddress, TmrCtrNumber,
                      XTC_TLR_OFFSET, 0);

    /*
     * reset the timer and the interrupt
     */

    XTmrCtr_mWriteReg(InstancePtr->BaseAddress, TmrCtrNumber,
                      XTC_TCSR_OFFSET,
                      XTC_CSR_INT_OCCURED_MASK | XTC_CSR_LOAD_MASK);

    /*
     * set the control/status register to enable timer
     */
    XTmrCtr_mWriteReg(InstancePtr->BaseAddress, TmrCtrNumber,
                      XTC_TCSR_OFFSET, XTC_CSR_ENABLE_TMR_MASK);

    /*
     * read the timer
     */
    TimerCount1 = XTimerCtr_mReadReg(InstancePtr->BaseAddress,
                                     TmrCtrNumber, XTC_TCR_OFFSET);
    /*
     * make sure timer is incrementing if the Count rolls over to zero
     * and the timer still has not incremented an error is returned
     */

    do
    {
        TimerCount2 = XTimerCtr_mReadReg(InstancePtr->BaseAddress,
                                        TmrCtrNumber, XTC_TCR_OFFSET);
        Count++;
    }
    while ((TimerCount1 == TimerCount2) && (Count != 0));

    /*
     * reset the timer and the interrupt
     */

    XTmrCtr_mWriteReg(InstancePtr->BaseAddress, TmrCtrNumber,
                      XTC_TCSR_OFFSET,
                      XTC_CSR_INT_OCCURED_MASK | XTC_CSR_LOAD_MASK);

    /*
     * set the control/status register to 0 to complete initialization
     * this disables the timer completely and allows it to be used again
     */

    XTmrCtr_mWriteReg(InstancePtr->BaseAddress, TmrCtrNumber,
                      XTC_TCSR_OFFSET, 0);

    if (TimerCount1 == TimerCount2)
    {
        return XST_FAILURE;
    }
    else
    {
        return XST_SUCCESS;
    }
}

