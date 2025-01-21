#include <stdio.h>
#include <stdlib.h>

void createAndWriteSourceFile(const char *sourceFile) {
    FILE *file;
    char ch;

    file = fopen(sourceFile, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }
    
    printf("Enter data to add to the file (Ctrl+D to end input):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == '*') {
            break;
        }
        putc(ch, file);
    }

    printf("Data successfully added to '%s'.\n", sourceFile);

    fclose(file);
}

void copyFileContent(const char *sourceFile, const char *destinationFile) {
    FILE *source, *destination;
    char ch;

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Source file '%s' does not exist or cannot be opened.\n", sourceFile);
        exit(1);
    }

    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Error opening destination file '%s'!\n", destinationFile);
        fclose(source);
        exit(1);
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("Content copied from '%s' to '%s'.\n", sourceFile, destinationFile);

    fclose(source);
    fclose(destination);
}

int main() {
    const char *sourceFile = "source.txt";
    const char *destinationFile = "destination.txt";

    FILE *checkSource = fopen(sourceFile, "r");
    if (checkSource == NULL) {
        printf("Source file '%s' does not exist.\n", sourceFile);
        createAndWriteSourceFile(sourceFile);
    } else {
        fclose(checkSource);
    }

    copyFileContent(sourceFile, destinationFile);

    return 0;
}
