#include <stdio.h>
#include "queuelinked.h"

int main(){
    int num_of_people;
    scanf("%d", &num_of_people);
    Queue q;
    CreateQueue(&q);
    int n= 0;
    int temp;
    int time= 0;
    int count= 0;
    while(n < num_of_people){
        int val;
        scanf("%d", &val);
        if(isEmpty(q)){
            enqueue(&q, val);
            temp= val;
            count++;
            printf("%d\n", count);
        }else{
            time+= val-temp;
            enqueue(&q, val);
            temp= val;
            count++;
            if(time > 300){
                time-=300;
                dequeue(&q, &val);
                count--;
            }
            printf("%d\n", count);
        }
        n++;
    }
    while(!isEmpty(q)){
        int val;
        dequeue(&q, &val);
    }
}