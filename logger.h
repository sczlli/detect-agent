#ifndef LOGGER_H
#define LOGGER_H


//Definizione dei livelli di log 
// DEBUG, INFO , WARN , ERROR , FATAL


typedef enum {
   LOG_LEVEL_DEBUG, // Messaggi dettagliati per il debugging 
   LOG_LEVEL_INFO,  // Messaggi informativi sul normale funzionamento
   LOG_LEVEL_WARN, // Avvisi su situazioni potenzialmente problematiche 
   LOG_LEVEL_ERROR  // Errori che impediscono delle funzionalità ma non bloccano l'agente
   LOG_LEVEL_FATAL  //Errori critici che causano l'interruzione dell'agente 
}LogLevel;

// funzioni pubbliche del logger
// ------------------------------


/**
*  @brief Inizializza il sistema di logging .
*
*  Questa funzione deve essere chiamata una volta all'inzio dell'applicazione
*  per configurare il livello minimo di log e il percorso del file di log.
*  Se log_file_path è NULL ,i log verrano scritti solo su stdout/stderr.
*
*  @param level Il livello minimo di log da registrare.
*  @param log_file_path il percorso del file dove scrivere i log. Se NULL, logga solo in stdout.
*/
void logger_init(LogLevel level, const char* log_file_path);

/**	
* 
*  @brief funzione principale per la registrazione dei messaggi di log 
*
*  Questa funzione è il cuore del logger , NON dovrebbe essere chiamato direttamente
*  Ma tramite macro LOG_DEBUG, LOG_INFO, LOG_WARN ecc. che auggiungono automaticamente
*  le informazioni sul file sorgente e il numero di riga.
*
*  @param level -> Il livello di severità del messaggio
*  @param file  -> Il nome del file sorgente da cui proviene la chiamata (automatico con le macro) 
*  @param line  -> Il numero di riga nel file sorgente (automatico con le macro) 
*  @param format -> la stringa di formato come printf
*  @param ... Argomenti variabili per la stringa di formato 
*/
void logger_log (LogLevel level, const char* file , int line, const char* format, ...);


/**
*
*  @brief chiude il sistema di logging.
*
*  Questa funzionw deve essere chiamata alla fine dell'applicazione per 
*  Chiudere correttamente i file
*/
void logger_close();

// Macro per semplificare l'utilizzo del logger
// --------------------------------------------
// Queste macro sono il modo raccomandato per utilizzare il logger.
// Includono automaticamente  __FILE__ (nome del file sorgente) e __LINE__ (numero di riga).
// Rendendo i log molto più utili per il debugging.
#define LOG_DEBUG(format, ...) logger_log(LOG_LEVEL_DEBUG, --FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_INFO(format, ...)  logger_log(LOG_LEVEL_INFO,  --FILE__, __LINE__,  format, ##__VA_ARGS__)
#define LOG_WARN(format, ...)  logger_log(LOG_LEVEL_WARN,  --FILE__, __LINE__,  format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) logger_log(LOG_LEVEL_ERROR, --FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...) logger_log(LOG_LEVEL_FATAL, --FILE__, __LINE__, format, ##__VA_ARGS__)

#endif // LOGGER_H












