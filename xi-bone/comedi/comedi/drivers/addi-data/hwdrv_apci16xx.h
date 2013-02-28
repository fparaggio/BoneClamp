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

#ifndef COMEDI_SUBD_TTLIO
#define COMEDI_SUBD_TTLIO   11	/* Digital Input Output But TTL */
#endif

#ifndef ADDIDATA_ENABLE
#define ADDIDATA_ENABLE  1
#define ADDIDATA_DISABLE 0
#endif

#define APCI16XX_TTL_INIT           0
#define APCI16XX_TTL_INITDIRECTION  1
#define APCI16XX_TTL_OUTPUTMEMORY   2

#define APCI16XX_TTL_READCHANNEL            0
#define APCI16XX_TTL_READPORT               1

#define APCI16XX_TTL_WRITECHANNEL_ON        0
#define APCI16XX_TTL_WRITECHANNEL_OFF       1
#define APCI16XX_TTL_WRITEPORT_ON           2
#define APCI16XX_TTL_WRITEPORT_OFF          3

#define APCI16XX_TTL_READ_ALL_INPUTS        0
#define APCI16XX_TTL_READ_ALL_OUTPUTS       1

#ifdef __KERNEL__

static const comedi_lrange range_apci16xx_ttl = { 12,
	{BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
			BIP_RANGE(1),
		BIP_RANGE(1)}
};

/*
+----------------------------------------------------------------------------+
|                       TTL INISIALISATION FUNCTION                          |
+----------------------------------------------------------------------------+
*/

int i_APCI16XX_InsnConfigInitTTLIO(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);

/*
+----------------------------------------------------------------------------+
|                       TTL INPUT FUNCTION                                   |
+----------------------------------------------------------------------------+
*/

int i_APCI16XX_InsnBitsReadTTLIO(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);

int i_APCI16XX_InsnReadTTLIOAllPortValue(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);

/*
+----------------------------------------------------------------------------+
|                            TTL OUTPUT FUNCTIONS                            |
+----------------------------------------------------------------------------+
*/

int i_APCI16XX_InsnBitsWriteTTLIO(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);

int i_APCI16XX_Reset(comedi_device * dev);
#endif
