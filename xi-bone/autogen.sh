#-------------------------------------------------------------------------

#	This file is part of the BoneClamp Data Conversion and Processing System
#	Copyright (C) 2013 BoneClamp

#-------------------------------------------------------------------------

#	Filename: autogen.sh to generate xi-bone makefiles

#	Written in 2013 by:
#		Jon Newman <jnewman6@gatech.edu>
#		Yogi Patel <yapatel@gatech.edu>

#	To the extent possible under law, the author(s) have dedicated all copyright
#	and related and neighboring rights to this software to the public domain
#	worldwide. This software is distributed without any warranty.

#	You should have received a copy of the CC Public Domain Dedication along with
#	this software. If not, see <http://creativecommons.org/licenses/by-sa/3.0/legalcode>.

#!/bin/bash

aclocal -I m4
libtoolize --copy --force --automake
autoheader 
autoconf
automake -a -c
