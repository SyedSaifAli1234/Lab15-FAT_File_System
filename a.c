#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define col 128 
#define row 10 

int main(void) {

    char line[row][col];
	char fname[20];
	char name[20];
	char temp[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;
    int j;
    char c;
  	int Num_of_files;
    int check = 0;
    int add = 0;
    int length = 0;
		

    fptr = fopen("file.txt", "r");
    while(fgets(line[i], col, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	
    Num_of_files = *line[3] - '0';
    printf("Num_of_files = %d\n", Num_of_files);

    while(1){
    	printf("\nChoose an option\n");
    	printf("1. Size of a file\n");
    	printf("2. Delete a file\n");
    	printf("3. Show freespace in the disk\n");

    	printf("Input: ");
    	c = getchar();

    	if(c == '1'){
    		printf("Please enter the name of the file: ");
    		scanf("%s", name);
    		printf("\nThe file name entered  by you is %s\n", name);
            int n = 0;
    		
            while(line[4][n]!=' '){
    			temp[n]=line[4][n];
    			n++;
    		}
    		
            temp[n]='\0'; 
            n=0; 		

    		for(int k=4; k < (4+Num_of_files); k++){
    			for (int m = 0; temp[m]!='\0'; m++){
                    if(line[k][m] == temp[m]){
                        length++;
                    }
                    else{
                        check = 1;
                    }
    			}
                if(check == 0){
                    printf("Length = %d\n", length);
                    add = (line[k][length+2]) - '0';
                    printf("Temp = %s\n", temp);
                    break;
                }
                else{
                    while(line[k+1][n]!=' '){
                        temp[n]=line[k+1][n];
                        n++;
                    }
                    temp[n]='\0'; 
                    printf("New temp = %s\n", temp);
                    n=0; 
                }
    		}
            printf("Starting address = %d\n", add);
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
















