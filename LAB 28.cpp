#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], word[50], line[300];
    int found = 0;

    printf("Enter filename: ");
    scanf("%99s", filename);

    printf("Enter word to search: ");
    scanf("%49s", word);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word) != NULL) {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found)
        printf("Word not found\n");

    fclose(fp);
    return 0;
}
