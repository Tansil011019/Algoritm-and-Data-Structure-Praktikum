/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>


Address newNode(ElType val){
    Address p = (Address) malloc (sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */


/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    Address p;
    int count= 0;
    p= FIRST(l);
    while(count<idx){
        p= NEXT(p);
        count++;
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    Address p;
    int count= 0;
    p= FIRST(*l);
    while(count<idx){
        p= NEXT(p);
        count++;
    }
    INFO(p)= val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    Address p;
    int count= 0;
    p =FIRST(l);
    boolean found= false;
    while (p != NULL && !found){
        if(INFO(p) == val){
            found= true;
        }else{
            count++;
            p= NEXT(p);
        }
    }
    if (found){
        return count;
    }else{
        return IDX_UNDEF;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p;
    p= newNode(val);
    if(p != NULL){
        NEXT(p)= *l;
        *l= p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address p, last;
    if (isEmpty(*l)) {
        insertFirst(l, val);
    }else{
        p= newNode(val);
        if(p!=NULL){
            last = FIRST(*l);
            while(NEXT(last) != NULL){
                last= NEXT(last);
            }
            NEXT(last)= p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    Address p, loc;
    int count= 0;
    if(idx == 0){
        insertFirst(l, val);
    }else{
        p= newNode(val);
        if(p != NULL){
            loc= FIRST(*l);
            while(count < idx-1){
                count++;
                loc= NEXT(loc);
            }
            NEXT(p)= NEXT(loc);
            NEXT(loc)= p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p;
    p= FIRST(*l);
    *val= INFO(p);
    FIRST(*l)= NEXT(p);
    free(p); 
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address p, last;
    p= FIRST(*l);
    last= NULL;
    while (NEXT(p) != NULL){
        last= p;
        p= NEXT(p);
    }
    if(last == NULL){ /*Jika list hanya memiliki 1 elemen*/
        deleteFirst(l,val);
    }else{
        NEXT(last)= NULL;
        *val= INFO(p);
        free(p);
    }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    Address p, loc;
    int count= 0;
    if(idx== 0){ /*Jika ingin menghapus elemen pertama pada list*/
        deleteFirst(l, val);
    }else{
        loc= FIRST(*l);
        while (count < idx-1){
            count++;
            loc= NEXT(loc);
        }
        p= NEXT(loc);
        NEXT(loc)= NEXT(p);
        *val= INFO(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address p;
    printf("[");
    p= FIRST(l);
    if(isEmpty(l)){
        printf("]");
    }else{
        while(p != NULL){
            if(NEXT(p)== NULL){
                printf("%d]", INFO(p));
            }else{
                printf("%d,", INFO(p));
            }
            p= NEXT(p);
        }
    }
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int count= 0;
    Address p;
    p= FIRST(l);
    while (p != NULL){
        count++;
        p= NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p;
    /*Concat l1 ke l3*/
    p= FIRST(l1);
    while(p!=NULL){
        insertLast(&l3, INFO(p));
        p= NEXT(p);
    }
    /*Concat l2 ke l3*/
    p= FIRST(l2);
    while(p!=NULL){
        insertLast(&l3, INFO(p));
        p= NEXT(p);
    }
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
