#include <stdio.h>
#include <io.h>

int main() {
    struct _finddata_t file;
    intptr_t handle;

    handle = _findfirst("*", &file);

    if (handle == -1) {
        printf("No files found\n");
        return 0;
    }

    printf("Files in current directory:\n");

    do {
        printf("%s\n", file.name);
    } while (_findnext(handle, &file) == 0);

    _findclose(handle);
    return 0;
}
