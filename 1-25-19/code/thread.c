#include <pthread.h>

void* myfunc(void* ptr) {
    int i = *((int *) ptr);
    printf("%d ", i); 
    return NULL;
}


int main() {
    int i, arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    pthread_t tid;
    for(i =0; i < 10; i++) {
        pthread_create(&tid, NULL, myfunc, &arr[i]);
    }   
    pthread_exit(NULL);
}


