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
	const char * message_bienvenue="Bonjour et bienvenue sur le serveur Lemon ! \n";	
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



