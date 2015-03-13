#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10001

int main(int argc,char** argv){
  msg r,t;
  init(HOST,PORT);

while (1) {
    if (recv_message(&r)<0){
      perror("Receive message");
      return -1;
    }

    printf("[%s] Got msg with payload: %s\n",argv[0],r.payload);

    // sprintf(t.payload,"1ACK");
    // t.len = strlen(t.payload + 1);
    // send_message(&t);

    // if (strcmp (r.payload, "0ENDSTOP") == 0 || strcmp (r.payload, "1ENDSTOP") == 0)
    //   break;

    /* Uncomment this to write in file PART 2/2 */
    //wb = write(dest_file, r.payload + 1, 7);
  }

  printf("[%s] Got msg with payload: %s\n",argv[0],r.payload);

  sprintf(t.payload,"ACK(%s)",r.payload);
  t.len = strlen(t.payload+1);
  send_message(&t);
  return 0;
}
