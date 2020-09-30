#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    //char name[240];
    //scanf("%s",name);
   // printf("el contendio es: %s\n", name);

   char c;
   while(read(STDIN_FILENO,&c,1)!=0){
        write(STDOUT_FILENO, &c, 1);
   }
    
return 0;
}