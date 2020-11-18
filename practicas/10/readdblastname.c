#include "./student.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
int main(){
    unsigned index;
    Student myStudent;
    char lastName[20];
    printf("Last Name: ");
    scanf("%s", lastName);
    int fd = open("class.dat", O_RDONLY, 0);

    while (read(fd, &myStudent, sizeof(Student))) {
            if (strcmp(myStudent.lastName,lastName) == 0) {
             printf("index %d, id %d, firstname %s, lastName %s, semester %c", index, myStudent.id, myStudent.afirstNme,myStudent.lastName, myStudent.semester);
            }
    }
   
    close(fd);
    return 0;



}