/* File: stacklinked.h */

#include <stdio.h>
#include "stacklinked.h"
#include "boolean.h"
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x){
    Address new_node= (Address) malloc (sizeof(Node));
    if(new_node != NULL){
        INFO(new_node)= x;
        NEXT(new_node)= NULL;
    }
    return new_node;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s){
    return (ADDR_TOP(s) == NULL);
}
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int length(Stack s){
    Address p= ADDR_TOP(s);
    int count= 0;
    while(p != NULL){
        count++;
        p= NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateStack(Stack *s){
    ADDR_TOP(*s)= NULL;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void DisplayStack(Stack s){
    printf("[");
    if(isEmpty(s)){
        printf("]");
    }else{
        Address p= ADDR_TOP(s);
        while(p != NULL){
            if(NEXT(p) == NULL){
                printf("%d]", INFO(p));
            }else{
                printf("%d,", INFO(p));
            }
            p= NEXT(p);
        }
    }
}
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */

void push(Stack *s, ElType x){
    Address p= newNode(x);
    if(p != NULL){
        if(!isEmpty(*s)){
            NEXT(p)= ADDR_TOP(*s);
        }
        ADDR_TOP(*s)= p;
    }
}
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Stack *s, ElType *x){
    Address p= ADDR_TOP(*s);
    *x= INFO(p);
    if(length(*s)==1){
        ADDR_TOP(*s)= NULL;
    }else{
        ADDR_TOP(*s)= NEXT(p);
    }
    free(p);
}
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
