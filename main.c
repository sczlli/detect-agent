#include "src/core/config.h"
#include "src/core/logger.h"

int main() {
    if (config_load("agent.conf") != 0) {
        // Use the logger to report an error, even with default settings
        LOG_FATAL("Failed to load configuration file.");
        return 1;
    }

    const char* log_level_str = config_get_string("log_level", "INFO");
    const char* log_file = config_get_string("log_file", "agent.log");

    // You'll need a small helper to convert "INFO" string to LOG_LEVEL_INFO enum
    LogLevel level = get_level_from_string(log_level_str);

    logger_init(level, log_file);

    LOG_INFO("Agent started with settings from config file.");

    logger_close();
    config_close();
    return 0;
}
