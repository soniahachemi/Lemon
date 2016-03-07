#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/wait.h>



int main (void)
{
  initialiser_signaux();
	struct sockaddr_in clientname;
	int socket_serveur;
	socklen_t size = sizeof (clientname);
	socket_serveur= creer_serveur(8080);
	if(socket_serveur==-1){
		perror("socket_serveur");
		return -1;
	}


	
		//const char * message_bienvenue=" Bonjour et bienvenue sur le serveur Lemon ! \n\nCe qui est dramatique\nEn dehors de croire que l’on détient la vérité\nEst de s’accrocher telle une tique\nAfin de l’imposer\n\nAucune amitié ne vaut\nLa paix de l’esprit\nAucuns grands travaux,\nNe vaut, du doute l’autopsie\n\nDu temps où vos solitudes me fascinaient\nJ’ai perdus mes concepts de simplicité\nEt chercher de l’intérieur ce qui chez moi clochait\nAlors que tout était déjà bien rangé\n\nÀ chacun son Dieu, à chacun sa folie\nEt les esprits seront bien gardés\nÉcoute ce que l’instinct te dit\nEt marche sans te retourner\n\n";	


const char * message_erreur = "HTTP/1.1 400 Bad Request \r\n Connection: close \r\n Content-Length: 17 \r\n 400 Bad request \r\n";


// Creation client
	int socket_client ;
	int f;

	while((socket_client = accept ( socket_serveur , (struct sockaddr *) &clientname, &size))  !=-1 ){
		if((f=fork()) ==-1 ){ perror("Erreur fork");}
		
		if(f==0){
			// processus fils

			FILE * desc;
			char str[60];

			desc = fdopen(socket_client,"w+");


			if(desc==NULL){
				perror("Erreur fopen");
				return -1;
			}
			// Analyse de la requete
			char premiereLigne[50];			
			fgets (premiereLigne, 50, desc);

			if(sscanf(premiereLigne,"GET / HTTP/1.1\n")== 0){
				printf("%s",premiereLigne);
				while( fgets (str, 60, desc)!=NULL ){
					printf("%s",str);
	  		 	}
			}

			else {fprintf(desc,"%s \n",message_erreur);}

	  		fclose(desc);
		}
		else {
			close(socket_client);
		}
	}
	return 0;
}







