/*
    written by Jason Salter
    Processes every button press on a ps4 controller
    Barebones driver
*/

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
  int xR=130;
  int yR=130;
  struct input_event ev;


  while(1){
    while(read(fd,&ev,sizeof(struct input_event))!=-1){
      if(ev.code==305){
        if(ev.value==1){
          printf("pressed X\n");
        }else{
          printf("released X\n");
        }
      }else if(ev.code==304){
        if(ev.value==1){
          printf("pressed Square\n");
        }else{
          printf("released Square\n");
        }
      } else if(ev.code==306){
        if(ev.value==1){
          printf("pressed Circle\n");
        }else{
          printf("released Circle\n");
        }
      }else if(ev.code==307){
        if(ev.value==1){
          printf("pressed Triangle\n");
        }else{
          printf("released Triangle\n");
        }
      }else if(ev.code==308){
        if(ev.value==1){
          printf("pressed L1\n");
        }else{
          printf("released L2\n");
        }
      }else if(ev.code==309){
        if(ev.value==1){
          printf("pressed R1\n");
        }else{
          printf("released R1\n");
        }
      }else if(ev.code==310){
        if(ev.value==1){
          printf("pressed L2\n");
        }else{
          printf("released L2\n");
        }
      }else if(ev.code==311){
        if(ev.value==1){
          printf("pressed R2\n");
        }else{
          printf("released R2\n");
        }
      }else if(ev.code==312){
        if(ev.value==1){
          printf("pressed Share\n");
        }else{
          printf("released Share\n");
        }
      }else if(ev.code==313){
        if(ev.value==1){
          printf("pressed Options\n");
        }else{
          printf("released Options\n");
        }
      }else if(ev.code==314){
        if(ev.value==1){
          printf("pressed L3\n");
        }else{
          printf("released L3\n");
        }
      }else if(ev.code==315){
        if(ev.value==1){
          printf("pressed R3\n");
        }else{
          printf("released R3\n");
        }
      }else if(ev.code==316){
        if(ev.value==1){
          printf("pressed PS Button\n");
        }else{
          printf("released PS Button\n");
        }
      }else if(ev.code==317){
        if(ev.value==1){
          printf("pressed Touchpad\n");
        }else{
          printf("released Touchpad\n");
        }
      }else if(ev.type==3){
        if(ev.code==16){
          if(ev.value==0){
            printf("released D-Pad\n");
          }else if(ev.value==1){
            printf("pressed D-Pad Right\n");
          }else if(ev.value==-1){
            printf("pressed D-Pad Left\n");
          }
        }else if(ev.code==17){
          if(ev.value==0){
            printf("released D-Pad\n");
          }else if(ev.value==1){
            printf("pressed D-Pad Down\n");
          }else if(ev.value==-1){
            printf("pressed D-Pad Up\n");
          }
        }else{
          if(ev.code==2 || ev.code==5){ 
            if(ev.code==5)yR=ev.value;
            if(ev.code==2)xR=ev.value;

            //115 < val < 140  == resting
            printf("Right Stick (%d,%d)\n",xR,yR);
          }

          if(ev.code==0 || ev.code==1){ 
            if(ev.code==1)yR=ev.value;
            if(ev.code==0)xR=ev.value;

            //115 < val < 140  == resting
            printf("Left Stick (%d,%d)\n",xR,yR);
          } 
        }

      }else {
        //4 is default signal
        //it is paired with every other signal
        //0 signals end of signal
        if(ev.type!=4 && ev.type!=0){
          printf("xxxxxxxxxxxxxxxxxxxx\n");
          printf("\n%i\n%i\n%i\n",ev.type,ev.value,ev.code);
          printf("XXXXXXXXxxxxxxxxxxxx\n");
        }
      }      
    }
    while((fd = open(argv[1], O_RDONLY))==-1){}
  }
}


