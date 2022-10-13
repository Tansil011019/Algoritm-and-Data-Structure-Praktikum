/* File : prioqueuetime.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */


#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.h"


/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q){
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueTime Q){
    return (NBElmt(Q) == MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueTime Q){
    int count;
    if(IsEmpty(Q)){
        count=0;
    }else{
        count = (Tail(Q) >= Head(Q)) ? (Tail(Q) - Head(Q)+1): (Tail(Q)+MaxEl(Q)+1)-Head(Q); 
    }
    return count;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max){
    (Q)->T = (infotype*) malloc ((Max+1)*sizeof(infotype));
    if(IsEmpty(*Q)){
        MaxEl(*Q) = 0;
    }else{
        MaxEl(*Q) = Max;
    }
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q){
    free((Q)->T);
    MaxEl(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X){
    if(IsEmpty(*Q)){
        Head(*Q)++;
        Tail(*Q)++;
        InfoTail(*Q) = X;
        // printf("%d\n", Head(*Q));
    }else{
        if(!IsFull(*Q)){
            int temp_length = NBElmt(*Q);
            boolean identify = false;
            int temp_head= Head(*Q);
            // printf("%d\n", NBElmt(*Q));
            // printf("%d\n", Head(*Q));
            while (!identify && Head(*Q)<temp_length){
                if(Time(InfoHead(*Q)) > Time(X)){
                    identify= true;
                }else{
                    Head(*Q)++;
                }
                // printf("%d\n", Head(*Q));
            }
            if(identify){
                Tail(*Q)++;
                int temp_tail= Tail(*Q);
                while(Tail(*Q)!=Head(*Q)){
                    InfoTail(*Q) = Elmt(*Q, Tail(*Q)-1);
                    Tail(*Q)--;
                }
                InfoHead(*Q)= X;
                Tail(*Q)= temp_tail;
            }else{
                Tail(*Q)++;
                InfoTail(*Q) = X;
            }
            Head(*Q) = temp_head;
        }        
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueTime * Q, infotype * X){
    *X = InfoHead(*Q);
    if(NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil; 
    }else{
        Head(*Q)++;
        if(Head(*Q)>MaxEl(*Q)-1){
            Head(*Q)= 0;
        }
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q){
    int temp= Head(Q);
    if(IsEmpty(Q)){
        printf("#\n");
    }else{
        while(Head(Q)!=Tail(Q)){
            if(Head(Q)>MaxEl(Q)-1){
                Head(Q)= 0;
            }
            printf("%d %c\n", Time(InfoHead(Q)), Info(InfoHead(Q)));
            Head(Q)++;
        }
        printf("%d %c\n#\n", Time(InfoTail(Q)), Info(InfoTail(Q)));
        Head(Q) = temp;
    } 
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

