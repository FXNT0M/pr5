#include <stdio.h>
#define STDOUT_FILENO 1

void redirectOutputToLog(char *path) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        fprintf(stderr, "Cannot open log file: %s\n", path);
        return;
    }
    dup2(fileno(file), STDOUT_FILENO); // Перенаправление stdout
    fclose(file);
}
