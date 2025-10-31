#ifndef TICKERTAPE_H
#define TICKERTAPE_H

#include <stdio.h>
#include <stdarg.h>

// Global handle, visible project-wide
extern FILE *tickertape_file;

// Initialize the log
void tickertape_init(const char *filename);

// Write formatted text to the log (like printf)
void tickertape_log(const char *fmt, ...);

// Close the log
void tickertape_close(void);

#endif

