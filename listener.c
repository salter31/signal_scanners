#include<stdio.h>
#include<linux/input.h>
#include<linux/types.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<math.h>

int main(int argc, char** argv){
  int fd = open(argv[1], O_RDONLY);
  struct input_event ev;

  sleep(1);
  while(1){
    while(read(fd,&ev,sizeof(struct input_event))!=-1){
      printf("\n%i\n%i\n%i\n",ev.type,ev.value,ev.code);
    }
    while((fd = open(argv[1], O_RDONLY))==-1){}
  }
}