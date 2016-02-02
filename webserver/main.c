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
	while(1){
	socket_client = accept ( socket_serveur , (struct sockaddr *) &clientname, &size);
	if ( socket_client == -1)
	{
		perror ( " accept " );
		/* traitement d ’ erreur */
	}
	const char * message_bienvenue="bjr";
		write ( socket_client , message_bienvenue , strlen ( message_bienvenue ));
		
	}
	close(socket_serveur);
	return 0;
}
