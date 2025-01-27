////////////////////////////////////////////////////////////////////////////////
//
// Filename: 	keys.h
// {{{
// Project:	AutoFPGA, a utility for composing FPGA designs from peripherals
//
// Purpose:	Defines the names of the strings AutoFPGA understands.  These
//		are the key names understood by AutoFPGA and described by the
//	ICD.
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
// }}}
// Copyright (C) 2017-2022, Gisselquist Technology, LLC
// {{{
// This program is free software (firmware): you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
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
// }}}
// License:	GPL, v3, as defined and found on www.gnu.org,
// {{{
//		http://www.gnu.org/licenses/gpl.html
//
////////////////////////////////////////////////////////////////////////////////
//
// }}}
#ifndef	ICD_H
#define	ICD_H

#include <string>
#include "mapdhash.h"

//
extern const	STRING	KYLEGAL;
extern const	STRING	KYCOPYRIGHT;
extern const	STRING	KYCMDLINE;
extern const	STRING	KYSUBD;	// Output subdirectory
extern const	STRING	KYPATH;
extern const	STRING	KYSUBD;
// extern const	STRING	KYBUS_ADDRESS_WIDTH;
extern const	STRING	KYSKIPADDR;
extern const	STRING	KYRESET_ADDRESS;
// For subclassing
extern const	STRING	KYPLUSDOT;
extern const	STRING	KYINCLUDEFILE;
// Other global keys
extern const	STRING	KYREGDEFS_CPP_INCLUDE;
extern const	STRING	KYREGDEFS_CPP_INSERT;
extern const	STRING	KYKEYS_TRIMLIST;
extern const	STRING	KYKEYS_INTLIST;
extern const	STRING	KYPROJECT;
//
extern const	STRING	KYSIO;
extern const	STRING	KYDIO;
extern const	STRING	KYSIO_SEL;
extern const	STRING	KYDIO_SEL;
//
extern const	STRING	KYPREFIX;
extern const	STRING	KYACCESS;
extern const	STRING	KYDEPENDS;
extern const	STRING	KYERROR_WIRE;
extern const	STRING	KYSLAVE,
			KYSLAVE_TYPE,
			KYSLAVE_BUS,
			KYSLAVE_BUS_NAME,
			KYSLAVE_ORDER,
			KYSLAVE_AWID,
			KYSLAVE_OPTIONS,
			KYSLAVE_PREFIX,
			KYSLAVE_PORTLIST,
			KYSLAVE_ANSIPORTLIST,
			KYSLAVE_IANSI,
			KYSLAVE_OANSI,
			KYSLAVE_ANSPREFIX;
extern const	STRING	KYMASTER,
			KYMASTER_TYPE,
			KYMASTER_BUS,
			KYMASTER_BUS_NAME,
			KYMASTER_PREFIX,
			KYMASTER_AWID,
			KYMASTER_OPTIONS,
			KYMASTER_PORTLIST,
			KYMASTER_ANSIPORTLIST,
			KYMASTER_IDWIDTH,
			KYMASTER_IANSI,
			KYMASTER_OANSI,
			KYMASTER_ANSPREFIX;
// Types of bus masters.
// KYBUS, (HOST), (VIDEO), (XCLOCK), and ...
extern	const	STRING	KYSUBBUS,
			KYARBITER,
			KYXCLOCK,
			KYHOST,
			KYCPU;
