#include <stdio.h>
#include <windows.h>

int main()
{
    HANDLE hMap;
    char *sharedMemory;

    hMap = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "SharedMemory");

    if (hMap == NULL)
    {
        printf("Shared memory creation failed.");
        return 1;
    }

    sharedMemory = (char *)MapViewOfFile(
        hMap,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        1024);

    if (sharedMemory == NULL)
    {
        printf("Unable to access shared memory.");
        CloseHandle(hMap);
        return 1;
    }

    printf("Enter message: ");
    gets(sharedMemory);

    printf("\nMessage stored in shared memory:\n");
    printf("%s\n", sharedMemory);

    UnmapViewOfFile(sharedMemory);
    CloseHandle(hMap);

    return 0;
}
