#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
	struct tm *tmp;
	char* buf = "08:01:07 PM, Mon Sep 29, 2019";
    char* buf1 = "s08:01:07 PM, Mon Sep 29, 2019";

    tmp = (struct tm *) malloc(sizeof(struct tm));
    if (strptime(buf, "%r, %a %b %d, %Y", tmp) == NULL) {
		printf("Unable to parse given time: %s\n", buf);
    } else {
        printf("tm_sec: %d\n", tmp->tm_sec);
        printf("tm_min: %d\n", tmp->tm_min);
        printf("tm_hour: %d\n", tmp->tm_hour);
        printf("tm_mday: %d\n", tmp->tm_mday);
        printf("tm_mon: %d\n", tmp->tm_mon);
        printf("tm_year: %d\n", tmp->tm_year);
        printf("tm_wday: %d\n", tmp->tm_wday);
        printf("tm_yday: %d\n", tmp->tm_yday);
        printf("tm_isdst: %d\n", tmp->tm_isdst);
    }

    if (strptime(buf1, "%r, %a %b %d, %Y", tmp) == NULL) {
		printf("Unable to parse given time: %s\n", buf1);
    } else {
        printf("tm_sec: %d\n", tmp->tm_sec);
        printf("tm_min: %d\n", tmp->tm_min);
        printf("tm_hour: %d\n", tmp->tm_hour);
        printf("tm_mday: %d\n", tmp->tm_mday);
        printf("tm_mon: %d\n", tmp->tm_mon);
        printf("tm_year: %d\n", tmp->tm_year);
        printf("tm_wday: %d\n", tmp->tm_wday);
        printf("tm_yday: %d\n", tmp->tm_yday);
        printf("tm_isdst: %d\n", tmp->tm_isdst);
    }
    free(tmp);

	exit(0);
}
