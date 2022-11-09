#include <stdio.h>
#include "stacklinked.h"

void process(int N, Stack * s){
    int count= 0;
    while(count < N){
        int val;
        scanf("%d", &val);
        if(val == 0){
            if(!isEmpty(*s)){
                pop(s, &val);
            }
        }else{
            push(s, val);
        }
        count++;
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    Stack s1, s2;
    CreateStack(&s1);
    CreateStack(&s2);
    process(N, &s1);
    process(M, &s2);
    boolean same= true;
    while(!isEmpty(s2) && !isEmpty(s1)){
        int val1, val2;
        pop(&s1, &val1);
        pop(&s2, &val2);
        if(val1 != val2){
            same= false;
        }
    }
    if(!isEmpty(s1) || !isEmpty(s2)){
        same= false;
    }
    if(same){
        printf("Sama");
    }else{
        printf("Tidak Sama");
    }
}