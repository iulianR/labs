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

int getBit (int pos, char c)
{
  return abs((c >> (8 - pos)) % 2);
}

char setBit (int pos, char c)
{
  return c | (1 << (8 - pos));
}

char unsetBit (int pos, char c)
{
  return c & (255 - (1 << (8 - pos)));
}

int main(int argc,char** argv){
  init(HOST,PORT);
  msg t;
  int i = 0;
  //char * str = "Hello_World!";
  char * str = "Hello!";
  int length = strlen(str) / 2;
  char * buffer = (char*) malloc (2 * sizeof(char));
  char * message = (char*) malloc (3 * sizeof(char));

  int k;
  int b1, b2, b4, b8, b16;
  while (i < length) {
    strcpy (buffer, str + i * 2);
    strcpy (t.payload, "");
    strcpy (t.payload, "");
    strncat (t.payload, str + i * 2, 2);
    t.len = strlen(t.payload) + 1;
    printf("%s\n", t.payload);
    int j;
    for (j = 1; j <= 8; j++) {
      printf("%d ", getBit(j, buffer[0]));
    }
    printf("\n");
    for (j = 1; j <= 8; j++) {
      printf("%d ", getBit(j, buffer[1]));
    }

    message = (char *) malloc (3 * sizeof(char));
    // for (k = 0; k < 3; k++) {
    //   for (j = 1; j <= 8; j++) {
    //     message[k] = unsetBit(j, message[k]);
    //   }
    // }

    k = 1;
    for (j = 1; j <= 8; j++) {
      if (j == 1 || j == 2 || j == 4 || j==8) {
        continue;
      }

      if (getBit(k, buffer[0])) {
        message[0] = setBit(j, message[0]);
      }
      k++;
    }
    for (j = 1; j <= 8; j++) {
      // printf("k = %d", k);
      if (j == 16) {
        continue;
      }
      if (k > 8) {
        if (getBit(k % 8, buffer[1])) {
            message[1] = setBit(j, message[1]);
            // printf("here %d\n", getBit(j, message[1]));
        }
      }
      else {
        if (getBit(k, buffer[0])) {
            message[1] = setBit(j, message[1]);
            // printf("here %d\n", getBit(j, message[1]));
        }
      }
      k++;
    }
    for (j = 1; j <= 8; j++) {
      if (j >= 6)
        continue;
      // printf("k = %d", k);
      if (getBit(k % 8, buffer[1])) {
        message[2] = setBit(j, message[2]);
      }
      k++;
    }


    printf("\n");
    for (j = 1; j <= 8; j++) {
      printf("%d ", getBit(j, message[0]));
    }
    printf("\n");
    for (j = 1; j <= 8; j++) {
      printf("%d ", getBit(j, message[1]));
    }
    printf("\n");
    for (j = 1; j <= 8; j++) {
      printf("%d ", getBit(j, message[2]));
    }

    b1 = getBit(1, message[0]) + getBit(3, message[0]) + getBit(5, message[0]) + getBit(7, message[0]) +
    getBit(9, message[1]) + getBit(11, message[1]) + getBit(13, message[1]) + getBit(15, message[1]) +
    getBit(17, message[2]) + getBit(19, message[2]) + getBit(21, message[2]); b1 = b1 % 2;

    b2 = getBit(2, message[0]) + getBit(3, message[0]) + getBit(6, message[0]) + getBit(7, message[0]) +
    getBit(10, message[1]) + getBit(11, message[1]) + getBit(14, message[1]) + getBit(15, message[1]) +
    getBit(18, message[2]); b2 = b2 % 2;

    b4 = getBit(4, message[0]) + getBit(5, message[0]) + getBit(6, message[0]) + getBit(7, message[0]) +
    getBit(12, message[1]) + getBit(13, message[1]) + getBit(14, message[1]) + getBit(15, message[1]) +
    getBit(18, message[2]); b4 = b4 % 2;

    b8 = getBit(8, message[0]) +
    getBit(9, message[1]) + getBit(10, message[1]) + getBit(11, message[1]) + getBit(12, message[1]) + getBit(13, message[1]) + getBit(14, message[1]) + getBit(15, message[1]) + getBit(20, message[2]) + getBit(21, message[1]);
    b8 = b8 % 2;
    
    if (b1 == 1)
      message[0] = setBit(1, message[0]);
    if (b2 == 1)
      message[0] = setBit(2, message[0]);
    if (b4 == 1)
      message[0] = setBit(4, message[0]);
    if (b8 == 1)
      message[0] = setBit(8, message[0]);
    printf("\n");
    printf("\n");
    printf("\n");
    // send_message (&t);

    // if (recv_message (&t)<0){
      // perror ("receive error");
    // }
    // else {
      // printf ("[%s] Got reply with payload: %s\n",argv[0],t.payload);
    // }

    i++;
  }
  // sprintf(t.payload,"Hello World of PC");
  // t.len = strlen(t.payload)+1;
  // send_message(&t);

  // if (recv_message(&t)<0){
  //   perror("receive error");
  // }
  // else {
  //   printf("[%s] Got reply with payload: %s\n",argv[0],t.payload);
  // }

  return 0;
}
