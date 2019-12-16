#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int pid1, pid2;

void handler (int numero){
	printf("%d", numero);
	if(numero == SIGUSR1){
		printf("Killing %d", getpid());
		kill(pid1, SIGUSR2);
	} else {
		printf("Killing Sub %d", getpid());
		kill(pid1,SIGKILL);
	}

}

int main (void)
{
	pid1 = fork();
	if(pid1 == -1) {
		printf("Error\n");
		exit(-1);
	} else if(pid1 == 0) {
		signal(SIGUSR2, handler);
		pause();
	} else {
		pid2 = fork();
		if(pid2 == -1){
			printf("Error\n");
			exit(-1);
		} else if(pid2 == 0){
			signal(SIGUSR1, handler);
			pause();
		} else {
			sleep(2);
			kill(pid2, SIGUSR1);
		}
	}
}
