#include <stdio.h>
#include "listrec.h"

void displayListmain(List l){
    if(isOneElmt(l)){
        printf("%d", INFO(l));
    }else{
        printf("%d ", INFO(l));
        displayListmain(tail(l));
    }
}

List get_input_in_order(int point){
    int val;
    if(point!=0){
        scanf("%d", &val);
        return konsb(get_input_in_order(point-1), val);
    }else{
        return NULL;
    }
}

int main(){
    int length, point;
    scanf("%d %d", &length, &point);
    int count= 0;
    while(count < length){
        if(length > count+point){
            List l2= get_input_in_order(point);
            displayListmain(l2);
            count+=point;
        }else{
            List l2= get_input_in_order(length-count);
            displayListmain(l2);
            count = length;
        }
        if(count != length){
            printf(" ");
        }
    }
    printf("\n");
}