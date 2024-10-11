#include <stdio.h>

void printUsage() {
    printf("Usage:\n"
           "  -u, --users       List users and their home directories.\n"
           "  -p, --processes   List running processes sorted by PID.\n"
           "  -h, --help        Show this help message.\n"
           "  -l PATH, --log PATH Redirect output to the specified file.\n"
           "  -e PATH, --errors PATH Redirect error output to the specified file.\n");
}
