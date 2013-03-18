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

#define APCI1710_30MHZ           30
#define APCI1710_33MHZ           33
#define APCI1710_40MHZ           40

#define APCI1710_SINGLE     0
#define APCI1710_CONTINUOUS 1

#define APCI1710_CHRONO_PROGRESS_STATUS		0
#define APCI1710_CHRONO_READVALUE			1
#define APCI1710_CHRONO_CONVERTVALUE		2
#define APCI1710_CHRONO_READINTERRUPT       3

#define APCI1710_CHRONO_SET_CHANNELON       		0
#define APCI1710_CHRONO_SET_CHANNELOFF		1
#define APCI1710_CHRONO_READ_CHANNEL		2
#define APCI1710_CHRONO_READ_PORT			3

/*
+----------------------------------------------------------------------------+
|                  CHRONOMETER INISIALISATION FUNCTION   |
+----------------------------------------------------------------------------+
 */

INT i_APCI1710_InsnConfigInitChrono(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

INT i_APCI1710_InsnWriteEnableDisableChrono(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);

/*
+----------------------------------------------------------------------------+
|                       CHRONOMETER READ FUNCTION                            |
+----------------------------------------------------------------------------+
*/

INT i_APCI1710_InsnReadChrono(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

INT i_APCI1710_GetChronoProgressStatus(comedi_device * dev,
	BYTE b_ModulNbr, PBYTE pb_ChronoStatus);

INT i_APCI1710_ReadChronoValue(comedi_device * dev,
	BYTE b_ModulNbr,
	UINT ui_TimeOut, PBYTE pb_ChronoStatus, PULONG pul_ChronoValue);

INT i_APCI1710_ConvertChronoValue(comedi_device * dev,
	BYTE b_ModulNbr,
	ULONG ul_ChronoValue,
	PULONG pul_Hour,
	PBYTE pb_Minute,
	PBYTE pb_Second,
	PUINT pui_MilliSecond, PUINT pui_MicroSecond, PUINT pui_NanoSecond);

/*
+----------------------------------------------------------------------------+
|                       CHRONOMETER DIGITAL INPUT OUTPUT FUNCTION                  |
+----------------------------------------------------------------------------+
*/

INT i_APCI1710_InsnBitsChronoDigitalIO(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);
