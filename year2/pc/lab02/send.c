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

int main(int argc,char** argv){
  init(HOST,PORT);
  msg t;

  char flag = '0';

  int source_file;
  source_file = open ("source.data", O_RDONLY);

  int rb;
  char buffer[7];

  /* Uncomment this for first part
  int length = strlen (str) / 7;
  int i = 0;
  char * str = "This is a long string";

  while (i < length) {
    strcpy (t.payload, "");
    strncat (t.payload, &flag, 1);
    strncat (t.payload, str + i * 7, 7);
    t.len = strlen(t.payload) + 1;
 
    send_message (&t);

    if (recv_message (&t)<0){
      perror ("receive error");
    }
    else {
      printf ("[%s] Got reply with payload: %s\n",argv[0],t.payload);
    }

    flag = (flag == '0') ? '1' :'0';
    i++;
  }
  */

  /* Comment this for first part */
  while ((rb = read (source_file, buffer, 7))) {
      strcpy (t.payload, "");
      strncat (t.payload, &flag, 1);
      strcat (t.payload, buffer);
      t.len = strlen(t.payload) + 1;
   
      send_message (&t);

      if (recv_message (&t)<0){
        perror ("receive error");
      }
      else {
        printf ("[%s] Got reply with payload: %s\n",argv[0],t.payload);
      }

      flag = (flag == '0') ? '1' :'0';
  }

  /* Don't touch */
  strcpy (t.payload, "");
  strncat (t.payload, &flag, 1);
  strcat (t.payload, "ENDSTOP");
  send_message (&t);

  if (recv_message (&t) < 0) {
    perror ("receive error");
  }
  else {
    printf ("[%s] Got reply with payload: %s\n", argv[0], t.payload);
  }

  return 0;
}
