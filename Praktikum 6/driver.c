#include <stdio.h>
#include "prioqueuetime.h"
#include "prioqueuetime.c"

int main(){
    PrioQueueTime q;
    MakeEmpty(&q, 10);
    infotype num, num1, num2, num3, val;
    Time(num) = 95;
    Info(num) = 'b';
    Time(num1) = 90;
    Info(num1) = 'a';
    Time(num2) = 100;
    Info(num2) = 'c';
    Time(num3) = 97;
    Info(num3) = 'c';
    // printf("%d\n", IsEmpty(q));
    // printf("%d\n", IsFull(q));
    // printf("%d\n", MaxEl(q));
    // printf("%d\n", NBElmt(q));
    Enqueue(&q, num);
    // printf("%d\n", IsEmpty(q));
    // printf("%d\n", IsFull(q));
    // printf("%d\n", MaxEl(q));
    // printf("%d\n", NBElmt(q));
    Enqueue(&q, num1);
    // printf("%d\n", IsEmpty(q));
    // printf("%d\n", IsFull(q));
    // printf("%d\n", MaxEl(q));
    // printf("%d\n", NBElmt(q));
    Enqueue(&q, num2);
    Enqueue(&q, num3);
    // Dequeue(&q, &val);
    // Dequeue(&q, &val);
    // Dequeue(&q, &val);
    PrintPrioQueueTime(q);
    DeAlokasi(&q);
}