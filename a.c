#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define col 128 
#define row 10 

int main(void) 
{
    char line[row][col];
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;
		

    fptr = fopen("file.txt", "r");
    while(fgets(line[i], col, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file are\n");    
    for(i = 0; i < tot; ++i)
    {
        printf(" %s\n", line[i]);
    }
    printf("\n");
    return 0;
}