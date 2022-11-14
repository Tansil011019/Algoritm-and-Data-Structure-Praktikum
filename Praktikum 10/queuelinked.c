/* File: queuelinked.h */

#include <stdio.h>
#include "queuelinked.h"
#include "boolean.h"
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x){
    Address new_node = (Address) malloc(sizeof(Node));
    if(new_node != NULL){
        INFO(new_node)= x;
        NEXT(new_node)= NULL;
    }
    return new_node;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmpty(Queue q){
    return(ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int length(Queue q){
    int count= 0;
    Address p= ADDR_HEAD(q);
    while(p != NULL){
        count++;
        p= NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q){
    ADDR_HEAD(*q)= NULL;
    ADDR_TAIL(*q)= NULL;
}
/* I.S. sembarang */
void DisplayQueue(Queue q){
    printf("[");
    if(isEmpty(q)){
        printf("]");
    }else{
        Address p= ADDR_HEAD(q);
        while(p != NULL){
            if(p==ADDR_TAIL(q)){
                printf("%d]", INFO(p));
            }else{
                printf("%d,", INFO(p));
            }
            p= NEXT(p);
        }
    }
}
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
    Address p= newNode(x);
    if(p != NULL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q)= p;
        }else{
            NEXT(ADDR_TAIL(*q))= p;
        }
        ADDR_TAIL(*q)= p;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void dequeue(Queue *q, ElType *x){
    Address p= ADDR_HEAD(*q);
    *x= INFO(p);
    if(length(*q)==1){
        ADDR_HEAD(*q)= NULL;
        ADDR_TAIL(*q)= NULL;
    }else{
        ADDR_HEAD(*q)= NEXT(p);
    }
    NEXT(p)= NULL;
    free(p);    
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
