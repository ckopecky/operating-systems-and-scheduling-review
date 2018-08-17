#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    FILE *fp;
    char c;
    fp = fopen("file.txt", "r");
    if(fp == NULL)
    {
        perror("error in opening file");
        return -1;
    }

    while(1) {
        c = fgetc(fp);
        if(feof(fp)) {
            printf("\n");
            break;
        }
        printf("%c", c);

    }
    fclose(fp);
    return 0;
}