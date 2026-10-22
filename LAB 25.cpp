
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>

int main() {
    FILE *fp;
    struct _stat st;
    struct _finddata_t file;
    intptr_t handle;
    char ch;

    fp = fopen("sample.txt", "w+");

    if (fp == NULL) {
        printf("File error\n");
        return 1;
    }

    fputs("HELLO", fp);

    fseek(fp, 0, SEEK_SET);
    ch = fgetc(fp);
    printf("First character: %c\n", ch);

    fclose(fp);

    if (_stat("sample.txt", &st) == 0)
        printf("File size: %ld bytes\n", (long)st.st_size);

    printf("\nDirectory files:\n");

    handle = _findfirst("*", &file);

    if (handle != -1) {
        do {
            printf("%s\n", file.name);
        } while (_findnext(handle, &file) == 0);

        _findclose(handle);
    }

    return 0;
}

