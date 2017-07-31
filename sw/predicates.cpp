////////////////////////////////////////////////////////////////////////////////
//
// Filename: 	predicates.cpp
//
// Project:	AutoFPGA, a utility for composing FPGA designs from peripherals
//
// Purpose:
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2017, Gisselquist Technology, LLC
//
// This program is free software (firmware): you can redistribute it and/or
// modify it under the terms of  the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
// target there if the PDF file isn't present.)  If not, see
// <http://www.gnu.org/licenses/> for a copy.
//
// License:	GPL, v3, as defined and found on www.gnu.org,
//		http://www.gnu.org/licenses/gpl.html
//
//
////////////////////////////////////////////////////////////////////////////////
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <ctype.h>

#include "parser.h"
#include "keys.h"
#include "kveval.h"
#include "legalnotice.h"
#include "bldtestb.h"
#include "bitlib.h"
#include "plist.h"
#include "bldregdefs.h"
#include "ifdefs.h"
#include "bldsim.h"
#include "predicates.h"

extern	int	gbl_err;
extern	FILE	*gbl_dump;

//
// Is the given location within our hash a master?  Look it up.
//
// To be a bus master, it must have a @MTYPE field.
//
bool	isbusmaster(MAPDHASH &phash) {
	return (NULL != getstring(phash, KYMASTER_TYPE));
}

//
// Same thing, but when given a location within the tree, rather than a hash
// value.
bool	isbusmaster(MAPT &pmap) {
	if (pmap.m_typ != MAPT_MAP)
		return false;
	return isbusmaster(*pmap.u.m_m);
}

//
// Is the given hash a definition of a peripheral
//
// To be a peripheral, it must have a @PTYPE field.
//
bool	isperipheral(MAPDHASH &phash) {
	return (NULL != getstring(phash, KYSLAVE_TYPE));
	// return (phash.end() != phash.find(KYSLAVE_TYPE));
}

bool	isperipheral(MAPT &pmap) {
	if (pmap.m_typ != MAPT_MAP)
		return false;
	return isperipheral(*pmap.u.m_m);
}

//
// Does the given hash define a programmable interrupt controller?
//
// If so, it must have a @PIC.MAX field identifying the maximum number of
// interrupts that can be assigned to it.
bool	ispic(MAPDHASH &phash) {
	return (phash.end() != findkey(phash, KYPIC_MAX));
}

bool	ispic(MAPT &pmap) {
	if (pmap.m_typ != MAPT_MAP)
		return false;
	return ispic(*pmap.u.m_m);
}

// Does this reference a memory peripheral?
bool	ismemory(MAPDHASH &phash) {
	STRINGP	strp;

	strp = getstring(phash, KYSLAVE_TYPE);
	if (!strp)
		return false;
	if (KYMEMORY.compare(*strp) != 0)
		return false;
	return true;
}

bool	ismemory(MAPT &pmap) {
	if (pmap.m_typ != MAPT_MAP)
		return false;
	return ismemory(*pmap.u.m_m);
}

//
// Does this component have a bus definition within it, or does it reference
// a bus?
bool	refbus(MAPDHASH &phash) {

	if (NULL != getstring(phash, KYBUS))
		return true;
	// else if (NULL != getmap(phash, KYBUS)) return true;
	return false;
}

bool	refbus(MAPT &pmap) {
	if (pmap.m_typ != MAPT_MAP)
		return false;
	return refbus(*pmap.u.m_m);
}

//
// Does this component have a clock definition within it, or does it reference
// a clock?
//
bool	refclock(MAPDHASH &phash) {
	STRINGP	strp;

	strp = getstring(phash, KYCLOCK);
	if (!strp)
		return false;
	return true;
}

bool	refclock(MAPT &pmap) {
	if (pmap.m_typ != MAPT_MAP)
		return false;
	return refbus(*pmap.u.m_m);
}