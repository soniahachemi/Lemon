#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>




void hand(int sig) {


printf("signal : %d",sig);
int status;
    int pid;
	while((pid=waitpid(-1,&status,WNOHANG))>0){

}

}


void initialiser_signaux ( void ){
  struct sigaction sa ;
	sa.sa_handler = hand ;
	sigemptyset (&sa.sa_mask );
	sa.sa_flags = SA_RESTART ;

	if ( sigaction ( SIGCHLD , &sa , NULL ) == -1)
	{
		perror ( " sigaction ( SIGCHLD ) " );
	}
}

int creer_serveur(int port){
  int socket_serveur ;
  socket_serveur = socket( AF_INET , SOCK_STREAM , 0);

  
  
  if ( socket_serveur == -1)
    {
      perror ( " socket_serveur " );
      /* traitement de l ’ erreur */
    }
  /* Utilisation de la socket serveur */

  int option = 1;
  if ( setsockopt ( socket_serveur , SOL_SOCKET , SO_REUSEADDR , &option , sizeof ( int )) == -1)
    perror ( " Can not set SO_REUSEADDR option " );

  struct sockaddr_in saddr ;
  saddr.sin_family = AF_INET ; /* Socket ipv4 */
  saddr.sin_port = htons(port); /* Port d ’ écoute */
  saddr.sin_addr.s_addr = INADDR_ANY ; /* écoute sur toutes les interfaces */
  if(bind ( socket_serveur , ( struct sockaddr *)& saddr , sizeof( saddr )) == -1)
    {
      perror( " bind socker_serveur " );
    }
  if ( listen ( socket_serveur , 10) == -1)
    {
      perror ( " listen socket_serveur " );
    }
	

  return socket_serveur;
}

