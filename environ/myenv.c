#include "apue.h"

extern char ** environ;
int main(int arc, char** argv) {
    char ** envp;
    envp = environ;
    while(*envp != NULL) {
        printf("%s\n", *envp);
        envp++;
    }
    return(0);
}
