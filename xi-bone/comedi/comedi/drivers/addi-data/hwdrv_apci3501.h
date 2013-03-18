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
// Card Specific information
#define APCI3501_BOARD_VENDOR_ID                 0x15B8
#define APCI3501_ADDRESS_RANGE                   255

#define APCI3501_DIGITAL_IP                       0x50
#define APCI3501_DIGITAL_OP                       0x40
#define APCI3501_ANALOG_OUTPUT                    0x00

//Analog Output related Defines
#define APCI3501_AO_VOLT_MODE                     0
#define APCI3501_AO_PROG                          4
#define APCI3501_AO_TRIG_SCS                      8
#define UNIPOLAR                                  0
#define BIPOLAR                                   1
#define MODE0                                     0
#define MODE1                                     1
// ANALOG OUTPUT RANGE
comedi_lrange range_apci3501_ao = { 2, {
			BIP_RANGE(10),
			UNI_RANGE(10)
	}
};

//Watchdog Related Defines 

#define APCI3501_WATCHDOG                         0x20
#define APCI3501_TCW_SYNC_ENABLEDISABLE           0
#define APCI3501_TCW_RELOAD_VALUE                 4
#define APCI3501_TCW_TIMEBASE                     8
#define APCI3501_TCW_PROG                         12
#define APCI3501_TCW_TRIG_STATUS                  16
#define APCI3501_TCW_IRQ                          20
#define APCI3501_TCW_WARN_TIMEVAL                 24
#define APCI3501_TCW_WARN_TIMEBASE                28
#define ADDIDATA_TIMER                            0
#define ADDIDATA_WATCHDOG                         2

// Hardware Layer  functions for Apci3501

//AO
INT i_APCI3501_ConfigAnalogOutput(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);
INT i_APCI3501_WriteAnalogOutput(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

//DI
// for di read
//INT i_APCI3501_ReadDigitalInput(comedi_device *dev,comedi_subdevice *s,comedi_insn *insn,lsampl_t *data);

INT i_APCI3501_ReadDigitalInput(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

//DO
int i_APCI3501_ConfigDigitalOutput(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);
INT i_APCI3501_WriteDigitalOutput(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);
INT i_APCI3501_ReadDigitalOutput(comedi_device * dev, comedi_subdevice * s,
	comedi_insn * insn, lsampl_t * data);

// TIMER  
// timer value is passed as u seconds
INT i_APCI3501_ConfigTimerCounterWatchdog(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);
int i_APCI3501_StartStopWriteTimerCounterWatchdog(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);
int i_APCI3501_ReadTimerCounterWatchdog(comedi_device * dev,
	comedi_subdevice * s, comedi_insn * insn, lsampl_t * data);
//Interrupt
void v_APCI3501_Interrupt(int irq, void *d);

//Reset functions
int i_APCI3501_Reset(comedi_device * dev);
