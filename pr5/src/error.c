#include <stdio.h>
#define STDERR_FILENO 1

void redirectErrorsToLog(char *path) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        fprintf(stderr, "Cannot open error file: %s\n", path);
        return;
    }
    dup2(fileno(file), STDERR_FILENO); // Перенаправление stderr
    fclose(file);
}
