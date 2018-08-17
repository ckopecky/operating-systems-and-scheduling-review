#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{   
    char *args[3]; //this tells us that there are 3 pointers in the array
    while(1){
        int rc = fork();
        if (rc < 0){
            fprintf(stderr, "Fork Failed\n");
            exit(1);
        } else if (rc==0) {
            //child
            printf("Hello Child Here\n");
            args[0] = strdup("Wc");
            args[1] = strdup("file.txt");
            args[2] = NULL;
            
            execvp(args[0], args);
            printf("This is should not be seen!");
        } else {
            //parent
            int wc = waitpid(rc, NULL, 0);
            printf("Hello I am the parent\n");

        }
        sleep(5);

    }
    return 0;
}
