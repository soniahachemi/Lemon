#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "socket.h"
#include <unistd.h>

int main (void)
{
	int socket_serveur;
	socket_serveur= creer_serveur(8080);
	if(socket_serveur==-1){
		perror("socket_serveur");
		return -1;
	}
// Creation client
	int socket_client ;
	socket_client = accept ( socket_serveur , NULL , NULL );
	if ( socket_client == -1)
	{
		perror ( " accept " );
		/* traitement d ’ erreur */
	}
	const char * message_bienvenue="bjr";
	write ( socket_client , message_bienvenue , strlen ( message_bienvenue ));
	close(socket_serveur);
	return 0;
}
