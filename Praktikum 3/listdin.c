/* Nama: Wilson Tansil */
/* NIM: 13521054 */
/* Tanggal: 11/09/2022 */
/* Topik: ADT List Statik dan Dinamik */

#include "boolean.h"
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
   CAPACITY(*l)= capacity;
   NEFF(*l)= 0;
   BUFFER(*l)= (int*) malloc (capacity*sizeof(int));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l){
   CAPACITY(*l)= 0;
   NEFF(*l)= 0;
   free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
   return(NEFF(l));
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
   return (0);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l){
   return(NEFF(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
   return(i>=0 && i<CAPACITY(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
   return(i>=0 && i<NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
   return(NEFF(l)==0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
   return(NEFF(l)==CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
   int n, i;
   do{
      scanf("%d", &n);
   }while(n<0 || n>CAPACITY(*l));
   NEFF(*l)=n;
   // CreateListDin(l, CAPACITY);
   if(n!=0){
      int get_number;
      for(i =0; i<n; i++){
         scanf("%d", &get_number);
         ELMT(*l, i)= get_number;
      }
   }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l){
   int i;
   if(isEmpty(l)){
      printf("[]");
   }else{
      for(i=0; i<NEFF(l); i++){
         if(i==NEFF(l)-1){
            printf("%d]", ELMT(l, i));
         }
         else if (i == 0){
            printf("[%d,", ELMT(l, i));
         }
         else{
            printf("%d,", ELMT(l, i));
         }
      }
   }
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
   ListDin result_list;
   CreateListDin(&result_list, CAPACITY(l1));
   NEFF(result_list)= NEFF(l1);
   if(plus){
      int i;
      for(i=0; i<NEFF(l1); i++){
         ELMT(result_list, i)= ELMT(l1, i)+ELMT(l2, i);
      }
   }else{
      int i;
      for(i=0; i<NEFF(l1); i++){
         ELMT(result_list, i)= ELMT(l1, i)-ELMT(l2, i);
      }
   }
   return (result_list);
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
   boolean equal = true;
   if(NEFF(l1)==NEFF(l2)){
      int i=0;
      while (equal && i<NEFF(l1)){
         if(ELMT(l1, i)!=ELMT(l2, i)){
            equal = false;
         }
         i++;
      }
   }else{
      equal = false;
   }
   return(equal);
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
   IdxType i;
   if(isEmpty(l)){
      return IDX_UNDEF;
   }
   for (i=0; i<NEFF(l); i++){
      if(ELMT(l, i) == val){
         return i;
      }
   }
   return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
   int i;
   *max= ELMT(l, 0); 
   *min = ELMT(l, 0);
   for(i=0; i<NEFF(l); i++){
      if(ELMT(l, i)<*min){
         *min = ELMT(l, i);
      }else if (ELMT(l, i)>*max){
         *max = ELMT(l, i);
      }
   }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
   CAPACITY(*lOut)= CAPACITY(lIn);
   NEFF(*lOut) = NEFF(lIn);
   CreateListDin(lOut, CAPACITY(lIn));
   int i;
   for(i=0; i<NEFF(lIn); i++){
      ELMT(*lOut, i) = ELMT(lIn, i);
   }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l){
   ElType result = 0;
   int i;
   for(i=0; i<NEFF(l); i++){
      result += ELMT(l, i);
   }
   return result;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
   int i, result= 0;
   for(i=0; i<NEFF(l); i++){
      if(ELMT(l, i)==val){
         result+=1;
      }
   }
   return(result);
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
   if(asc){
      boolean sorted = false;
      int temp, max_idx = NEFF(*l)-1;
      while (!sorted){
         sorted=true;
         int i;
         for(i=0; i<max_idx; i++){
            if(ELMT(*l, i)>ELMT(*l, i+1)){
               temp = ELMT(*l, i);
               ELMT(*l, i)=ELMT(*l, i+1);
               ELMT(*l, i+1) = temp;
               sorted = false;
            }
         }
         max_idx-=1;
      }
   }else{
      boolean sorted = false;
      int temp, max_idx = NEFF(*l)-1;
      while (!sorted){
         sorted=true;
         int i;
         for(i=0; i<max_idx; i++){
            if(ELMT(*l, i)<ELMT(*l, i+1)){
               temp = ELMT(*l, i);
               ELMT(*l, i)=ELMT(*l, i+1);
               ELMT(*l, i+1) = temp;
               sorted = false;
            }
         }
         max_idx-=1;
      }
   }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
   ELMT(*l, NEFF(*l))= val;
   NEFF(*l)+=1;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
   *val = ELMT(*l, NEFF(*l)-1);
   NEFF(*l)-=1;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
   CAPACITY(*l)+=num;
   BUFFER(*l)= (int*) realloc (BUFFER(*l), sizeof(int)*CAPACITY(*l));
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
   CAPACITY(*l)-=num;
   BUFFER(*l)= (int*) realloc (BUFFER(*l), sizeof(int)*CAPACITY(*l));
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
   CAPACITY(*l)= NEFF(*l);
   BUFFER(*l)= (int*) realloc (BUFFER(*l), sizeof(int)*CAPACITY(*l));
}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

