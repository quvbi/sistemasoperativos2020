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
    printf("id: ");
    scanf("%d", &myStudent.id);
    printf("name: ");
    scanf("%s", myStudent.afirstNme);
    printf("last name: ");
    scanf("%s ", myStudent.lastName);
    printf("semester: ");
    scanf("%c ", &myStudent.semester);

// printf("index %d, id %d, firstname %s, lastName %s, semester %c", index, myStudent.id, myStudent.afirstNme,myStudent.lastName, myStudent.semester);
    int fd = open("class.dat", O_WRONLY, 0);
    int offset = index * sizeof(Student);
    lseek(fd,  offset,SEEK_SET);
    write(fd, &myStudent, sizeof(Student));
    close(fd);
    return 0;



}