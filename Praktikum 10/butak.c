#include <stdio.h>
#include "queuelinked.h"
#include "charmachine.h"
char currentChar;
boolean EOP;


int main(){
    Queue q1, q2, q3;
    CreateQueue(&q1);
    CreateQueue(&q2);
    CreateQueue(&q3);
    boolean next= false;
    int n= 0;
    START();
    while(!EOP){
        if(currentChar == ','){
            for(int i= 1; i<=n; i++){
                enqueue(&q3, i);
            }
            next= true;
        }else{
            if(next){
                if(currentChar == 'B'){
                    enqueue(&q2, 0);
                }else if(currentChar == 'K'){
                    enqueue(&q2, 1);
                }
            }else{
                if(currentChar == 'B'){
                    enqueue(&q1, 0);
                }else if(currentChar == 'K'){
                    enqueue(&q1, 1);
                }
                n++;
            }
        }
        ADV();
    }
    // boolean cant_move = false;
    int count= 0;
    ElType val1, val2, val, val3, val_temp;
    while(!isEmpty(q1) && count < length(q3)){
        // DisplayQueue(q1);
        // DisplayQueue(q2);
        // DisplayQueue(q3);
        // printf("\n");
        if(HEAD(q1) == HEAD(q2)){
            dequeue(&q1, &val1);
            dequeue(&q2, &val2);
            dequeue(&q3, &val3);
            if(val2 == 0){
                printf("%d -> bulat\n", val3);
            }else if(val2 == 1){
                printf("%d -> kotak\n", val3);
            }
            count= 0;
        }else{
            dequeue(&q1, &val);
            dequeue(&q3, &val_temp);
            enqueue(&q1, val);
            enqueue(&q3, val_temp);
            count++;
        }
    }
    printf("%d\n", length(q1));
    return 0;
}