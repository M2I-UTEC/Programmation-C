#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void gestionnaire (int numero)
{
	fprintf(stdout, "\n%ld a recu le signal %d (%s)\n", 
	        (long) getpid(), numero, sys_siglist[numero]);
}

int main (void)
{
	int i;

	for (i = 1; i < NSIG; i ++) // les codes des signaux sont compris entre 1 et NSIG
		if (signal(i, gestionnaire) == SIG_ERR)
			fprintf(stderr, "Signal %d non capture\n", i);

	while (1)
		pause();
}

/************************************
// Liste des signaux disponibles   
************************************/

// SIGINT  2 Term Interruption depuis le clavier.
// SIGQUIT  3 Core Demande « Quitter » depuis le clavier.
// SIGILL  4 Core Instruction illégale.
// SIGABRT  6 Core Signal d'arrêt depuis abort(3).
// SIGFPE  8 Core Erreur mathématique virgule flottante.
// SIGKILL  9 Term Signal « KILL ».
// SIGSEGV 11 Core Référence mémoire invalide.
// SIGPIPE 13 Term Écriture dans un tube sans lecteur.
// SIGALRM 14 Term Temporisation alarm(2) écoulée.
// SIGTERM 15 Term Signal de fin.
// SIGUSR1 30,10,16 Term Signal utilisateur 1.
// SIGUSR2 31,12,17 Term Signal utilisateur 2.
// SIGCHLD 20,17,18 Ign Fils arrêté ou terminé.
// SIGCONT 19,18,25 Cont Continuer si arrêté.
// SIGSTOP 17,19,23 Stop Arrêt du processus.
// SIGTSTP 18,20,24 Stop Stop invoqué depuis tty. 
// SIGTTIN 21,21,26 Stop Lecture sur tty en arrière-plan.
// SIGTTOU 22,22,27 Stop Écriture sur tty en arrière-plan.
// SIGPIPE (13) : écriture dans un tube sans lecteur

// Term
	// Par défaut, terminer le processus. 

// Ign
	// Par défaut, ignorer le signal. 

// Core
	// Par défaut, terminer le processus et créer un fichier 
	
// Stop
	// Par défaut, arrêter le processus. 
	
// Cont
	// Par défaut, continuer le processus s'il est arrêté.

	
// signaux relatifs à la fin de processus :
	// – SIGCHLD (17) : mort du fils
	// – SIGKILL (9) : signal de terminaison
 
// Les signaux SIGKILL et SIGSTOP ne peuvent être ni capturés ni ignorés. 

/*******************************
// Attendre un signal
********************************/
	//– int pause();

