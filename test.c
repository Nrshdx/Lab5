#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask(){
    char name[30];
    printf(“Enter name : ”);
    fgets(“name, sizeof(name), stdin”);
    printf(“\nMy name is “);
    puts(name);
    printf(“My child process => PPID=%d\n\n”, getppid(), getpid());
}

Void parentTask(){
    printf(“Parent process => PID==%d\n”, getpid());
    printf(“All child process is finnised!\n”);
    printf(“Job is done\n”);
}

Void waiting(){
      printf(“waiting for child process to finnish…”);
      wait(NULL);
      printf(“child process finnished”);
      printf(“_______________________________________________________________”);
}

Int main(void){
    for(int i = 1; i < 5; i++){
	    pid_t pid = fork();
	    if(pid == 0){
	        childTask();
	    }else if(i == 4){
	        waiting();
	        parentTask();
                }else parentTask();
    }
    return EXIT_SUCCESS;
}
