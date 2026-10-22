#include <stdio.h>

int main() {
    int block[10], process[10], alloc[10];
    int nb, np, i, j, best;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for (i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        alloc[i] = -1;
    }

    for (i = 0; i < np; i++) {
        best = -1;
        for (j = 0; j < nb; j++) {
            if (block[j] >= process[i] &&
                (best == -1 || block[j] < block[best]))
                best = j;
        }

        if (best != -1) {
            alloc[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < np; i++) {
        printf("%d\t%d\t", i + 1, process[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
