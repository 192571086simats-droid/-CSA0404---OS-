#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char text[100];

    fp = fopen("sample.txt", "w");

    if (fp == NULL) {
        printf("File creation failed\n");
        return 1;
    }

    fprintf(fp, "Hello UNIX File");
    fclose(fp);

    fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        printf("File opening failed\n");
        return 1;
    }

    fgets(text, sizeof(text), fp);
    printf("File content: %s\n", text);

    fclose(fp);

    printf("File management operations completed successfully\n");

    return 0;
}
