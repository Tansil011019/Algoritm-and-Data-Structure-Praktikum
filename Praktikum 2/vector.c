/* Nama: Wilson Tansil */
/* NIM: 13521054 */
/* Tanggal: 8 September 2022 */
/* Topik Praktikum: ADT Sederhana */
/* Deskripsi: ADT Vector */

#include "point.h"
#include <stdio.h>
#include "vector.h"
#include <math.h>


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
void CreateVector(VECTOR *v, float x, float y){
    CreatePoint(v, x, y);
}
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v){
    printf("<%.2f,%.2f>", Absis(v), Ordinat(v));
}
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v){
    return(Jarak0(v));
}
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
VECTOR Add(VECTOR a, VECTOR b){
    VECTOR result;
    Absis(result)=Absis(a)+Absis(b);
    Ordinat(result)=Ordinat(a)+Ordinat(b);
    return(result);
}
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
VECTOR Substract(VECTOR a, VECTOR b){
    VECTOR result;
    Absis(result)=Absis(a)-Absis(b);
    Ordinat(result)=Ordinat(a)-Ordinat(b);
    return(result);
}
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
float Dot(VECTOR a, VECTOR b){
    return((Absis(a)*Absis(b))+(Ordinat(a)*Ordinat(b)));
}
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
VECTOR Multiply(VECTOR v, float s){
    VECTOR result;
    Absis(result)=Absis(v)*s;
    Ordinat(result)=Ordinat(v)*s;
    return(result);
}
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * v.x, s * v.y) */

