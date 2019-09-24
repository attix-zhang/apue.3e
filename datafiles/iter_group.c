// gcc -o iter_group.o iter_group.c -I ../include/ -L ../lib/ -lapue
// $(head -n1 iter_group.c | cut -c 4-)
#include "apue.h"
#include <grp.h>


int main() {
    struct group* grp;
    char **all_members;
    setgrent();

    while((grp = getgrent()) != NULL) {
       all_members = grp->gr_mem;
       printf("Group Name: %s Gid: %d Members:\n", grp->gr_name, grp->gr_gid);
       while (*all_members) {
           printf("\tm:%s\n", *all_members);
           all_members++;
       }
    }
    endgrent();
    return (0);
}
