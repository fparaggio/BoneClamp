/**
@verbatim

Copyright (C) 2004,2005  ADDI-DATA GmbH for the source code of this module. 
        
        ADDI-DATA GmbH 
        Dieselstrasse 3 
        D-77833 Ottersweier 
        Tel: +19(0)7223/9493-0 
        Fax: +49(0)7223/9493-92 
        http://www.addi-data-com 
        info@addi-data.com 

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

You shoud also find the complete GPL in the COPYING file accompanying this source code.

@endverbatim
*/

#define APCI1710_PCI_BUS_CLOCK 					0
#define APCI1710_FRONT_CONNECTOR_INPUT 			1
#define APCI1710_TIMER_READVALUE				0
#define APCI1710_TIMER_GETOUTPUTLEVEL			1
#define APCI1710_TIMER_GETPROGRESSSTATUS		2
#define APCI1710_TIMER_WRITEVALUE				3

#define APCI1710_TIMER_READINTERRUPT            1
#define APCI1710_TIMER_READALLTIMER             2

// BEGIN JK 27.10.03 : Add the possibility to use a 40 Mhz quartz
#ifndef APCI1710_10MHZ
#define APCI1710_10MHZ           10
#endif
// END JK 27.10.03 : Add the possibility to use a 40 Mhz quartz

/*
+----------------------------------------------------------------------------+
|                       82X54 TIMER INISIALISATION FUNCTION                  |
+----------------------------------------------------------------------------+
*/

INT i_APCI1710_InsnConfigInitTimer(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

INT i_APCI1710_InsnWriteEnableDisableTimer(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);
/*
+----------------------------------------------------------------------------+
|                       82X54 READ FUNCTION                                  |
+----------------------------------------------------------------------------+
*/

INT i_APCI1710_InsnReadAllTimerValue(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

INT i_APCI1710_InsnBitsTimer(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

/*
+----------------------------------------------------------------------------+
|                       82X54 READ & WRITE FUNCTION                          |
+----------------------------------------------------------------------------+
*/
INT i_APCI1710_ReadTimerValue(comedi_device * dev,
	BYTE b_ModulNbr, BYTE b_TimerNbr, PULONG pul_TimerValue);

INT i_APCI1710_GetTimerOutputLevel(comedi_device * dev,
	BYTE b_ModulNbr, BYTE b_TimerNbr, PBYTE pb_OutputLevel);

INT i_APCI1710_GetTimerProgressStatus(comedi_device * dev,
	BYTE b_ModulNbr, BYTE b_TimerNbr, PBYTE pb_TimerStatus);

/*
+----------------------------------------------------------------------------+
|                       82X54 WRITE FUNCTION                                 |
+----------------------------------------------------------------------------+
*/
INT i_APCI1710_WriteTimerValue(comedi_device * dev,
	BYTE b_ModulNbr, BYTE b_TimerNbr, ULONG ul_WriteValue);
