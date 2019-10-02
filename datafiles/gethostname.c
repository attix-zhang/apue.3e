#include "apue.h"
#include <unistd.h>
#include <limits.h>

int main() {
    char* name;

    name = (char*) malloc(sizeof(int) * 255);

    if (gethostname(name, 255) != 0) {
        err_sys("gethostname error.");
    }
    printf("Hostname: %s\n", name);
    return (0);
}
