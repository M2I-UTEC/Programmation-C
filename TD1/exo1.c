# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
void main(void){
	int f=fork();
	switch(f){
	case -1:
		perror("impossible de fourcher");
		exit(1);
	case 0:
		printf("Je suis le processe %d de pere %d\n",getpid(),getppid());
		system("ps -fl > psfils");
		break;
	default:
		wait(&f);
		printf("je suis le processus pere %d de fils %d\n",getpid(),f);
		system("ps -fl > pspere");
	}
}
