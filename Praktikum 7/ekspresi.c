#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"
#include <math.h>
#include <stdlib.h>

boolean Operator(char x);
int operation (int x, int y, char operator);
int convert(char cc);


int main(){
    /*Kamus*/
    Stack S;
    int current_num= 0;

    /*Algoritma*/
    /*Constructor*/
    CreateEmpty(&S);

    STARTWORD();
    if(endWord){/*if there is no expression*/
        printf("Ekspresi kosong\n");
    }else{
        while(!endWord){
            /*Operate*/
            if(Operator(currentWord.TabWord[0])){
                infotype x, y;
                Pop(&S, &x);
                Pop(&S, &y);
                // if(currentWord.TabWord[0]=='/'){
                //     printf("%d\n", y/x);
                // }
                printf("%d %c %d\n", y, currentWord.TabWord[0], x);
                int result= operation(y, x, currentWord.TabWord[0]);
                printf("%d\n", result);
                Push(&S, result);
            }else{/*Fill Stack*/
                for(int i= 0; i< currentWord.Length; i++){
                    int temp_num= convert(currentWord.TabWord[i]);
                    // printf("%c\n", currentWord.TabWord[i]);
                    if(i!=0){
                        current_num *=10;
                    }
                    // printf("%d\n", temp_num);
                    current_num += temp_num;
                }
                printf("%d\n", current_num);
                Push(&S, current_num);
                current_num=0;
                // printf("%d\n", current_num);
            }
            ADVWORD();
        }
    }
    /*Remain = Final Result*/
    while(!IsEmpty(S)){
        infotype x;
        Pop(&S, &x);
        printf("Hasil=%d\n", x);
    }
}

/*Check Operator*/
boolean Operator(char x){
    return (x=='+' || x=='-' || x=='/' || x=='*' || x=='^');
}

/*Operation Process*/
int operation (int x, int y, char operator){
    /*Kamus*/
    int result;

    /*Algoritma*/
    switch (operator){
        case '+': result= x+y;
        break;
        case '-': result= x-y;
        break;
        case '/': result= ((double)x/(double)y);
        break;
        case '*': result= x*y;
        break;
        case '^': result= pow(x, y);
        break;
    }

    return result;
}

/*Integer Converter*/
int convert(char cc){
    return (cc-48);
}