#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include <malloc.h>

double wtime();
int getrand(int min, int max);

int main()
{
    int i = 0, n/*, key*/;
    struct bstree *tree, *node;
    printf("Enter n: ");
    scanf("%d", &n);
    char word[n][30];
    double t;
    FILE *stream;
    stream = fopen("bin/wapsort.txt", "r");
        if (stream == NULL) {
        printf("wapsort.txt cannot be opened");
        return 1;
    }
    fscanf(stream, "%s", word[0]);
    tree = bstree_create(word[0], i);
    for (i = 1; i < n; i++) {
        fscanf(stream, "%s", word[i]);
        bstree_add(tree, word[i], i);
    }
    //key = getrand(1, n-1);
    t = wtime();
    //node = bstree_lookup(tree, key);
    node = bstree_max(tree);
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
