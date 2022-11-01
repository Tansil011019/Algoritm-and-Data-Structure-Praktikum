/* File : list_circular.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

#include <stdio.h>
#include "list_circular.h"
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l)==NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l)= NULL;
}
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address p= (Address) malloc (sizeof(ElmtList));
    if(p != NULL){
        INFO(p)= val;
        NEXT(p)= NULL;
    }
    return p;
}
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void deallocate(Address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    if(isEmpty(l)){
        return NULL;
    }else{
        Address p= FIRST(l);
        while(NEXT(p) != FIRST(l) && INFO(p) != val){
            p= NEXT(p);
        }
        if(INFO(p) == val){
            return p;
        }else{
            return NULL;
        }
    }
}
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p){
    if(isEmpty(l)){
        return false;
    }else{
        Address loc= FIRST(l);
        while(NEXT(loc) != FIRST(l) && loc != p){
            loc = NEXT(loc);
        }
        return loc == p;
    }
}
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p= allocate(val);
    Address last_loc= FIRST(*l);
    if(p!=NULL){
        if(isEmpty(*l)){
            NEXT(p)= p;
        }else{
            while(NEXT(last_loc) != FIRST(*l)){
                last_loc = NEXT(last_loc);
            }
            NEXT(p)= FIRST(*l);
            NEXT(last_loc)= p;
        }
        FIRST(*l)= p;
    }
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
void insertLast(List *l, ElType val){
    Address last_loc= FIRST(*l);
    if(isEmpty(*l)){
        insertFirst(l, val);
    }else{
        Address p= allocate(val);
        if(p != NULL){
            while(NEXT(last_loc) != FIRST(*l)){
                last_loc= NEXT(last_loc);
            }
            NEXT(last_loc)= p;
            NEXT(p) = FIRST(*l);
        }
    }
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
    Address p= FIRST(*l);
    *val= INFO(p);
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l)= NULL;
    }else{
        Address last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)){
            last= NEXT(last);
        }
        FIRST(*l)= NEXT(p);
        NEXT(last)= FIRST(*l);
    }
    deallocate(p);
}
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
void deleteLast(List *l, ElType * val){
    if(NEXT(FIRST(*l))== FIRST(*l)){
        deleteFirst(l, val);
    }else{
        Address last= FIRST(*l);
        Address prev_last= NULL;
        while(NEXT(last) != FIRST(*l)){
            prev_last= last;
            last= NEXT(last);
        }
        *val= INFO(last);
        NEXT(prev_last)= FIRST(*l);
        deallocate(last);
    }
}
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    printf("[");
    if(isEmpty(l)){
        printf("]");
    }else{
        Address p= FIRST(l);
        while(NEXT(p) != FIRST(l)){
            printf("%d,", INFO(p));
            p= NEXT(p);
        }
        if(NEXT(p) == FIRST(l)){
            printf("%d]", INFO(p));
        }
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
