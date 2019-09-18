// gcc -o bad_tempfile.o bad_tempfile.c -I ../../include -L ../../lib/ -lapue
// How to execute: $(head -n1 bad_tempfile.c | cut -c 4-)
#include "apue.h"
#include <errno.h>

void make_temp(char *);

int main() {
    char good_template[] = "/tmp/dirXXXXXX";
    char *bad_template = "/tmp/dir1XXXXXX";

    printf("trying to create first temp file...\n");
    make_temp(good_template);
    printf("trying to create second temp file...\n");
    make_temp(bad_template);
    exit(0);
}

void make_temp(char * template) {
    int fd;
    struct stat sbuf;

    if ((fd = mkstemp(template)) < 0) {
        err_sys("can't create temp file");
    }
    close(fd);
    if (stat(template, &sbuf) < 0) {
        if (errno == ENOENT) {
            printf("File [%s] doesn't exist\n", template);
        } else {
            err_sys("stat failed.\n");
        }
    } else {
        printf("File [%s] exists.\n", template);
        unlink(template);
    }
}
