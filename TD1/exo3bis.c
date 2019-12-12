# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int main(){
	int f = 0;
	for(int i=0; i<5; i++) {
		if(f != 0) {
			f = fork();
		} else {
			break;
		}
	}
	while(1){}
}

