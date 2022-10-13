#include <stdio.h>
#include "prioqueuetime.h"
// #include "prioqueuetime.c"


//Produk Gagal
int main(){
    int process;
    PrioQueueTime process_q;
    infotype input_info;
    // infotype storage[200], output_storage[200];
    int temp_time= 0, temp=0;
    scanf("%d", &process);
    // infotype final[process];
    // MakeEmpty(&q, process);
    MakeEmpty(&process_q, process);
    // int j=0;
    for(int i=0; i<process; i++){
        scanf("%d %c", &Time(input_info), &Info(input_info));
        // storage[i] = input_info;
        Enqueue(&process_q, input_info);
        // Enqueue(&q, input_info);
        // printf("%d %d\n", i, temp_time);
        // if(i== temp_time){
        //     Dequeue(&process_q, &input);
        //     temp= Time(input);
        //     Time(input) = temp_time;
        //     Enqueue(&q, input);
        //     temp_time += temp;
        // }
        if(temp==0){
            Dequeue(&process_q, &input_info);
            printf("%d %c\n", temp_time, Info(input_info));
            temp= Time(input_info);
            // Time(input_info) = temp_time;
            temp_time+=temp;
            // j++;
        }
        temp--;
        // printf("\n");
        // PrintPrioQueueTime(process_q);
        // printf("\n");
        // PrintPrioQueueTime(q);
    }
    // PrintPrioQueueTime(process_q);
    // int residual_length = NBElmt(process_q);
    // for(int i=0; i<residual_length; i++){
    //     Dequeue(&process_q, &input_info);
    //     printf("%d %c\n", temp_time, Info(input_info));
    //     temp= Time(input_info);
    //     // Time(input_info) = temp_time;
    //     // final[j]= input_info;
    //     temp_time += temp;
    //     // j++;
    // }
    while(!IsEmpty(process_q)){
        Dequeue(&process_q, &input_info);
        printf("%d %c\n", temp_time, Info(input_info));
        temp= Time(input_info);
        temp_time += temp;
    }
    // PrintPrioQueueTime(q);
    //print phrase
    // for(int i=0; i<process; i++){
    //     printf("%d %c\n", Time(final[i]), Info(final[i]));
    // }
    // int temp_print= Head(q);
    // while(Head(q)!=Tail(q)){
    //     if(Head(q)>MaxEl(q)-1){
    //         Head(q)= 0;
    //     }
    //     printf("%d %c\n", Time(InfoHead(q)), Info(InfoHead(q)));
    //     Head(q)++;
    // }
    // printf("%d %c\n", Time(InfoTail(q)), Info(InfoTail(q)));
    // Head(q) = temp_print; 
    // DeAlokasi(&q);
    DeAlokasi(&process_q);
    return 0;
    // for(int i=0; i<process; i++){
    //     printf("%d %c\n", Time(storage[i]), Info(storage[i]));
    // }
    // int max_time= 0;
    // for(int i=0; i<process; i++){
    //     max_time += Time(storage[i]);
    // }
    // // printf("%d\n", max_time);
    // for(int i= 0; i<max_time; i++){
    //     if(i==0){
    //         temp= Time(storage[i]);

    //         Enqueue(&q, storage[i]);
    //     }
    // }
}