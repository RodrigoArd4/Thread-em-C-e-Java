#include <pthread.h>
#include <stdio.h>

/* Imprime x's */
void* print_xs(void* unused)
{
    while (1)
        fputc('x', stderr);
    return NULL;
}

/* Imprime a's */
void* print_as(void* unused)
{
    while (1)
        fputc('a', stderr);
    return NULL;
}

/* Imprime b's */
void* print_bs(void* unused)
{
    while (1)
        fputc('b', stderr);
    return NULL;
}

int main()
{
    pthread_t thread_id_x;
    pthread_t thread_id_a;
    pthread_t thread_id_b;

    /* Thread que imprime x */
    pthread_create(&thread_id_x, NULL, &print_xs, NULL);

    /* Thread que imprime a */
    pthread_create(&thread_id_a, NULL, &print_as, NULL);

    /* Thread que imprime b */
    pthread_create(&thread_id_b, NULL, &print_bs, NULL);

    /* A thread principal imprime o's continuamente */
    while (1)
        fputc('o', stderr);

    return 0;
}
