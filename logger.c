#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

static LogLevel current_log_level = LOG_LEVEL_INFO;
static FILE* log_file = NULL;








