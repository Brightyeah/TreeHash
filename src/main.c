#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>

double wtime();
int getrand(int min, int max);

int main()
{
    int i = 0, n, key;
    struct listnode *hashtab[HASH_SIZE], *node;
    printf("Enter n: ");
    scanf("%d", &n);
    char word[n][30];
    double t;
    FILE *stream;
    stream = fopen("bin/wap.txt", "r");
        if (stream == NULL) {
        printf("wap.txt cannot be opened");
        return 1;
    }
    hashtab_init(hashtab);
    for (i = 0; i < n; i++) {
        fscanf(stream, "%s", word[i]);
        hashtab_add(hashtab, word[i], i);
    }
    key = getrand(1, i - 1);
    t = wtime();
    node = hashtab_lookup(hashtab, word[key]);
    t = wtime() - t;
    printf("%d %.6f\n", n, t);
    fclose(stream);
    return 0;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
} 