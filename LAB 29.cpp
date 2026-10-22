#include <stdio.h>
#include <pthread.h>

int buffer = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    pthread_mutex_lock(&lock);
    buffer = 100;
    printf("Producer produced: %d\n", buffer);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *consumer(void *arg) {
    pthread_mutex_lock(&lock);
    printf("Consumer consumed: %d\n", buffer);
    buffer = 0;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t p, c;

    pthread_create(&p, NULL, producer, NULL);
    pthread_join(p, NULL);

    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
