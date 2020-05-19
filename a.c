#include <stdio.h>       
#include <stdlib.h>

char* buffer;
char* buffer2;


int main(){


		printf("\nReading file A\n");
		FILE *fp;
	    char line[11];
	    line[10] = '\0';

	    fp = fopen("file-1.txt", "r");
   	    fgets(line, 11, (FILE*)fp);
	    printf("Read from file: %s\n", line);
	    fclose(fp);
	    
	    printf("Printed to buffer: ");
	    sem_wait(buff1);
	    for(int i=0; i<10; i++){
	    	buffer[i] = line[i];
	    	printf("%c", buffer[i]);
	    }

	  
	
		wait(NULL);																		
		if(fork() == 0){
		//B say read and enter in buffer1												
			printf("In Process B\n");
			FILE *fp;
		    char line[11];
		    line[10] = '\0';

		    fp = fopen("file-2.txt", "r");
	   	    fgets(line, 11, (FILE*)fp);
		    printf("Read from file: %s\n", line);
		    fclose(fp);
		    
		    printf("Printed to buffer: ");
		    sem_wait(buff1);
		    int j = 10;
		    for(int i=0; i<10; i++){
		    	buffer[j] = line[i];
		    	printf("%c", buffer[j]);
		    	j++;
		    }

		    sem_post(buff1);
		    printf("\nLeaving Process B after writing to buffer1\n\n");
		    printf("Buffer 1 now contains: %s\n", buffer);
		    exit(0);
		}
		else{
			wait(NULL);																	
			if(fork() == 0){		
			//C say read from buffer1 to buffer 2										
				printf("\nIn Process C\n");
				sem_wait(buff1);
				sem_wait(buff2);
				for(int i = 0; i<20; i++){
					buffer2[i] = buffer[i];
				}
				printf("Buffer 1 = %s\n", buffer);
				printf("Buffer 2 = %s\n", buffer2);
				sem_post(buff1);
				sem_post(buff2);
				exit(0);
			}
			else{	
				wait(NULL);																
				if(fork() == 0){														
					//D reads from Buffer 2 and prints
					printf("In Process D\n");
					sem_wait(buff2);
					
					for(int i = 0; i<20; i++){
						buffer2[i] = buffer[i];
						printf("%c", buffer2[i]);
					}
					sem_post(buff2);
					printf("\n");
					exit(0);
				}
				else{
					wait(NULL);
				}
			}
		}
	}











	result = shmdt(buff1);																
	if (result < 0){
		perror("Error in removing semaphore buff1_sem\n");
		exit(0);
	}
	result = shmdt(buff2);
	if (result < 0){
		perror("Error in removing semaphore buff2_sem\n");
		exit(0);
	}
	result = shmdt(buffer);
	if (result < 0){
		perror("Error in removing semaphore buff2_sem\n");
		exit(0);
	}
	result = shmdt(buffer2);
	if (result < 0){
		perror("Error in removing semaphore buff2_sem\n");
		exit(0);
	}

	
	shmctl(shmid_buff1, IPC_RMID, 0);
	shmctl(shmid_buff2, IPC_RMID, 0);
	shmctl(shmid_buff1_sem, IPC_RMID, 0);
	shmctl(shmid_buff2_sem, IPC_RMID, 0);
    sem_destroy(buff1);
    sem_destroy(buff2);

	printf("\nEverything works\n");
	return 0;
}

