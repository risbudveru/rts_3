#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

struct args {
    int real, img;
};

struct comp_numx {
    struct args arg1, arg2;
};

void *runner(void *arguments) {

    struct args *arg = arguments;
    printf("%d\n", arg->real);
    printf("%d\n", arg->img);
    pthread_exit(NULL);
    return NULL;
}

void thread_mgmt(int n) {
    int i;
    struct args arg_array[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arg_array[i].real);
        scanf("%d", &arg_array[i].img);
    }
    pthread_t threads[n];
    for(i = 0; i < n; i++)
        pthread_create(&threads[i], NULL, &runner, (void *)&arg_array[i]);
    for(i = 0; i < n; i++)
        pthread_join(threads[i], NULL);
    
}

int main() {
    int n = 0;
    printf("Enter number of real numbers to multiply:\n");
    scanf("%d", &n);
    thread_mgmt(n);   
    return 0;
}
