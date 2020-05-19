#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define col 128 
#define row 10 

int main(void) 
{
    char line[row][col];
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;
    int j;
    char name[20];
    char c;
		

    fptr = fopen("file.txt", "r");
    while(fgets(line[i], col, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	// printf("\n The content of the file are\n");    
 //    for(i = 0; i < tot; ++i)
 //    {
 //        printf(" %s\n", line[i]);
 //    }

    while(1){
    	printf("\nChoose an option\n");
    	printf("1. Size of a file\n");
    	printf("2. Delete a file\n");
    	printf("3. Show freespace in the disk\n");

    	//sleep(1);
    	printf("Input: ");
    	c = getchar();

    	if(c == '1'){
    		printf("Please enter the name of the file: ");
    		scanf("%s", name);
    		printf("\nThe file name entered  by you is %s\n", name);
    	}
    	else if(c == '2'){
    		printf("Please enter the name of the file you want to delete: ");
    		scanf("%s", name);
    		printf("\nThe file name entered  by you is %s\n", name);
    	}
    	else if(c == '3'){
    		printf("\nThe total free space on disk is: \n");
    	}
    	else{
    		printf("\nOption is invalid\n");
    	}
    	c = getchar();

    }




    printf("\n");
    return 0;
}
















