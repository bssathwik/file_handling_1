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

void writeToFile(struct Student *students, int count, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s %s %s\n", students[i].name, students[i].branch, students[i].place);
    }

    fclose(file);
    printf("Data written to file successfully.\n");
}
int main()
{
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));
    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++)
    {
        printf("Enter details for student %d (name branch place): ", i + 1);
        printf("name:");
        scanf("%s", students[i].name);
        printf("branch:");
        scanf("%s", students[i].branch);
        printf("place:");
        scanf("%s", students[i].place);
    }

    const char *filename = "students.txt";

    writeToFile(students, numStudents, filename); 

    return 0;
}
