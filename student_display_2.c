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
        printf("%s", student.name);
        for (int i = strlen(student.name); i < 10; i++)
        {
            printf(" ");
        }
        printf("%s", student.branch);
        for (int i = strlen(student.branch); i < 5; i++)
        {
            printf(" ");
        }
        printf("%s", student.place);
        for (int i = strlen(student.place); i < 10; i++)
        {
            printf(" ");
        }

        printf("\n");
    }

    fclose(file);
    return 0;
}
