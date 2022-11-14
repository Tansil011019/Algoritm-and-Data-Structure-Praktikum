#include <stdio.h>
#include "charmachine.h"
#include "stacklinked.h"

void push_to_stack (Stack * s, int num, int * count){
    // printf("This is push num= %d\n", num);
    push(s, num);
    (*count)++;
    DisplayStack(*s);
    printf("\n");
}

void pop_from_stack (Stack * s, int * count, int * valid, int num){
    ElType val;
    if(!isEmpty(*s)){
        pop(s, &val);
        if(val != num){
            push(s, val);
        }else{
            // printf("This is pop num= %d\n", val);
            (*count)--;
        }
    }else{
        *valid= 0;
    }
    DisplayStack(*s);
    printf("\n");
}

int main(){
    Stack s;
    CreateStack(&s);
    int valid= 1;
    int count_siku= 0, count_bulat= 0, count_tegak= 0, count_kurawal= 0, count_segitiga= 0;
    int count= 0, max= count;
    do{
        START();
        if(currentChar != ' '){
            if(currentChar == '['){
                push_to_stack(&s, 0, &count);
                count_siku++;
            }else if(currentChar == '('){
                push_to_stack(&s, 1, &count);
                count_bulat++;
            }else if(currentChar == '|'){
                if(isEmpty(s)){
                    push_to_stack(&s, 2, &count);
                    count_tegak++;
                }else{
                    if(TOP(s) != 2){
                        push_to_stack(&s, 2, &count);
                        count_tegak++;
                    }else{
                        pop_from_stack(&s, &count, &valid, 2);
                    }
                }
            }else if(currentChar == '{'){
                push_to_stack(&s, 3, &count);
                count_kurawal++;
            }else if(currentChar == '<'){
                push_to_stack(&s, 4, &count);
                count_segitiga++;
            }else if(currentChar == ']'){
                pop_from_stack(&s, &count, &valid, 0);
            }else if(currentChar == ')'){
                pop_from_stack(&s, &count, &valid, 1);
            }else if(currentChar == '}'){
                pop_from_stack(&s, &count, &valid, 3);
            }else if(currentChar == '>'){
                pop_from_stack(&s, &count, &valid, 4);
            }
            // printf("This is current char= %c\n", currentChar);
        }
        if(max < count){
            max= count;
        }
    }while(currentChar != MARK);
    if(isEmpty(s) && valid){
        printf("kurung valid\n");
        printf("[%d] (%d) |%d| {%d} <%d>\n", count_siku, count_bulat, count_tegak, count_kurawal, count_segitiga);
        printf("MAX %d\n", max);
    }else{
        printf("kurung tidak valid\n");
    }
    return 0;
}