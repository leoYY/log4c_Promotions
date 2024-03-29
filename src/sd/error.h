/* $Id: error.h,v 1.6 2006/09/21 11:59:35 legoater Exp $
 *
 * Copyright 2001-2003, Meiosys (www.meiosys.com). All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef __sd_error_h
#define __sd_error_h

#include <stdarg.h>

extern int sd_debug(const char *fmt, ...);
extern int sd_error(const char *fmt, ...);

#endif /* __sd_error_h */
