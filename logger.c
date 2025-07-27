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


 //initializes the logging system 
 void logger_init(LogLevel level, const char* log_file_path) {
    current_log_level = level;

   if (log_file_path) {
        // Open the file in append mode ("a") to preserve history
        log_file = fopen(log_file_path, "a");
        if (!log_file_path)  {
            fprint(stderr, "ERROR: Could not open log file: %s\n", log_file_path);

          }      
     }
}

  
 

   }   


 





