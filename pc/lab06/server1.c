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


// void usage(char*file)
// {
// 	fprintf(stderr,"Usage: %s server_port file\n",file);
// 	exit(0);
// }

/*
*	Utilizare: ./server server_port nume_fisier
*/
int main(int argc,char**argv)
{
	// if (argc!=3)
		// usage(argv[0]);

	struct sockaddr_in my_sockaddr;
	char buf[BUFLEN];


	/*Deschidere socket*/
	int sd1 = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP);

	/*Setare struct sockaddr_in pentru a asculta pe portul respectiv */
	my_sockaddr.sin_family = AF_INET;
	my_sockaddr.sin_port = htons (1333);
	inet_aton("127.0.0.1", &my_sockaddr.sin_addr);

	/* Legare proprietati de socket */
	printf ("Bind %d\n ", bind (sd1, (struct sockaddr *) &my_sockaddr, sizeof(struct sockaddr_in)));
	listen (sd1, 100);

	unsigned int tmp1, tmp2;
	int sd2 = accept (sd1, (struct sockaddr *) &my_sockaddr, &tmp1);
	int sd3 = accept (sd1, (struct sockaddr *) &my_sockaddr, &tmp2);

	while (1) {
		int n = recv (sd2, buf, BUFLEN, 0);
		write (1, "Receive 1: ", 11);
		write (1, buf, n);
		send (sd3, buf, n, 0);

		n = recv (sd3, buf, BUFLEN, 0);
		write (1, "Receive 2: ", 11);
		write (1, buf, n);
		send (sd2, buf, n, 0);

		if (buf[0] == 'x')
			break;
	}


	/*Inchidere socket*/
	close (sd1);
	close (sd2);
	close (sd3);
	/*Inchidere fisier*/

	return 0;
}
