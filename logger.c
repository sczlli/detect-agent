#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

//Static global variables to encapsulate the logger state
static LogLevel current_log_level = LOG_LEVEL_INFO;
static FILE* log_file = NULL;

static const char* get_log_level_string(LogLevel level) {

   switch (level) {
       case LOG_LEVEL_DEBUG: return "DEBUG";
       case LOG_LEVEL_INFO:  return "INFO"; 
       case LOG_LEVEL_WARN:  return "WARN";
       case LOG_LEVEL_ERROR: return "ERROR";
       case LOG_LEVEL_FATAL: return "FATAL";
       default:              return "UNKNOWN";
   }


}





