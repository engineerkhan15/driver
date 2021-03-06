/**************************************************************
 * Copyright (C) 2010   STMicroelectronics. All Rights Reserved.
 * This file is part of the latest release of the Multicom4 project. This release 
 * is fully functional and provides all of the original MME functionality.This 
 * release  is now considered stable and ready for integration with other software 
 * components.

 * Multicom4 is a free software; you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License as published by the Free Software Foundation 
 * version 2.

 * Multicom4 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with Multicom4; 
 * see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - 
 * Suite 330, Boston, MA 02111-1307, USA.

 * Written by Multicom team at STMicroelectronics in November 2010.  
 * Contact multicom.support@st.com. 
**************************************************************/

/*
 *
 */

/*
 * fli7510 ST231 Audio
 */


/*
 * Mailbox allocation (ST231 only see even mbox IRQs)
 *
 * MBOX4 -> video
 * MBOX7 -> audio 1
 * MBOX9 -> audio 2
 *
 */

#include <bsp/_bsp.h>

#define MBOX0_ADDR	0xfd740000
#define MBOX1_ADDR	0xfd760000
#define MBOX2_ADDR	0xfd780000
#define MBOX3_ADDR	0xfd230000
#define MBOX4_ADDR	0xfd234000

#include <os21/st200.h>

/* #include <os21/st200/fli7510.h> */
extern interrupt_name_t OS21_INTERRUPT_MAILBOX_4;
extern interrupt_name_t OS21_INTERRUPT_MAILBOX_7;
extern interrupt_name_t OS21_INTERRUPT_MAILBOX_9;
/*
extern interrupt_name_t OS21_INTERRUPT_MAILBOX_??;
extern interrupt_name_t OS21_INTERRUPT_MAILBOX_??;
*/

struct bsp_mbox_regs bsp_mailboxes[] = 
{
  { 
    .base	= (void *) (MBOX0_ADDR),	/* Video LX Mailbox (MBOX0.1) */
    .interrupt	= 0,				/* Video owns SET1 */
    .flags      = 0
  },
  { 
    .base	= (void *) (MBOX0_ADDR+0x100),	/* Video LX Mailbox (MBOX0.2) */
    .interrupt	= 0,				/* *WE* own SET2 */
    .flags      = 0
  },


  {
    .base	= (void *) (MBOX1_ADDR),	/* Audio 0 LX Mailbox (MBOX1.1) */
    .interrupt  = 0,				/* Audio owns SET1 */
    .flags      = 0
  },
  {
    .base	= (void *) (MBOX1_ADDR+0x100),	/* Audio 0 LX Mailbox (MBOX1.2) */
    .interrupt  = 0,				/* *WE* own SET2 */
    .flags      = 0
  },


  {
    .base	= (void *) (MBOX2_ADDR),			/* Audio 1 LX Mailbox (MBOX1.1) */
    .interrupt  = (unsigned int) &OS21_INTERRUPT_MAILBOX_9,	/* Audio owns SET1 */
    .flags      = 0
  },
  {
    .base	= (void *) (MBOX2_ADDR+0x100),	/* Audio 1 LX Mailbox (MBOX1.2) */
    .interrupt  = 0,				/* *WE* own SET2 */
    .flags      = 0
  },

};

unsigned int bsp_mailbox_count = sizeof(bsp_mailboxes)/sizeof(bsp_mailboxes[0]);

/*
 * Local Variables:
 *  tab-width: 8
 *  c-indent-level: 2
 *  c-basic-offset: 2
 * End:
 */
