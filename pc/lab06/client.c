/*
*  	Protocoale de comunicatii: 
*  	Laborator 6: UDP
*	client mini-server de backup fisiere
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
	fprintf(stderr,"Usage: %s ip_server port_server file\n",file);
	exit(0);
}

/*
*	Utilizare: ./client ip_server port_server nume_fisier_trimis
*/
int main(int argc,char**argv)
{
	// if (argc!=4)
		// usage(argv[0]);
	int fd;
	struct sockaddr_in to_station;
	char buf[BUFLEN];

	/*Deschidere socket*/
	fd = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP);

	/*Setare struct sockaddr_in pentru a specifica unde trimit datele*/
	to_station.sin_family = AF_INET;
	to_station.sin_port = htons (atoi (argv[2]));
	inet_aton(argv[1], &to_station.sin_addr);

	int c = connect (fd, (struct sockaddr *) &to_station, sizeof (struct sockaddr));
	printf("%d\n", c);

	int n;
	while (1) {
		n = read (0, buf, BUFLEN);
		buf[strlen (buf)] = '\0';
		send (fd, buf, n + 1, 0);

		n = recv (fd, buf, 100, 0);
		write (1, "Received ", 9);
		write (1, buf, n);

		if (buf[0] == 'x')
			break;
	}


	/*Inchidere socket*/
	close (fd);
	/*Inchidere fisier*/

	return 0;
}