#include "./student.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int dFd = open("class.dat", O_WRONLY, O_CREAT, 600);
    Student *myStudent;
    myStudent = calloc(1,sizeof(Student));
    for (int i = 0; i < 20; i++ ) {
        
        write(dFd, myStudent,  sizeof(Student));
    }
        close(dFd);
        return 0;
}
