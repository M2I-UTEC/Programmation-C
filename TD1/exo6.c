#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
    int tube[2];
    int tube2[2];
    char buffer2[256];
    char buffer[256];
    int i;
    int pid = fork();
    fprintf(stdout, "Creation tube\n");
    if (pipe(tube) != 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if (pipe(tube2) != 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    switch (pid) {
        case 0 :
            close(tube[1]);
            close(tube2[0]);
            read(tube[0], buffer, 256);
            printf("fils : %s",buffer);
            char reponse[256] = "call du fils";
            write(tube2[1], reponse, 256);
            break;
        default :
            close(tube[0]);
            close(tube2[1]);
            char reponse2[256] = "call du père";
            write(tube2[0], reponse2, 256);
		sleep(2);
            read(tube[1], buffer, 256);
            printf("Pere : %s",buffer2);
            break;
    }
    return EXIT_SUCCESS;
}
