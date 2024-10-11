#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log.h"
#include "error.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    // Обработка аргументов
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            listUsers();
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            listProcesses();
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printUsage();
            return 0;
        } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) {
            if (i + 1 < argc) {
                redirectOutputToLog(argv[++i]);
            } else {
                fprintf(stderr, "No path provided for log.\n");
            }
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) {
            if (i + 1 < argc) {
                redirectErrorsToLog(argv[++i]);
            } else {
                fprintf(stderr, "No path provided for errors.\n");
            }
        } else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
            printUsage();
            return 1;
        }
    }

    return 0;
}
