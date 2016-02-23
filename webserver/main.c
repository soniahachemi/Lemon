#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>


int main (void)
{

	struct sockaddr_in clientname;
	int socket_serveur;
	socklen_t size;
	socket_serveur= creer_serveur(8080);
	if(socket_serveur==-1){
		perror("socket_serveur");
		return -1;
	}
	

// Creation client
	int socket_client ;
	size = sizeof (clientname);
	socket_client = accept ( socket_serveur , (struct sockaddr *) &clientname, &size);
	if ( socket_client == -1)
	{
		perror ( " accept " );
		/* traitement d ’ erreur */
	}
	const char * message_bienvenue="Bonjour et bienvenue sur le serveur Lemon ! \n\nCe qui est dramatique\nEn dehors de croire que l’on détient la vérité\nEst de s’accrocher telle une tique\nAfin de l’imposer\n\nAucune amitié ne vaut\nLa paix de l’esprit\nAucuns grands travaux,\nNe vaut, du doute l’autopsie\n\nDu temps où vos solitudes me fascinaient\nJ’ai perdus mes concepts de simplicité\nEt chercher de l’intérieur ce qui chez moi clochait\nAlors que tout était déjà bien rangé\n\nÀ chacun son Dieu, à chacun sa folie\nEt les esprits seront bien gardés\nÉcoute ce que l’instinct te dit\nEt marche sans te retourner\n\n";	
	write ( socket_client , message_bienvenue , strlen ( message_bienvenue ));
	static char message_recu[200];
	int i;
	while(1){
		if ((i = read(socket_client, message_recu,200 )) > 0){
			write(socket_client, message_recu, i);
		}
	}
	close(socket_serveur);
	return 0;
}



