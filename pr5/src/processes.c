#include <stdio.h>
#include <stdlib.h>

void listProcesses() {
    FILE *fp;
    char path[1035];

    // Открытие командной строки для получения процессов
    fp = popen("ps -e --format pid,cmd --sort pid", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    while (fgets(path, sizeof(path) - 1, fp) != NULL) {
        printf("%s", path);
    }
    pclose(fp);
}
