# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void main(void) {
	int f, i;
	for (i = 0; i<10; i++) {
		f = fork();
		if (f == 0) {
			break;
		}
	}
	if(f == 0) {
		for (int o = 0; o < 10; o++) {
			printf("%d\n", i);
		}
	}
}
