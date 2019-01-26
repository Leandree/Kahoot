#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

#define TAILLE_MESSAGE 100

char* nomJoueur;

int creationPipe(){
	int entreeTube;

    char path[40] = "/tmp/kahoot/";
	strcat(path,nomJoueur);

	char mkdirCommande[50] = "mkdir -p ";
	strcat(mkdirCommande,path);
	system(mkdirCommande);

	char nomTube = "";
	strcat(path,"/reponse");

	char chaineAEcrire[TAILLE_MESSAGE] = "Bonjour";

	if(mkfifo(nomTube, 0644) != 0) 
	{
		fprintf(stderr, "Impossible de créer le tube nommé.\n");
		exit(EXIT_FAILURE);
	}

	if((entreeTube = open(nomTube, O_WRONLY)) == -1) 
	{
		fprintf(stderr, "Impossible d'ouvrir l'entrée du tube nommé.\n");
		exit(EXIT_FAILURE);
	}

	write(entreeTube, chaineAEcrire, TAILLE_MESSAGE);


	return EXIT_SUCCESS;
}

int main(){

    printf("Bienvenue ! Saisissez votre pseudo : ");
    scanf("%s",nomJoueur);

    creationPipe();
}
