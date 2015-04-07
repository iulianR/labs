/*
*  	Protocoale de comunicatii: 
*  	Laborator 6: UDP
*	client mini-server de backup fisiere
*/

#include "helpers.h"

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
	// 	usage(argv[0]);
	
	int fd;
	struct sockaddr_in to_station;
	char buf[BUFLEN] = "Hello world!";


	/*Deschidere socket*/
	fd = socket (PF_INET, SOCK_DGRAM, 0);
	
	/* Deschidere fisier pentru citire */
	// DIE((fd=open(argv[3],O_RDONLY))==-1,"open file");
	
	/*Setare struct sockaddr_in pentru a specifica unde trimit datele*/
	to_station.sin_family = AF_INET;
	to_station.sin_port = 1222;
	inet_aton("127.0.0.1", &to_station.sin_addr);
	
	// sprintf(buf, "ASD");
	sendto (fd, buf, strlen (buf) + 1, 0, (struct sockaddr *) &to_station, sizeof (struct sockaddr));
	printf ("Sent\n");
	/*
	*  cat_timp  mai_pot_citi
	*		citeste din fisier
	*		trimite pe socket
	*/	


	/*Inchidere socket*/
	close (fd);
	
	/*Inchidere fisier*/

	return 0;
}