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

    char line[MAXLINE]; //buffer for the user input
    char *lastPosition;

    while(1){

        //Print out the prompt
        printf("%s", prompt);
        fgets(line, MAXLINE, stdin);

        lastPosition=strchr(line, '\n');
        if(lastPosition!=NULL){
            *lastPosition='\0';}

        int loop, lineLength=strlen(line);

        int spaces=0; //keep track number of spaces found in the arg string, so how large the argument array is known
        for(loop=0;loop<lineLength;loop++){
            if(line[loop] == ' '){
                spaces++;}
        }

        //Initialize the argument array to have space for a null at the end
        char* toks[(spaces+2)];

        //Initialize the entire array to be null to start
        for(loop=0;loop<spaces+2;loop++){
          toks[loop]=NULL;}

        int counter=0;

        //Cut the string up into individual array indexes
        char *token=strtok(line, " :'\n''\t'");

        while(token!=NULL){
            toks[counter]=strdup(token);
            token=strtok(NULL, " :'\n''\t'");
            counter++;}

        toks[counter]=token;

        if(strcmp(toks[0], "exit") == 0){
            exit(0);}

    }

	printf("\n");

return 0;
}

//Function Definition: clear
void clear(){

    printf("\033[H\033[J");

}
