#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd[2];  // file descriptor: fd[0] for read and fd[1] for write
    pid_t pid;
    char buffer[100];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    pid = fork();  // create a child process
    printf("pid: %d\n",pid);
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid > 0) { // Parent process
        close(fd[0]); // Close unused read end
        
        const char* message = "Hello from parent!";
        printf("sending from parent\n");
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    else { // Child process
        close(fd[1]); // Close unused write end
        
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}