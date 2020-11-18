#include "./student.h"
#include <stdio.h>
#include <fcntl.h>
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
    return 0;

 printf("index %d, id %d, firstname %s, lastName %s, semester %c", index, myStudent.id, myStudent.afirstNme,myStudent.lastName, myStudent.semester);


}