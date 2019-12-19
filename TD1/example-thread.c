// ¨Pour compiler:
// gcc exemple_thread.c -o thread -lpthread

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>

/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);

- Crée un nouveau thread et l'enregistre dans thread.
- Le nouveau thread s'exécute en invoquant la fonction start_routine()
- arg est passé comme seul argument à start_routine
- Retourne 0 en cas de succès; une valeur différente de 0 dans le cas contraire et le contenu de thread sera indéfini
- Les autres arguments doivent être mis à NULL pour l'instant

*/

int shared_val = 0 ; 

typedef struct ARGS_THREAD {
	int id ;

}args_thread ;


void * routine(void *arg){

	args_thread * arg1  = (args_thread *) arg ;
	shared_val++ ;
	printf("Le thread : %d \n",arg1->id);
	printf("Shared val %d\n",shared_val);
	
	pthread_exit(NULL); // Permet de quitter correctement le thread et de renvoyer une valeur a pthread_join

}


int main(int argc, char * argv[])
{
	args_thread  arg1  ;
	pthread_t thread ;

	arg1.id = 666 ;
	if(pthread_create(&thread, NULL, routine, & arg1) != 0){

			perror("Un problème est survenu lors de l'appel a pthread_create\n");

			return EXIT_FAILURE;

	}	
		
	if(pthread_join(thread,NULL) != 0)  // attendre la fin du thread
		
		{
			perror("Un problème est survenu lors de l'appel a pthread_join\n");
			return EXIT_FAILURE;
		}

	
		
	printf("Au revoir... \n");
	return EXIT_SUCCESS;
}


