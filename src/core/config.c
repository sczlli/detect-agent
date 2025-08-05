#include "config.h"
#include "logger.h" // For logging errors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONFIG_ENTRIES 50
#define MAX_LINE_LENGTH 256

// Structure to hold a single key-value pair
typedef struct {
    char* key;
    char* value;
} ConfigEntry;

// Static array to store all configuration entries
static ConfigEntry config_data[MAX_CONFIG_ENTRIES];
static int config_count = 0;


int config_load(const char* filepath) {
    (void)filepath; // Prevents "unused parameter" warning
    // Return 0 for success
    return 0;
}

const char* config_get_string(const char* key, const char* default_value) {
    (void)key; // Prevents "unused parameter" warning
    // Always return the default value for now
    return default_value;
}

int config_get_int(const char* key, int default_value) {
    (void)key; // Prevents "unused parameter" warning
    return default_value;
}

void config_close() {
    
}
