#include "./student.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    unsigned index;
    Student myStudent;

    printf("index: ");
    scanf("%d", &index);
    int fd = open("class.dat", O_RDONLY, 0);
    int offset = index * sizeof(Student);
    lseek(fd,  offset,SEEK_SET);
    read(fd, &myStudent, sizeof(Student));
    close(fd);

//printf("index %d, id %d, firstname %s, lastName %s, semester %c", index, myStudent.id, myStudent.afirstNme,myStudent.lastName, myStudent.semester);
    printf("attribute: ");
    char attributeName[20];
    scanf("%c", attributeName);
    if(strcmp(attributeName, "id") == 0){
        printf("current id %d , new id:", myStudent.id);
        scanf("%d", &myStudent.id);
    }
     if(strcmp(attributeName, "lastName") == 0){
        printf("current lastname %s , new lastname:", myStudent.lastName);
        scanf("%s", myStudent.lastName);
    }
     if(strcmp(attributeName, "firstName") == 0){
        printf("current firstname %s , new firstname:", myStudent.afirstNme);
        scanf("%s", myStudent.afirstNme);
    }
     if(strcmp(attributeName, "semester") == 0){
        printf("current id %c , new id:", myStudent.semester);
        scanf("%c", &myStudent.semester);
    }

    fd = open("class.dat", O_WRONLY,0);
    lseek(fd, offset, SEEK_SET );
    write(fd, &myStudent,  sizeof(Student));
    close(fd);
    return 0;

}