#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler (int numero){
	if(numero == SIGUSR2){
		kill(getpid(), SIGUSR2);
	} else {
		kill(getpid(), SIGKILL);
	}

}

int main (void)
{
        int i;
	int f = fork();
	if(f != 0){
		i = fork();
		if(i == 0) {
			signal(SIGUSR2, handler);
		} else {
			kill(i, SIGUSR1);
		}
	} else {
		signal(SIGUSR2, handler);
		wait(NULL);
	}
}
