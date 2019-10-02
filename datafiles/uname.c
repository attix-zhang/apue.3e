#include "apue.h"
#include <sys/utsname.h>

int main() {
    struct utsname info;

    if (uname(&info) == -1) {
        err_sys("uname error.");
    }

    printf("Operating System:\t%s\n", info.sysname);
    printf("Node name:\t%s\n", info.nodename);
    printf("Release:\t%s\n", info.release);
    printf("Version:\t%s\n", info.version);
    printf("Machine::\t%s\n", info.machine);

    return (0);
}
