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
    struct bstree *tree/*, *node*/;
    char *word/*, *w*/;
    word = malloc(sizeof(char)*90);
    int i = 0, n;
    double t;
    FILE *stream;
    stream = fopen("wap.txt", "r");
    scanf("%d", &n);
    fgets(word, 90, stream);
    tree = bstree_create(word, i);
    for (i++; i < n - 1; i++) {
        fgets(word, 90, stream);
        bstree_add(tree, word, i);
        if ((i % n) == 0) {
            //w = word[getrand(0, i-1)];
            t = wtime();
            //node = bstree_lookup(tree, w);
            t = wtime() - t;
            printf("n = %d, time = %.6f\n", i-1, t);
        }
    }
    free(word);
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