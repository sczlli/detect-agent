#ifndef LOGGER_H
#define LOGGER_H

// Log Level Definitions
// DEBUG, INFO, WARN, ERROR, FATAL
typedef enum {
    LOG_LEVEL_DEBUG, // Detailed messages for debugging
    LOG_LEVEL_INFO,  // Informational messages about normal operation
    LOG_LEVEL_WARN,  // Warnings about potentially problematic situations
    LOG_LEVEL_ERROR, // Errors that prevent some functionality but do not stop the agent
    LOG_LEVEL_FATAL  // Critical errors that cause the agent to terminate
} LogLevel;


LogLevel get_level_from_string(const char* level_str);


// Public Logger Functions
// -----------------------

/**
 * @brief Initializes the logging system.
 *
 * This function must be called once at the start of the application
 * to configure the minimum log level and the log file path.
 * If log_file_path is NULL, logs will only be written to stdout/stderr.
 *
 * @param level The minimum log level to record.
 * @param log_file_path The path to the file where logs will be written. If NULL, logs only to the console.
 */
void logger_init(LogLevel level, const char* log_file_path);

/**
 * @brief The main function for recording log messages.
 *
 * This function is the core of the logger. It should NOT be called directly
 * but through the LOG_DEBUG, LOG_INFO, LOG_WARN, etc., macros, which automatically
 * add the source file and line number information.
 *
 * @param level The severity level of the message.
 * @param file The name of the source file where the call originates (automatic with macros).
 * @param line The line number in the source file (automatic with macros).
 * @param format The format string (like printf).
 * @param ... Variable arguments for the format string.
 */
void logger_log(LogLevel level, const char* file, int line, const char* format, ...);

/**
 * @brief Closes the logging system.
 *
 * This function must be called at the end of the application to
 * properly close the log file and release resources.
 */
void logger_close();

// Macros to simplify logger usage
// -------------------------------
// These macros are the recommended way to use the logger.
// They automatically include __FILE__ (source file name) and __LINE__ (line number),
// making the logs much more useful for debugging.
#define LOG_DEBUG(format, ...) logger_log(LOG_LEVEL_DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_INFO(format, ...)  logger_log(LOG_LEVEL_INFO,  __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_WARN(format, ...)  logger_log(LOG_LEVEL_WARN,  __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) logger_log(LOG_LEVEL_ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...) logger_log(LOG_LEVEL_FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

#endif // LOGGER_H

