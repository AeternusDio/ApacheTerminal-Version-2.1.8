#include <stdio.h>
#include <string.h>

void quack() {
    printf("quack\n");
}

#ifndef QuackCodeDebugger_H
#define QuackCodeDebugger_H

void QuackCodeDebugger(void) {

    char usrInput[2000]; 
    printf("\nEnter the issue you are dealing with: ");

    while (1) { 
        fgets(usrInput, sizeof(usrInput), stdin);
        usrInput[strcspn(usrInput, "\n")] = 0;  

        if (strcmp(usrInput, "quit") == 0) {
            break;  
        }

        quack();
        printf("Enter the issue you are dealing with: ");
    }

}

#endif
