#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LIMIT 256 // max number of tokens for a command
#define MAXLINE 1024 // max number of characters from user input

//Function Declaration (Prototype)
void clear();

int main(int argc, char *argv[]){

    clear();

    //prompt: username
	char *username = getenv("USER");

    //prompt: hostname
	char hostname[1024];
	hostname[1023] = '\0';
	gethostname(hostname, 1023);

    //prompt: working_directory
    char *working_directory = getenv("PWD");

    char prompt[1032];

  	snprintf(prompt, sizeof(prompt), "%s@%s:%s $ ", username, hostname, working_directory);

    char line[MAXLINE]; // buffer for the user input
    char *lastPosition;

  	while(1){

  	    //Print out the prompt
  	    printf("%s", prompt);
  	    fgets(line, MAXLINE, stdin);

  	    lastPosition=strchr(line, '\n');
        if(lastPosition!=NULL){
            *lastPosition = '\0';}

        if(strcmp(line, "exit") == 0){
            exit(0);}

    }

	printf("\n");

return 0;
}

//Function Definition: clear
void clear(){

    printf("\033[H\033[J");

}
