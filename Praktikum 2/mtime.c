/* Nama: Wilson Tansil */
/* NIM: 13521054 */
/* Tanggal: 8 September 2022 */
/* Topik Praktikum: ADT Sederhana */
/* Deskripsi: Main program time */

#include <stdio.h>
#include "time.h"
// #include "time.c"

int main(){
    int chances, indeks;
    long max, min;
    // long min, max;
    // Tawal= T1;
    // Takhir=T1;
    // min=TIMEToDetik(T1);
    // max=TIMEToDetik(T1);
    indeks=1;
    scanf("%d", &chances);
    while(chances>0){
        TIME T1, T2;
        printf("[%d]\n", indeks);
        BacaTIME(&T1);
        BacaTIME(&T2);
        printf("%ld\n", (TGT(T1, T2) ? Durasi(T2, T1) : Durasi(T1, T2)));
        if (indeks == 1){
            min = TIMEToDetik(T1);
            max = TIMEToDetik(T2);
        }
        if (TIMEToDetik(T1) < min){
            min = TIMEToDetik(T1);
        }
        if (TIMEToDetik(T2) < min){
            min = TIMEToDetik(T2);
        }
        if (TIMEToDetik(T1) > max){
            max = TIMEToDetik(T1);
        }
        if (TIMEToDetik(T2) > max){
            max = TIMEToDetik(T2);
        }
        indeks +=1;
        chances -=1;
        }
        TulisTIME(DetikToTIME(min));
        printf("\n");
        TulisTIME(DetikToTIME(max));
        printf("\n");
        return 0;
    }
    

  
// [0:37 pm, 08/09/2022] Jeffrey Chow: // Nama : Jeffrey Chow
// // NIM : 13521046
// // Tanggal : 8 September 2022
// // Topik Praktikum : ADT Sederhana
// // Deskripsi : ADT VECTOR

// #include "time.h"
// #include <stdio.h>

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     TIME T1;
//     TIME T2;
//     TIME MAX;
//     TIME MIN;

//     int i = 1;
//     while (i <= n)
//     {
//         printf("[%d]\n", i);

//         BacaTIME(&T1);
//         BacaTIME(&T2);

//         TIME TAw;
//         TIME TAkh;
//         int t1 = TIMEToDetik(T1);
//         int t2 = TIMEToDetik(T2);

//         if (t2 >= t1)
//         {
//             TAw = T1;
//             TAkh = T2;
//         }
//         else
//         {
//             TAw = T2;
//             TAkh = T1;
//         }

//         if (i == 1)
//         {
//             MAX = TAkh;
//             MIN = TAw;
//         }

//         if (TIMEToDetik(TAkh) > TIMEToDetik(MAX))
//         {
//             MAX = TAkh;
//         }

//         if (TIMEToDetik(TAw) < TIMEToDetik(MIN))
//         {
//             MIN = TAw;
//         }

//         printf("%d\n", Durasi(TAw, TAkh));

//         i++;
//     }
//     TulisTIME(MIN);
//     printf("\n");
//     TulisTIME(MAX);
//     printf("\n");
//     return 0;
// }
