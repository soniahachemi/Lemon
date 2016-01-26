#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int main ( int argc , char ** argv )
{
/* Arnold Robbins in the LJ of February ’95 , describing RCS */
	if(argc > 1 && strcmp(argv [1]," - advice ")== 0){
		printf("Dont panick");
		return 42;
	}
	printf("need an advice ?");
	int socket_serveur;
	socket_serveur= socket(AF_INET, SOCK_STREAM,0);
	if(socket_serveur==-1){
		perror("socket_serveur");
		return -1;
	}


	return 0;
}
