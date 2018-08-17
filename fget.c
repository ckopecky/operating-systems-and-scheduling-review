#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 64

int main(void)
{
    char buff[MAX];
    printf("Enter some text: ");
    fgets(buff, MAX, stdin);
    printf("You entered %s\n", buff);
    return 0;
}