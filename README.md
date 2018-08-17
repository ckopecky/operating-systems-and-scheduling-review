# Operating Systems-and Scheduling Review

* [ ] Name some of the things an Operating System does

    - Manages memory allocation
    - Creates processes
    - Schedule the processes (Multilevel Feedback Queue)
    - intermediary between user and hardware. 


* [ ] Name some of the thins a Scheduler does.
    - schedules the processes
    - control time sharing
    - MLFQ is the right balance of fairness, priority, and time
* [ ] What types of Scheduler are there? Describe them.
    - MLFQ
    - Round Robin - Whatever is in the queue has to finish before something else comes in. Most fair of the group. 
    - Priority Queue takes the same amount of time. 


## practise with C commands
* [ ] fflush(stdout) [example](https://stackoverflow.com/questions/22901901/what-does-fflushstdin-do-in-c-programing)

```
#include <stdio.h>
#include <string.h>

int main () {

   char buff[1024];

   memset( buff, '\0', sizeof( buff ));

   fprintf(stdout, "Going to set full buffering on\n");
   setvbuf(stdout, buff, _IOFBF, 1024);

   fprintf(stdout, "This is tutorialspoint.com\n");
   fprintf(stdout, "This output will go into buff\n");
   fflush( stdout );

   fprintf(stdout, "and this will appear when programm\n");
   fprintf(stdout, "will come after sleeping 5 seconds\n");

   sleep(5);

   return(0);
}
```

* [ ] fgets [example](https://www.geeksforgeeks.org/fgets-gets-c-language/)

```
/ C program to illustrate
// gets()
#include <stdio.h>
#define MAX 15

int main()
{
    char buf[MAX];

    printf("Enter a string: ");
    gets(buf);
    printf("string is: %s\n", buf);

    return 0;
}
```
* [ ] feof(stdin) [example](https://www.tutorialspoint.com/c_standard_library/c_function_feof.htm)

```
#include <stdio.h>

int main () {
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   if(fp == NULL) {
      perror("Error in opening file");
      return(-1);
   }

   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) {
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);

   return(0);
}

```
* [ ] strok(str)[example](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)

```
#include <string.h>
#include <stdio.h>

int main () {
   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;

   /* get the first token */
   token = strtok(str, s);

   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );

      token = strtok(NULL, s);
   }

   return(0);
}
```
* [ ] strcmp(str1, str2)[example](https://www.geeksforgeeks.org/strcmp-in-c-cpp/)
```
// C program to illustrate
// strcmp() function
#include<stdio.h>
#include<string.h>

int main()
{

    char leftStr[] = "g f g";
    char rightStr[] = "g f g";

    // Using strcmp()
    int res = strcmp(leftStr, rightStr);

    if (res==0)
        printf("Strings are equal");
    else
        printf("Strings are unequal");

    printf("\nValue returned by strcmp() is:  %d" , res);
    return 0;
}
```
* [ ] fork()
* [ ] waitpid
* [ ] excvp(myargs[0], myargs)

```
This function could by used by a Unix shell to run a command and wait for the command to finish before going on. It returns the termination status of the command.
It uses function parsecmd(cmd,argv), which is not writtten here, but which breaks cmd at spaces and stores the pieces into argv, followed by a null pointer. For example, parsecmd("eat the banana", argv) will set argv as follows.

   argv[0] = "eat"
   argv[1] = "the"
   argv[2] = "banana"
   argv[3] = NULL
This example also presumes that there might be other child processes running in background, and that they might terminate while the shell is waiting for the current command to stop. A function called process_terminated is use to handle the termination of a background process. It is not written here.
int runcmd(char *cmd)
{
  char* argv[MAX_ARGS];
  pid_t child_pid;
  int child_status;

  parsecmd(cmd,argv);
  child_pid = fork();
  if(child_pid == 0) {
    /* This is done by the child process. */

    execvp(argv[0], argv);

    /* If execvp returns, it must have failed. */

    printf("Unknown command\n");
    exit(0);
  }
  else {
     /* This is run by the parent.  Wait for the child
        to terminate. */

     do {
       pid_t tpid = wait(&child_status);
       if(tpid != child_pid) process_terminated(tpid);
     } while(tpid != child_pid);

     return child_status;
  }
}
```
