#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#ifndef TypingGame_H
#define TypingGame_H

void TypingGame(void){

system("clear");
// the word bank
const char* realWords[] = {
    "might", "govern", "take", "you", "need", "child", "we", "move", "time", "present",
    "at", "come", "day", "one", "become", "home", "way", "world", "look", "life",
    "know", "people", "work", "use", "find", "give", "tell", "ask", "try", "call",
    "own", "end", "should", "great", "place", "year", "government", "company", "part", "problem",
    "fact", "right", "power", "often", "long", "country", "friend", "school", "group", "father",
    "mother", "hand", "old", "place", "big", "small", "live", "thought", "few", "put",
    "understand", "point", "leave", "name", "world", "high", "seem", "important", "different", "next",
    "early", "young", "open", "until", "example", "beautiful", "agree", "money", "however", "body",
    "above", "bit", "book", "music", "game", "keep", "eye", "mind", "face", "side",
    "heart", "door", "idea", "head", "food", "foot", "city", "side", "state", "word",
};


int getNumRealWords(){
    return sizeof(realWords) / sizeof(realWords[0]);
}

const char* getRandomRealWord() {
    int index = rand() % getNumRealWords();
    return realWords[index];
}


    srand(time(NULL));

    
    int count = 0;
    while (count < 25){
        for (int i = 0; i < 10; ++i) {  
            const char* randomRealWord = getRandomRealWord();
            char RandomWordTypeThingIDK[1000];
            printf("Type: %s\n ~> ",randomRealWord);
            scanf("%s", RandomWordTypeThingIDK);
            system("clear");
            count++;
            if (count >= 25) {
                break;
            }
        }
        
    }

}

#endif 


