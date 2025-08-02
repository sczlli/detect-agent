#include "config.h"
#include <stdio.h> 



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
