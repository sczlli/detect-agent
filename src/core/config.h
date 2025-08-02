#ifndef CONFIG_H
#define CONFIG_H

// Loads the configuration from a file
int config_load(const char* filepath);

// Gets a string value for a given key. Returns default_value if not found.
const char* config_get_string(const char* key, const char* default_value);

// Gets an integer value for a given key. Returns default_value if not found.
int config_get_int(const char* key, int default_value);

// Frees any memory allocated by the config parser.
void config_close();

#endif // CONFIG_H







