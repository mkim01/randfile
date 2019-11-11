#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "randfile.h"

int rand_num() {
  int file = open("/dev/random", O_RDONLY);
  if (file == -1){
    printf("errno: %s", strerror(errno));
  }

  int buff;
  int test = read(file, &buff, 4);
  if (test == -1) {
    printf("errno: %s\n", strerror(errno));
  }

  close(file);
  return buff;
}
