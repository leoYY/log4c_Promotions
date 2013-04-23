/* $Id: log4c.h,v 1.4 2006/11/07 23:13:28 rbyrne Exp $
 *
 * log4c.h
 *
 * Copyright 2001-2002, Meiosys (www.meiosys.com). All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef log4c_log4c_h
#define log4c_log4c_h
#include <log4c/version.h>
#include <log4c/init.h>
#include <log4c/rc.h>
#include <log4c/appender.h>
#include <log4c/rollingpolicy.h>
#include <log4c/category.h>
#include <log4c/layout.h>
#include <log4c/logging_event.h>
#include <log4c/priority.h>

#define LOG_INIT() \
    log4c_init();\
    
#define LOG_UNINIT() \
    log4c_fini()

#define FORAMT_LINE(_fmt_,arg...) \
    "%s[%d] - " _fmt_,__FILE__,__LINE__,##arg

#define WARNING_LOG(_fmt_,arg...) \
    log4c_category_log(log4c_category_get("root"),LOG4C_PRIORITY_WARN, FORAMT_LINE(_fmt_,##arg))

#define DEBUG_LOG(_fmt_,arg...) \
    log4c_category_log(log4c_category_get("root"),LOG4C_PRIORITY_DEBUG, FORAMT_LINE(_fmt_,##arg))

#define FATAL_LOG(_fmt_,arg...) \
    log4c_category_log(log4c_category_get("root"),LOG4C_PRIORITY_FATAL, FORAMT_LINE(_fmt_,##arg))

#define NOTICE_LOG(_fmt_,arg...) \
    log4c_category_log(log4c_category_get("root"),LOG4C_PRIORITY_NOTICE, FORAMT_LINE(_fmt_,##arg))

#endif

