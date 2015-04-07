/*
*  	Protocoale de comunicatii: 
*  	Laborator 6: UDP
*	mini-server de backup fisiere
*/
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include "helpers.h"


void usage(char*file)
{
	fprintf(stderr,"Usage: %s server_port file\n",file);
	exit(0);
}

/*
*	Utilizare: ./server server_port nume_fisier
*/
int main(int argc,char**argv)
{
	// if (argc!=3)
		// usage(argv[0]);
	
	struct sockaddr_in my_sockaddr,from_station ;
	char buf[BUFLEN];


	/*Deschidere socket*/
	int fd = socket (PF_INET, SOCK_DGRAM, 0);
	
	/*Setare struct sockaddr_in pentru a asculta pe portul respectiv */
	my_sockaddr.sin_family = AF_INET;
	my_sockaddr.sin_port = 1222;
	inet_aton("127.0.0.1", &my_sockaddr.sin_addr);
	
	/* Legare proprietati de socket */
	printf ("Bind %d\n ", bind (fd, (struct sockaddr *) &my_sockaddr, sizeof(struct sockaddr_in)));
	
	unsigned int tmp;

	recvfrom (fd, buf, 100, 0, (struct sockaddr *) &from_station, &tmp);
	printf ("Here %s\n", buf);
	// sendto (fd, buf, strlen (buf), 0, (struct sockaddr_in*) &to_station, sizeof (struct sockaddr_in));
	/* Deschidere fisier pentru scriere */
	// DIE((fd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644))==-1,"open file");
	
	/*
	*  cat_timp  mai_pot_citi
	*		citeste din socket
	*		pune in fisier
	*/


	/*Inchidere socket*/	
	close (fd);

	
	/*Inchidere fisier*/

	return 0;
}
