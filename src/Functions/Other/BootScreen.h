#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef BootScreen_H
#define BootScreen_H

void BootScreen(void) {

    const char *BootScreen = 
    ""
    "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
    "┃         _                         ┃\n"
    "┃        / /                        ┃\n"
    "┃       / /  \\                      ┃\n"
    "┃      / / /\\ \\                     ┃\n" 
    "┃     / / /\\ \\ \\                    ┃\n" 
    "┃    / / /  \\ \\ \\                   ┃\n"
    "┃   / / /___/ /\\ \\                  ┃\n"
    "┃  / / /_____/ /\\ \\                 ┃\n"
    "┃ / /_________/\\ \\ \\                ┃\n"
    "┃/ / /_       __\\ \\_\\               ┃\n"
    "┃\\_\\___\\     /_____/__/             ┃\n"
    "┃ApacheTerminal                     ┃\n"
    "┃Written by Longnecklion000         ┃\n"
    "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
    "";

    printf("%s", BootScreen);
    fflush(stdout); // Flush the output buffer

    int i;
    for (i = 0; i < 100; i++) {
        printf("\rInitializing Modules.....%d", i + 1);
        fflush(stdout); // Flush the output buffer
        usleep(50000); // Wait for 50 milliseconds
    }
    printf("\nInitialization Complete\n");
    usleep(2000000); // Wait for 2 seconds

    
    for (i = 0; i < 100; i++) {
        printf("\rBeginning Final Boot Protocol.....%d\b", i + 1); // Modify this line
        fflush(stdout); // Flush the output buffer
        usleep(50000); // Wait for 50 milliseconds
    }

}

#endif

