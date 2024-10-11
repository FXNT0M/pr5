#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <dirent.h>

void listUsers() {
    struct passwd *pw;
    setpwent(); // Инициализация работы с passwd

    while ((pw = getpwent()) != NULL) {
        printf("%s: %s\n", pw->pw_name, pw->pw_dir);
    }
    endpwent();
}
