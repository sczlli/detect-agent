#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

// Static global variables to encapsulate the logger's state
static LogLevel current_log_level = LOG_LEVEL_INFO;
static FILE* log_file = NULL;

// Helper function to convert LogLevel enum to a string
static const char* get_log_level_string(LogLevel level) {
    switch (level) {
        case LOG_LEVEL_DEBUG: return "DEBUG";
        case LOG_LEVEL_INFO:  return "INFO ";
        case LOG_LEVEL_WARN:  return "WARN ";
        case LOG_LEVEL_ERROR: return "ERROR";
        case LOG_LEVEL_FATAL: return "FATAL";
        default:              return "UNKNOWN";
    }
}

// Initializes the logging system
void logger_init(LogLevel level, const char* log_file_path) {
    current_log_level = level;

    if (log_file_path) {
        // Open the file in append mode ("a") to preserve history
        log_file = fopen(log_file_path, "a");
        if (!log_file) {
            fprintf(stderr, "ERROR: Could not open log file: %s\n", log_file_path);
        }
    }
}

// The core logging function
void logger_log(LogLevel level, const char* file, int line, const char* format, ...) {
    // Filter messages based on the configured level
    if (level < current_log_level) {
        return;
    }

    // Get the current timestamp
    time_t timer;
    char time_buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    // Prepare the full log message
    char log_message[20248];
    int offset = 0;

    // Add timestamp, log level, and file/line info
    offset += snprintf(log_message + offset, sizeof(log_message) - offset,
                       "[%s] %s [%s:%d] ", time_buffer, get_log_level_string(level), file, line);

    // Format the user's message using variable arguments
    va_list args;
    va_start(args, format);
    offset += vsnprintf(log_message + offset, sizeof(log_message) - offset, format, args);
    va_end(args);
    
    // Ensure there is a newline at the end
    if (offset > 0 && log_message[offset-1] != '\n') {
        snprintf(log_message + offset, sizeof(log_message) - offset, "\n");
    }

    // Write to the target (file or console)
    if (log_file) {
        fprintf(log_file, "%s", log_message);
        fflush(log_file); // Ensure immediate write to disk
    } else {
        fprintf((level >= LOG_LEVEL_WARN) ? stderr : stdout, "%s", log_message);
    }
}


// get_log_level function
LogLevel get_level_from_string(const char* level_str) {
    if (strcmp(level_str, "DEBUG") == 0) {
        return LOG_LEVEL_DEBUG;
    }
    if (strcmp(level_str, "INFO") == 0) {
        return LOG_LEVEL_INFO;
    }
    if (strcmp(level_str, "WARN") == 0) {
        return LOG_LEVEL_WARN;
    }
    if (strcmp(level_str, "ERROR") == 0) {
        return LOG_LEVEL_ERROR;
    }
    if (strcmp(level_str, "FATAL") == 0) {
        return LOG_LEVEL_FATAL;
    }
    // Default to INFO if the string is unknown
    return LOG_LEVEL_INFO;
}

// Closes the logging system
void logger_close() {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}
