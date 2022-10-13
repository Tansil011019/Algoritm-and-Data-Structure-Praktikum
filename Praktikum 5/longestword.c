#include <stdio.h>
#include "wordmachine.h"

int main(){
    STARTWORD();
    int max= currentWord.Length;
    while (!endWord){
        if(max<currentWord.Length){
            max= currentWord.Length;
        }
        ADVWORD();
    } 
    printf("%d\n", max);
    return 0;
}