//
extern const	STRING	KYBASE;
extern const	STRING	KYREGBASE;
extern const	STRING	KYMASK;
extern const	STRING	KYNADDR;
//
extern const	STRING	KYEXPR;
extern const	STRING	KYVAL;
extern const	STRING	KYFORMAT;
extern const	STRING	KYSTR;
//
extern const	STRING	KYSCOPE;
extern const	STRING	KYMEMORY;
extern const	STRING	KYSINGLE;
extern const	STRING	KYDOUBLE;
extern const	STRING	KYOTHER;
//
extern const	STRING	KYNP;
extern const	STRING	KYNPIC;
extern const	STRING	KYNPSINGLE;
extern const	STRING	KYNPDOUBLE;
extern const	STRING	KYNPMEMORY;
extern const	STRING	KYNSCOPES;
// Regs definition(s)
extern const	STRING	KYREGS_N;
extern const	STRING	KYREGS_NOTE;
extern const	STRING	KYREGDEFS_H_INCLUDE;
extern const	STRING	KYREGDEFS_H_DEFNS;
extern const	STRING	KYREGDEFS_H_INSERT;
// Board definitions for C/C++
extern const	STRING	KYBDEF_INCLUDE;
extern const	STRING	KYBDEF_DEFN;
extern const	STRING	KYBDEF_IOTYPE;
extern const	STRING	KYBDEF_OSDEF;
extern const	STRING	KYBDEF_OSVAL;
extern const	STRING	KYBDEF_INSERT;
// Top definitions
extern const	STRING	KYTOP_PORTLIST;
extern const	STRING	KYTOP_IODECL;
extern const	STRING	KYTOP_PARAM;
extern const	STRING	KYTOP_DEFNS;
extern const	STRING	KYTOP_MAIN;
extern const	STRING	KYTOP_INSERT;
// Main definitions
extern const	STRING	KYMAIN_INCLUDE;
extern const	STRING	KYMAIN_PORTLIST;
extern const	STRING	KYMAIN_IODECL;
extern const	STRING	KYMAIN_PARAM;
extern const	STRING	KYMAIN_DEFNS;
extern const	STRING	KYMAIN_INSERT;
extern const	STRING	KYMAIN_ALT;
// Definitions for the .ld file(s)
extern const	STRING	KYLD_FILE;
extern const	STRING	KYLD_SCRIPT;
extern const	STRING	KYLD_ENTRY;
extern const	STRING	KYLD_NAME;
extern const	STRING	KYLD_PERM;
extern const	STRING	KYLD_DEFNS;
extern const	STRING	KYFLASH;
extern const	STRING	KYSCRIPT;
// XDC/UCF definitions
extern	const	STRING	KYXDC_FILE;
extern	const	STRING	KYXDC_INSERT;
extern	const	STRING	KYPCF_FILE;
extern	const	STRING	KYPCF_INSERT;
extern	const	STRING	KYLPF_FILE;
extern	const	STRING	KYLPF_INSERT;
extern	const	STRING	KYUCF_FILE;
extern	const	STRING	KYUCF_INSERT;
// Arbitrary output data files
extern	const	STRING	KYOUT_FILE;
extern	const	STRING	KYOUT_DATA;
// rtl/Makefile include file
extern	const	STRING	KYRTL_MAKE_GROUP;
extern	const	STRING	KYRTL_MAKE_SUBD;
extern	const	STRING	KYRTL_MAKE_VDIRS;
extern	const	STRING	KYRTL_MAKE_FILES;
extern	const	STRING	KYVFLIST;
extern	const	STRING	KYAUTOVDIRS;
// PIC definitions
extern	const	STRING	KYPIC, KYPIC_BUS, KYPIC_MAX;
// Cache information
extern	const	STRING	KYCACHABLE_FILE;
// Interrupt definitions
extern	const	STRING	KY_INT, KYINTLIST, KY_WIRE, KY_DOTWIRE, KY_ID;
// SIM definitions
extern	const	STRING	KYSIM_INCLUDE, KYSIM_DEFINES, KYSIM_DEFNS,
			KYSIM_PREINITIAL, KYSIM_INIT, KYSIM_TICK,
			KYSIM_SETRESET, KYSIM_CLRRESET,
			KYSIM_DBGCONDITION, KYSIM_DEBUG,
			KYSIM_LOAD, KYSIM_METHODS, KYSIM_CLOCK;
// CLOCK definitions
extern	const	STRING	KYCLOCK,
			KYCLOCK_NAME,
			KYCLOCK_TOP,
			KY_NAME,
			KY_TOP,
			KY_CLASS,
			KY_FREQUENCY;
// BUS definitions
extern	const	STRING	KYBUS,
			KYBUS_NAME,
			KYBUS_PREFIX,
			KYBUS_TYPE,
			KYBUS_WIDTH,
			KYBUS_IDWIDTH,
			KYBUS_AWID,
			KYBUS_CLOCK,
			KYBUS_NULLSZ,
			KY_TYPE,
			KY_WIDTH,
			KY_IDWIDTH,
			KY_AWID,
			KY_CLOCK,
			KY_RESET,
			KY_NULLSZ,
			KY_NSELECT,
			KYDEFAULT_BUS,
			KYREGISTER_BUS,
			KYREGISTER_BUS_NAME;
// Bus options
extern	const	STRING	KY_OPT_LOWPOWER,
			KY_OPT_LINGER,
			KY_OPT_LGMAXBURST,
			KY_OPT_TIMEOUT,
			KY_OPT_STARVATION_TIMEOUT,
			KY_OPT_DBLBUFFER;
//
extern const	STRING	KYSTHIS;
extern const	STRING	KYTHISDOT;

#endif
