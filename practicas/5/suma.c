#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    //char name[240];
    //scanf("%s",name);
   // printf("el contendio es: %s\n", name);

   char c;
   char buffer[20];
   unsigned i = 0;
   unsigned total =0;

   while(read(STDIN_FILENO,&c,1)!=0){
        if(c != ' '){
           buffer[i] = c; 
           i+=1;

        } else {
            buffer[i] = '\0';
            total += atoi(buffer);
            i = 0;
        }
   }
   buffer[i] = '\0';
  total += atoi(buffer);
  printf("%u\n", total);
    
return 0;
}