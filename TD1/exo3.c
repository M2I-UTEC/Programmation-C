# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int count = 0;

void sigint(int sig){
	++count;
	if(count == 5) {
		exit(0);
	}
}

int main(){
	signal(SIGINT, sigint);
	while(1){}
}

