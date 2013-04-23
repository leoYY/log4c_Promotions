log4c_Promotions
================

Do some promotions on log4c lib for personal requirements

Log4c is an open source lib. 

Promotions :
1. add some macro definitions.

In details, 
I add some macro definitions in log4c.h, just like WARNING_LOG FATAL_LOG

Usually, you can do some initional in main.cpp/main.c like 
LOG_INIT()

some code....

LOG_UINIT()

WARNING_LOG(_fmt_,arg...),DEBUG_LOG(_fmt_,arg...),FATAL_LOG(_fmt_,arg...),NOTICE_LOG(_fmt_,arg...)

By using macro definitions as above, \_\_FILE\_\_ and \_\_LINE\_\_ will be found in log file.
