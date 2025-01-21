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
        fputs(students[i].name, file);
        fputs(" ", file);
        fputs(students[i].branch, file);
        fputs(" ", file);
        fputs(students[i].place, file);
        fputs("\n", file);
    }

    fclose(file);
    printf("Data written to file successfully.\n");
}

void readFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
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
            printf(".");
        }
        printf("%s", student.branch);
        for (int i = strlen(student.branch); i < 5; i++)
        {
            printf(".");
        }
        printf("%s", student.place);
        for (int i = strlen(student.place); i < 10; i++)
        {
            printf(".");
        }

        printf("\n");
    }

    fclose(file);
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

    writeToFile(students, numStudents, filename); // Write data to file
    readFromFile(filename);                       // Read data from file

    free(students); // Free dynamically allocated memory

    return 0;
}
