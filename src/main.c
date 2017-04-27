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
    int i = 0, n, key, summ = 0, collision[n];
    struct listnode *hashtab[HASH_SIZE], *node;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        collision[i] = 0;
    }
    char word[n][15];
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
        collision[hashtab_hash(word[i], strlen(word[i]))]++;
    }

    for (i = 0; i < n; i++) {
        if (collision[i] > 0) {
            collision[i]--;
        }
        summ += collision[i];
    }

    key = getrand(1, n - 1);
    t = wtime();
    node = hashtab_lookup(hashtab, word[key]);
    t = wtime() - t;
    printf("%d %.6f\n", n, t);
    printf("Collisions: %d\n", summ);
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
