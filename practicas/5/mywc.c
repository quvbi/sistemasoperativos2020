#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    //char name[240];
    //scanf("%s",name);
   // printf("el contendio es: %s\n", name);

   char c;
  
   unsigned lineas =1;
 unsigned caracteres =0;
   unsigned palabras =0;


   while(read(STDIN_FILENO,&c,1)!=0){
     
        if(c != ' ' && c != '\n'){
          
        } else if(c=='\n'){
            lineas +=1;
            }else {
            palabras+=1;
        }
        caracteres+=1;
   }
   if(c!=' '){
       palabras+=1;
   }
  
  printf("caracteres: %u lineas: %u palabras: %u\n", caracteres, lineas, palabras);
    
return 0;
}