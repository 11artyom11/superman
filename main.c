#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("[ERROR] Please provide the path of the script\n");
        return 1;
    }
    char* path;
    path = argv[1];
    char result[256];
    int fd[2];
    int childpid = 0;

    printf("This is the script I am going to run %s\n", path);
    pipe(fd);
    if ( (childpid = fork   () ) == -1){
        fprintf(stderr, "FORK failed");
        return 1;
    } else if( childpid == 0) {
        close(1);
        dup2(fd[1], 1);
        close(fd[0]);
        execlp("/bin/sh","-c",path,NULL);
    }
    wait(NULL);
    read(fd[0], result, 256);
    printf("%s\n",result);
}