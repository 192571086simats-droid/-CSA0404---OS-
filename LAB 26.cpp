#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("File creation failed\n");
        return 1;
    }

    fprintf(fp, "Operating Systems Lab");
    fclose(fp);
    printf("File created successfully\n");

    fp = fopen("student.txt", "r");
    if (fp == NULL) return 1;

    fgets(text, sizeof(text), fp);
    printf("File content: %s\n", text);
    fclose(fp);

    fp = fopen("student.txt", "a");
    if (fp == NULL) return 1;

    fprintf(fp, "\nFile management operations");
    fclose(fp);
    printf("Data appended successfully\n");

    return 0;
}
