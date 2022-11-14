#include <unistd.h>
#include <stdio.h>
#include <limits.h>

char* getPath() {

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        errx(1, "Path is null");
    }

    return cwd;
}
