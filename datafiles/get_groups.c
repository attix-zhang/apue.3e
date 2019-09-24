// gcc -o get_groups.o get_groups.c -I ../include/ -L ../lib/ -lapue
// $(head -n1 get_groups.c | cut -c 4-)
#include "apue.h"
#include <unistd.h>
#include <grp.h>

void print_group_name(gid_t);

int main() {
    int num_group;
    int i;
    gid_t* group_list;

    if ((num_group = getgroups(0, NULL)) == -1) {
        err_sys("getgroups error.");
    }
    group_list = (gid_t *)malloc(sizeof(gid_t) * num_group);
    if (getgroups(num_group, group_list) == -1) {
        err_sys("getgroups error.");
    }
    for (i = 0; i < num_group; i++) {
        print_group_name(group_list[i]);
    }
    return (0);
}

void print_group_name(gid_t gid) {
    struct group * grp;
    if((grp = getgrgid(gid)) == NULL) {
        err_sys("getgrgid error.");
    }
    printf("Supplementary group: name: %s, gid: %d\n", grp->gr_name, grp->gr_gid);
}
