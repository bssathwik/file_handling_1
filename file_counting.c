#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    fp = fopen("students.txt", "r");
    char ch;
    int w = 0;
    int count = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ')
        {
            w++;
        }
        else
        {
            count++;
        }
    }
    printf("Count with spaces %d\n", w + count);
    printf("Count without spaces %d", count);
    return 0;
}