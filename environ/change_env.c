#include <stdlib.h>
#include <stdio.h>
#include "apue.h"

void change_env(const char*, const char*);

int main() {
    char * v1 = "a=aaaaa";
    char * v2 = "a=ccc";
    char * v3 = "a=bbbbbbbbbb";

    char * name = "a";
    char * value;

    value = getenv(name);
    if (value == NULL) {
        printf("a=NULL\n");
    } else {
        printf("a=address: %d value: %s\n", (int) value, value);
    }

    if (putenv(v1) != 0) {
        err_sys("Error setting env var a");
    }
    value = getenv(name);
    if (value == NULL) {
        printf("a=NULL\n");
    } else {
        printf("a=address: %d value: %s\n", (int) value, value);
    }
    
    if (putenv(v2) != 0) {
        err_sys("Error setting env var a");
    }
    value = getenv(name);
    if (value == NULL) {
        printf("a=NULL\n");
    } else {
        printf("a=address: %d value: %s\n", (int) value, value);
    }

    if (putenv(v3) != 0) {
        err_sys("Error setting env var a");
    }
    value = getenv(name);
    if (value == NULL) {
        printf("a=NULL\n");
    } else {
        printf("a=address: %d value: %s\n", (int) value, value);
    }
    
    return (0);
}

void change_env(const char* name, const char* value) {
     
}
