#pragma once


enum log_levels  {ERROR=0, INFO, TRACE, DEBUG};
typedef enum log_levels log_levels;




void trace(log_levels level, char *format, ...);


log_levels set_log_level(log_levels level);

