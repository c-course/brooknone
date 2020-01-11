#include <pthread.h>
#include <stdio.h>

void *thread1(void *p)
{
    int i = 0;
    while (i < 5) {
        printf("Bong bong bong!\n");
        sleep(1);
        i++;
        if (2 == i)
            pthread_exit(thread1);
    }
}

void *thread2(void *p)
{
    int j = 0;
    while (j < 3) {
        sleep(1);
        printf("I am coming!\n");
        j++;
    }
    if (3 == j) {
        sleep(1);
        printf("Bye!\n");
    }
}
