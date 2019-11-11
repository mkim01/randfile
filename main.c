#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "randfile.h"

int main(){
//
  printf("Generating random numbers: \n");
  int arr[10];
  int i;
  for(i = 0; i < 10; i++){
    arr[i] = rand_num();
    printf("random %d: %d\n", i, arr[i]);
  }
//
  printf("Writing numbers to file...\n");
  int file = open("test", O_CREAT | O_RDWR, 0644);
  if (file == -1){
    printf("errno: %s\n", strerror(errno));
  }
  int error = write(file, arr, sizeof(int)*10);
  if (error == -1){
    printf("errno: %s\n", strerror(errno));
  }
  printf("Bytes written: %d\n", error);
  close(file);
//
  printf("Reading numbers from file...\n");

  int nums[10];
  file = open("test", O_RDONLY);
  if (file == -1){
   printf("errno: %s\n", strerror(errno));
  }
  error = read(file, nums,sizeof(int)*10);
  if (error == -1){
   printf("errno: %s\n", strerror(errno));
  }
  printf("Bytes read: %d\n", error);

//
  printf("Verification that written values were the same:\n");
  for (i = 0; i < 10; i++){
   printf("random %d: %d\n", i, nums[i]);
  }
  close(file);
}
