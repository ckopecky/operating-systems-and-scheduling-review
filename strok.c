#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char str[] = "Geeks-for-Geeks";

    // Returns first token 
    char *token = strtok(str, "-");
    // Keep printing tokens while one of the
    // delimiters present in str[]. Delimiter is the char you want to split on.
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }

    return 0;
}