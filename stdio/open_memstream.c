// gcc -o open_memstream.o open_memstream.c -I ../include/ -L ../lib/ -lapue
#include "apue.h"

int main() {
    int i;
    size_t size;
    char *buf;

    FILE *fp;

    if ((fp = open_memstream(&buf, &size)) == NULL) {
        err_sys("open_memstream failed.");
    }

    for (i = 0; i < 10; i++) {
        fprintf(fp, "hello, world");
        printf("current buf address: %p, buf size: %ld, buf content:%s\n", buf, (long)strlen(buf), buf);
        fflush(fp);
        printf("fflush buf address: %p, buf size: %ld, buf content:%s\n", buf, (long)strlen(buf), buf);
    }
    return (0);
}
