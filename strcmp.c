#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
    char leftStr[] = "g f g";
    char rightStr[] = "g f g";

    char leftOne[] = "apple";
    char leftTwo[] = "aapl";
    int res = strcmp(leftStr, rightStr);
    int res2 = strcmp(leftOne, leftTwo);
    //can't use if else for strcmp because it would only point tp
    //the first character's character address.
    if(res == 0 && res2 == 0)
    {
        printf("Strings are equal\n");
    }
    else{
        printf("Strings are not equal\n");
    }
}