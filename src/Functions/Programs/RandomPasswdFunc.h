#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#ifndef RandomPasswdFunc_H
#define RandomPasswdFunc_H


void RandomPasswd(void) {

    
    const char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand((unsigned int)time(NULL));
    int passwordLength = 12;
    char password[passwordLength + 1];

    for (int i = 0; i < passwordLength; ++i) {
        int index = rand() % (sizeof(characters) - 1);
        password[i] = characters[index];
    }

    password[passwordLength] = '\0';

    system("clear");
    printf("Generated Password: %s\n", password);
    

}



#endif
