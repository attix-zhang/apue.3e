// gcc -o fmemopen.o fmemopen.c -I ../../include/ -L ../../lib/ -lapue
// $(head -n1 fmemopen.c | cur -c 4-)
#include "apue.h"

#define BSZ 48

void set_buffer(char *, char);

int main() {
    FILE *fp;
    char buf[BSZ];

    set_buffer(buf, 'a');

    if ((fp = fmemopen(buf, BSZ, "w+")) == NULL) {
        err_sys("fmemopen failed.");
    }

    printf("initial buffer contents: %s\n", buf);
    fprintf(fp, "hello, world");
    printf("before fflush: %s\n", buf);
    fflush(fp);
    printf("after fflush: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    set_buffer(buf, 'b');
    fprintf(fp, "hello world");
    printf("before fseek: %s\n", buf);
    fseek(fp, 0, SEEK_SET);
    printf("after fseek: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));
    
    set_buffer(buf, 'c');
    fprintf(fp, "hello world");
    fclose(fp);
    printf("after close: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    return (0);
}

void set_buffer(char * buf, char c) {
    memset(buf, c, BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
}

/*
chapter5 git:(chapter5) ✗ ./fmemopen.o
initial buffer contents:
before fflush: hello, world
after fflush: hello, world
len of string in buf = 12
before fseek: bbbbbbbbbbbbhello world
after fseek: bbbbbbbbbbbbhello world
len of string in buf = 23
after close: hello world
len of string in buf = 11
 */
