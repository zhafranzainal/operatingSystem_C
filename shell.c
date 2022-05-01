#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LIMIT 256 //max number of tokens for a command
#define MAXLINE 1024 //max number of characters from user input

//Function Declaration (Prototype)
void clear();
void display_prompt();

char prompt[1032];

int main(int argc, char *argv[]){

    clear();

    char line[MAXLINE]; //buffer for the user input
    char *lastPosition;

    while(1){

        display_prompt();

        //print out the prompt
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

        //initialize the argument array to have space for a null at the end
        char* toks[(spaces+2)];

        //initialize the entire array to be null to start
        for(loop=0;loop<spaces+2;loop++){
          toks[loop]=NULL;}

        int counter=0;

        //cut the string up into individual array indexes
        char *token=strtok(line, " :'\n''\t'");

        while(token!=NULL){
            toks[counter]=strdup(token);
            token=strtok(NULL, " :'\n''\t'");
            counter++;}

        toks[counter]=token;

        if(strcmp(toks[0], "exit") == 0){
            exit(0);}

        else if(strcmp(toks[0], "ls") == 0){

            int status;
            char *args[2];

            args[0] = "/bin/ls"; //first arg is the full path to the executable
            args[1] = NULL; //list of args must be NULL terminated

            if(fork()==0){
                execv(args[0], args);} //child: call execv with the path and the args
            else{
                wait(&status);} //parent: wait for the child
        }

        else if(strcmp(toks[0], "cd") == 0){

            if(toks[1] == NULL){
                chdir(getenv("HOME"));}

            else{
                if(chdir(toks[1]) == -1){
                    printf(" %s: No such file or directory\n", toks[1]);}
            }
        }

    }

    printf("\n");

return 0;
}

//Function Definition: clear
void clear(){

    printf("\033[H\033[J");

}

//Function Definition: display_prompt
void display_prompt(){

    //prompt: username
    char *username = getenv("USER");

    //prompt: hostname
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);

    //prompt: working_directory
    char temp[1024];
    char *working_directory = getcwd(temp, sizeof(temp));

    snprintf(prompt, sizeof(prompt), "%s@%s:%s $ ", username, hostname, working_directory);

}
