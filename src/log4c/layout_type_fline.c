// Copyright (c) 2013 Baidu.com , Inc. All Rights Reserved
// @author: zwh (yuanyi03@baidu.com)
// @brief : 

#include <log4c/layout.h>
#include <log4c/priority.h>
#include <sd/sprintf.h>
#include <sd/sd_xplatform.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char* fline_format(
        const log4c_layout_t*   a_layout,
        const log4c_logging_event_t* a_event)
{
    static char buffer[1024];
#ifndef _WIN32
#ifndef __HP_cc
#warning gmtime() routine should be defined in sd_xplatform
#endif 
    struct tm   tm;
    gmtime_r(&a_event->evt_timestamp.tv_sec, &tm);
    snprintf(buffer, sizeof(buffer), "%-4s %04d%02d%02d %02d:%02d:%02d %s\n",
               log4c_priority_to_string(a_event->evt_priority),
               tm.tm_year + 1900,
               tm.tm_mon+1,
               tm.tm_mday,
               tm.tm_hour,
               tm.tm_min,
               tm.tm_sec,
               a_event->evt_msg);
#else
        SYSTEMTIME stime;
        if (FileTimeToSystemTime(&a_event->evt_timestamp, &stime)){
            snprintf(buffer, sizeof(buffer), "%-4s %04d%02d%02d %02d:%02d:%02d %s\n",
                        log4c_priority_to_string(a_event->evt_priority),
                        stime.wYear,
                        stime.wMonth,
                        stime.wDay,
                        stime.wHour,
                        stime.wMinute,
                        stime.wSecond,
                        a_event->evt_msg);
        }
#endif 
    return buffer;
}

const log4c_layout_type_t log4c_layout_type_fline = {
    "fline",
    fline_format,
};
