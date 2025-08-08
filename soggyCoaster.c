#include "utility.h"

int main()
{
    char *fileName = malloc(sizeof(char) * 256);

    printf("Enter the file name: ");
    scanf("%s", fileName);
    fileReader(fileName);
    free(fileName);
    printData();
    freeAllList();

    return err;
}
