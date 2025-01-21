#include <stdio.h>
#include <stdlib.h>





int main()
{
  FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int ch;
    printf("Reading data from file:\n");
    while((ch = fgetc(file)) != EOF){
		if(ch==' '||ch=='\n'){
			printf("#");
			if(ch=='\n'){
				printf("\n");
			}
		}
		else{
			printf("%c",ch);
		}
	
	  	}


    fclose(file);
    return 0;
}
