#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include <stdint.h>

double wtime();
int getrand(int min, int max);

int main()
{
    int i = 0, n, summ = 0;
    struct listnode *hashtab[HASH_SIZE], *node;
    printf("Enter n: ");
    scanf("%d", &n);
    int coll[HASH_SIZE];
    for (i = 0; i < HASH_SIZE; i++) {
        coll[i] = 0;
    }
    char word[n][15];
    FILE *stream;
    stream = fopen("bin/wap.txt", "r");
    if (stream == NULL) {
        printf("wap.txt cannot be opened");
        return 1;
    }

    hashtab_init(hashtab);
    for (i = 1; i < n; i++) {
        fscanf(stream, "%s", word[i]);
        hashtab_add(hashtab, word[i], i);
        coll[hashtab_hash(word[i], strlen(word[i]) - 1)]++;
    }

    for (i = 0; i < HASH_SIZE; i++) {
        if (coll[i] > 0) {
            coll[i]--;
        }
        summ += coll[i];
    }

    int key = getrand(1, n - 1);
    double t = wtime();
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
