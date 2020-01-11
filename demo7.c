#include <stdio.h>
#include <pthread.h>

void *thread1(void *);
void *thread2(void *);

int main()
{
    pthread_t id1, id2;
    pthread_create(&id1, NULL, thread1, NULL);
    pthread_create(&id2, NULL, thread2, NULL);

    printf("Hello world!\n");

    pthread_join(id2, NULL);


    return 0;
}