#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10000

int main(int argc, char *argv[])
{
	msg t;
	int i, res;
	
	printf("[SENDER] Starting.\n");	
	init(HOST, PORT);

	printf("[SENDER]: BDP=%d\n", atoi(argv[1])); 
	float window_size = (float) atoi(argv[1])/(MSGSIZE * 8);
	int size = 8;
	printf("Window size: %lf = %d\n", window_size, size);

	// primim bdp biti, msg_size bytes
	//afisati bdp, afisati dim, afisam fiecare send and receiv
	// speed mb/s, delay ms
	int j;
	for (j = 0; j < size; j++) {
		printf ("sent %d\n", j);
		res = send_message(&t);
		if (res < 0) {
			perror("[SENDER] Send error. Exiting.\n");
			return -1;
		}
	}
	for (i = size; i < COUNT; i++) {
		/* cleanup msg */
		memset(&t, 0, sizeof(msg));
		
		/* gonna send an empty msg */
		t.len = MSGSIZE;
		
		
		/* wait for ACK */
		res = recv_message(&t);
		printf ("received %d\n", i);
		if (res < 0) {
			perror("[SENDER] Receive error. Exiting.\n");
			return -1;
		}
		else {
			/* send msg */
			if (i < COUNT - size) {
				res = send_message(&t);
				printf ("sent %d\n", i);
				if (res < 0) {
					perror("[SENDER] Send error. Exiting.\n");
					return -1;
				}
			}
		}
	}

	printf("[SENDER] Job done, all sent.\n");
		
	return 0;
}
