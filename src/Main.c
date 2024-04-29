#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

char filename[100];
char filename[MAX_FILENAME_LENGTH];
char content[MAX_CONTENT_LENGTH];

#include "Functions/Programs/Calculator.h"
#include "Functions/Programs/QuackCodeDebugger.h"
#include "Functions/Programs/RandomPasswdFunc.h"
#include "Functions/Programs/TypingGame.h"
#include "Functions/Other/BootScreen.h"

void initializeReadline() {
    
    using_history();
    char *histfile = ".shell_history";
    read_history(histfile);
    stifle_history(1000); 
}

void saveCommandToHistory(const char *command) {
    if (command && *command) {
        add_history(command);
        write_history(".shell_history");
    }
}

int main(int argc, char* argv[]) {

    srand(time(NULL));
    int randomNumber = rand() % 2 + 1;
    
    if(randomNumber == 1) {
        
        system("clear");
        BootScreen();

    }

    system("clear");

    initializeReadline();

    char path[5000];
    realpath(__FILE__, path);

    char dir[5000];
    getcwd(dir, sizeof(dir)); 

    int isFirstPrint = 1;
    DIR *directory;
    struct dirent *entry;

    while (1) {

        if (isFirstPrint) {
            printf("\n/User%s\n> ", dir);
            isFirstPrint = 0;
        }

        char *Commands = readline("");

        if (Commands && *Commands) {
            saveCommandToHistory(Commands);
        }

        if (Commands[strlen(Commands) - 1] == '\n') {
            Commands[strlen(Commands) - 1] = '\0';
        }

        if (strncmp(Commands, "make love", 9) == 0) {
            printf("Not War.\n");
            isFirstPrint = 1;

        } else if (strncmp(Commands, "make ", 5) == 0) {
            char fileName[100];
            strcpy(fileName, Commands + 5);
            FILE *filePtr = fopen(fileName, "w");

            if (filePtr == NULL) {
                printf("Error: Unable to create the file.\n");
                isFirstPrint = 1;
            } else {
                fclose(filePtr);
                printf("File '%s' created successfully.\n", fileName);
            }
            isFirstPrint = 1;

        } else if (strcmp(Commands, "lf") == 0) {
            directory = opendir(".");

            if (directory == NULL) {
                perror("Unable to open directory");
                exit(EXIT_FAILURE);
            }

            while ((entry = readdir(directory)) != NULL) {
                printf("%s\n", entry->d_name);
            }

            closedir(directory);
            isFirstPrint = 1;
        } else if (strncmp(Commands, "cd ", 3) == 0) {

            char* directory = Commands + 3; 
            char *newline = strchr(directory, '\n');

            if (newline) {
                *newline = '\0';
            }

            if (chdir(directory) != 0) {
                printf("Failed to change directory to '%s'\n", directory);
                isFirstPrint = 1;
            } else {
                getcwd(dir, sizeof(dir)); 
            }

            isFirstPrint = 1;

        } else if (strcmp(Commands, "-cd") == 0) {
            if (chdir("..") != 0) {
                printf("Failed to go back a directory.\n");
            } else {
                getcwd(dir, sizeof(dir)); 
            }

            isFirstPrint = 1;
        } else if (strncmp(Commands, "say", 3) == 0) {
            printf("%s\n", &Commands[4]); 
            isFirstPrint = 1;

        } else if (strncmp(Commands, "random password", 5) == 0) {

            RandomPasswd();
            isFirstPrint = 1;

        } else if (strncmp(Commands, "makedir ", 8) == 0) {

            char dirName[100];
            strcpy(dirName, Commands + 8);


            if (mkdir(dirName, 0777) == -1) {

                printf("Error: Unable to create the directory.\n");

            }

            printf("Directory '%s' created successfully.\n", dirName);
            isFirstPrint = 1;

        } else if (strncmp(Commands, "rm", 2) == 0) {
          sscanf(Commands, "%*s %s", filename);

          char rm_command[200];
          sprintf(rm_command, "rm -r %s", filename);

          int status = system(rm_command);

          if (status == 0) {
              printf("File or directory '%s' successfully deleted.\n", filename);
              isFirstPrint = 1;

          } else {

              printf("Error: Failed to delete file or directory '%s'.\n", filename);
              isFirstPrint = 1;

          }

        } else if (strncmp(Commands, "con", 3) == 0) {
          sscanf(Commands, "%*s %s", filename);

          FILE *file = fopen(filename, "r");

          if (file != NULL) {
              while (fgets(content, sizeof(content), file) != NULL) {
                  printf("%s", content);
                  isFirstPrint = 1;
              }

              fclose(file);
          } else {
              printf("Error: Unable to open file '%s'.\n", filename);
              isFirstPrint = 1;
          }

        } else if (strncmp(Commands, "calculator", 5) == 0) {

            Calculator();
            isFirstPrint = 1;

        } else if (strncmp(Commands, "debugger", 5) == 0) {

            QuackCodeDebugger();
            isFirstPrint = 1;

        } else if (strncmp(Commands, "type game", 5) == 0) {

            TypingGame();
            isFirstPrint = 1;        

        } else if (strncmp(Commands, "atm cd", 6) == 0) {

             const char *cdcommand = "man ./Functions/Manuals/CD-Manual.1";
             system(cdcommand);
             isFirstPrint = 1;

        } else if (strncmp(Commands, "atm con", 6) == 0) {

             const char *concommand = "man ./Functions/Manuals/CON-Manual.1";
             system(concommand);
             isFirstPrint = 1;

        } else if (strncmp(Commands, "atm rm", 6) == 0) {

             const char *rmcommand = "man ./Functions/Manuals/RM-Manual.1";
             system(rmcommand);
             isFirstPrint = 1;

        } else if (strncmp(Commands, "atm say", 6) == 0) {

             const char *saycommand = "man ./Functions/Manuals/SAY-Manual.1";
             system(saycommand);
             isFirstPrint = 1;     

        } else if (strncmp(Commands, "atm lf", 6) == 0) {

             const char *lfcommand = "man ./Functions/Manuals/LF-Manual.1";
             system(lfcommand);
             isFirstPrint = 1;

        } else if (strncmp(Commands, "atm make", 8) == 0) {

            const char *makecommand = "man ./Functions/Manuals/MAKE-Manual.1";
            system(makecommand);
            isFirstPrint = 1;

        } else if (strncmp(Commands, "clear", 5) == 0) {

            system("clear");
            isFirstPrint = 1;

        } else if (strncmp(Commands, "shutdown", 5) == 0) {

            exit(0);

        } else {

            printf("Invalid command\n");
            isFirstPrint = 1;

        }

    }

    return 0;
}

