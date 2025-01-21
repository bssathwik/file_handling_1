#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// #define  10

struct Student
{
    char name[10];
    char branch[5];
    char place[10];
};


int main()
{
  FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    struct Student student;
    printf("Reading data from file:\n");
    while (fscanf(file, "%s %s %s", student.name, student.branch, student.place) != EOF)
    {
        printf(" %d %s  %s  %s \n",(strlen(student.name)+strlen(student.branch)+strlen(student.place)),student.name,student.branch,student.place);
    }

    fclose(file);
    return 0;
}
