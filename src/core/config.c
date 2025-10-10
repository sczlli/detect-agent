#include "config.h"
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

// Helper function to trim leading/trailing whitespace from a string
static char* trim_whitespace(char* str) {
    char* end;
    // Trim leading space
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str; // All spaces

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';

    return str;
}

int config_load(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        // This is not a fatal error; the program can proceed with defaults.
        return -1; 
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && config_count < MAX_CONFIG_ENTRIES) {
        char* clean_line = trim_whitespace(line);

        // Ignore empty lines and comments
        if (strlen(clean_line) == 0 || clean_line[0] == '#') {
            continue;
        }

        char* separator = strchr(clean_line, '=');
        if (!separator) {
            continue; // Line doesn't contain '=', so skip it
        }

        *separator = '\0'; // Split the string into key and value
        char* key = trim_whitespace(clean_line);
        char* value = trim_whitespace(separator + 1);

        if (strlen(key) > 0 && strlen(value) > 0) {
            config_data[config_count].key = strdup(key);
            config_data[config_count].value = strdup(value);
            config_count++;
        }
    }

    fclose(file);
    return 0; // Success
}

const char* config_get_string(const char* key, const char* default_value) {
    for (int i = 0; i < config_count; i++) {
        if (strcmp(config_data[i].key, key) == 0) {
            return config_data[i].value;
        }
    }
    return default_value;
}

int config_get_int(const char* key, int default_value) {
    const char* value_str = config_get_string(key, NULL);
    if (value_str) {
        return atoi(value_str);
    }
    return default_value;
}

void config_close() {
    for (int i = 0; i < config_count; i++) {
        free(config_data[i].key);
        free(config_data[i].value);
    }
    config_count = 0;
}
