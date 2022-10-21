#include <stdio.h>
#include "stack.h"
// #include "stack.c"
#include "string.h"
#include "boolean.h"

void reduction_result (int y, int x, int * burrow, Stack * S);
void remain (Stack * S_domain, int * burrow, Stack * S);

int main(){
    /*Kamus*/
    char first_num[100], second_num[100];
    Stack S1, S2, S1temp, S2temp, S;
    int burrow=0;
    boolean neg= false; /*negative identifier*/
    int length_result= 0; /*length for result stack*/
    boolean first_zero= true; /*check if the result have 0's in front*/

    /*Algoritma*/
    /*Construct*/
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S1temp);
    CreateEmpty(&S2temp);
    CreateEmpty(&S);

    /*Input*/
    scanf(" %s", first_num);
    scanf(" %s", second_num);
    for(int i=0; i<strlen(first_num); i++){
        int convert= first_num[i]-48; /*Convert to integer*/
        Push(&S1, convert);
    }
    for(int i=0; i<strlen(second_num); i++){
        int convert= second_num[i]-48; /*Convert to integer*/
        Push(&S2, convert);
    }

    /*Check if first number greater or smaller than second number*/
    // printf("%d\n", strlen(first_num));
    // printf("%d\n", strlen(second_num));
    int length_first= strlen(first_num);
    int length_second= strlen(second_num);
    if(length_second>length_first){
        neg= true;
    }else if(length_first == length_second){
        while(!IsEmpty(S1) && !IsEmpty(S2)){
            infotype x, y;
            Pop(&S1, &x);
            Pop(&S2, &y);
            Push(&S1temp, x);
            Push(&S2temp, y);
            x-=burrow;
            if(x<y && (length_first==1 || length_second==1)){
                neg= true;
            }
            if(x<y){
                burrow= 1;
            }else{
                burrow= 0;
            }
            length_first--;
            length_second--;
            // printf("%d\n", neg);
            // printf("%d\n", length_first);
            // printf("%d\n", length_second);
        }
    }

    burrow= 0; /*Reset burrow*/

    // printf("%d\n", neg);

    /*Refill lacking element of S1 and S2*/
    while(!IsEmpty(S1temp) && !IsEmpty(S2temp)){
        infotype x, y;
        Pop(&S1temp, &x);
        Pop(&S2temp, &y);
        Push(&S1, x);
        Push(&S2, y);
    }

    /*Reduction Operation*/
    while(!IsEmpty(S1) && !IsEmpty(S2)){
        infotype x, y;
        Pop(&S1, &x);
        Pop(&S2, &y);
        // printf("x= %d\n", x);
        // printf("y= %d\n", y);
        if(neg){
            reduction_result(y, x, &burrow, &S);
        }else{
            reduction_result(x, y, &burrow, &S);
        }
        length_result+=1;
    }
    // printf("%d\n", neg);

    /*Filling Remain*/
    while(!IsEmpty(S1)){
        remain(&S1, &burrow, &S);
        length_result+=1;
    }
    while(!IsEmpty(S2)){
        remain(&S2, &burrow, &S);
        length_result+=1;
    }

    /*Giving sign if the result negative*/
    if(neg){
        printf("-");
    }

    /*Print out result*/
    while(!IsEmpty(S)){
        infotype x;
        Pop(&S, &x);
        if(x==0 && length_result == 1 && first_zero){
            printf("0");/*if there is only zero in the result stack*/
        }else if(x==0 && first_zero){
            /*if there are 0's in front then do nothing (not print)*/
        }else{
            printf("%d", x);
            first_zero= false;
        }
        length_result--;
    }
    printf("\n");
}

/*Result reduction function*/
void reduction_result (int y, int x, int * burrow, Stack * S){
    y-=*burrow;
    if(y<x){
        *burrow=1;
        y+=10;
        // printf("%d\n", y);
    }else{
        *burrow= 0;
    }
    int result= y-x;
    // printf("%d\n", result);
    Push(S, result);
}

/*Filling remain function*/
void remain (Stack * S_domain, int * burrow, Stack * S){
    infotype x;
    Pop(S_domain, &x);
    x-=*burrow;
    if(x<0){
        x+=10;
        *burrow = 1;
    }else{
        *burrow = 0;
    }
    Push(S, x);
}