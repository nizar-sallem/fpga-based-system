////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2004 Xilinx, Inc.  All rights reserved. 
// 
// Xilinx, Inc. 
// XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
// COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS 
// ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
// STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
// IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
// FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION. 
// XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
// THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
// ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
// FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
// AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $Id: microblaze_exceptions_g.c,v 1.3.6.8 2007/07/03 05:42:16 vasanth Exp $
////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/**
*
* @file microblaze_exceptions_g.c
*
* This file contains the exception handler table for the MicroBlaze processor.
* This file is usually generated by LibGen.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Date     Changes
* ----- -------- -----------------------------------------------
* 1.00a 06/24/04 First release
* </pre>
*
******************************************************************************/
#include "microblaze_exceptions_i.h"
#include "xparameters.h"

extern void XNullHandler (void *);

/*
* The exception handler table for microblaze processor
*/

MB_ExceptionVectorTableEntry MB_ExceptionVectorTable[] =
{
    {XNullHandler, (void*) 0},                                      /* --          FSL Exception         -- */
    {XNullHandler, (void*) 1},                                      /* -- Unaligned Access Exception     -- */
    {XNullHandler, (void*) 2},                                      /* --   Illegal Opcode Exception     -- */
    {XNullHandler, (void*) 3},                                      /* --         IOPB Exception         -- */
    {XNullHandler, (void*) 4},                                      /* --         DOPB Exception         -- */
    {XNullHandler, (void*) 5},                                      /* --       Div-by-0 Exception       -- */
    {XNullHandler, (void*) 6},                                      /* --         FPU  Exception         -- */
    {XNullHandler, (void*) 7}                                       /* --         MMU  Exceptions        -- */    
};
