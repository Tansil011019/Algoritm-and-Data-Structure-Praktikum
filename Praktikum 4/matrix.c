/* Nama: Wilson Tansil */
/* NIM: 13521054 */
/* Tanggal: 20/09/2022 */
/* Topik: ADT Matrix */

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return(i<ROW_CAP && j<COL_CAP && i>=0 && j>=0);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return(ROW_EFF(m)-1);
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
    return(COL_EFF(m)-1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return(i<ROW_EFF(m) && j<COL_EFF(m) && i>=0 && j>=0);
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i){
    return(ELMT(m, i, i));
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    // ROW_EFF(*mOut)=ROW_EFF(mIn);
    // COL_EFF(*mOut)= COL_EFF(mIn);
    // int i, j;
    // for(i=0; i<ROW_EFF(*mOut); i++){
    //     for(j=0; j<COL_EFF(*mOut); j++){
    //         ELMT(*mOut, i, j)=ELMT(mIn, i, j);
    //     }
    // }
    *mOut = mIn;
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow, nCol, m);
    int i, j;
    for(i=0; i< nRow; i++){
        for(j=0; j<nCol; j++){
            int get_number;
            scanf("%d", &get_number);
            ELMT(*m, i, j) = get_number;
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    int i, j;
    for ( i = 0; i < ROW_EFF(m); i++){
        for ( j = 0; j < COL_EFF(m); j++){
            printf("%d", ELMT(m, i, j));
            if(j!= COL_EFF(m)-1){
                printf(" ");
            }
        }
        printf("\n"); 
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix result_m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &result_m);
    int i, j;
    for(i=0; i<ROW_EFF(result_m); i++){
        for(j=0; j<COL_EFF(result_m); j++){
            ELMT(result_m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return result_m;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix result_m;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &result_m);
    int i, j;
    for(i=0; i<ROW_EFF(result_m); i++){
        for(j=0; j<COL_EFF(result_m); j++){
            ELMT(result_m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return result_m;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix result_m;
    int count=0;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &result_m);
    int i, j, k;
    for(i=0; i<ROW_EFF(m1); i++){
        for(j=0; j<COL_EFF(m2); j++){
            for(k=0; k<ROW_EFF(m2); k++){
                count += (ELMT(m1, i, k) * ELMT(m2, k, j));
            }
            ELMT(result_m, i, j) = count;
            count =0;
        }
    }
    return result_m;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyByConst(Matrix m, ElType x){
    Matrix result_m;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result_m);
    int i, j;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            ELMT(result_m, i, j) = ELMT(m, i, j) * x;
        }
    }
    return result_m;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
    int i, j;
    for(i=0; i<ROW_EFF(*m); i++){
        for(j=0; j<COL_EFF(*m); j++){
            ELMT(*m, i, j) *= k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    boolean isequal= false;
    if(isMatrixSizeEqual(m1, m2)){
        isequal = true;
        int i, j;
        for(i=0; i< ROW_EFF(m1); i++){
            for(j=0; j<COL_EFF(m1); j++){
                if(ELMT(m1, i, j) != ELMT(m2, i, j)){
                    return false;
                }
            }
        }
    }
    return (isequal);
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return(!isMatrixEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return(ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    return(ROW_EFF(m)*COL_EFF(m));
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return(ROW_EFF(m)==COL_EFF(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
    boolean issym = false;
    if(isSquare(m)){
        issym = true;
        int i, j;
        for(i=0; i<ROW_EFF(m); i++){
            for(j=0; j<COL_EFF(m); j++){
                if(ELMT(m, i, j)!=ELMT(m, j, i)){
                    issym = false;
                }
            }
        }
    }
    return issym;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
    boolean isidn = false;
    if(isSquare(m)){
        isidn = true;
        int i, j;
        for(i=0; i<ROW_EFF(m); i++){
            for(j=0; j<COL_EFF(m); j++){
                if(i==j){
                    if(getElmtDiagonal(m, i)!=1){
                        return false;
                    }
                }else{
                    if(ELMT(m, i, j)!=0){
                        return false;
                    }
                }
            }
        }
    }
    return isidn;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
    int i, j, count;
    count =0;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            if(ELMT(m, i, j) != 0){
                count+=1;
            }
        }
    }
    return(((double)count/(double)countElmt(m))*100 <= 5);
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m){
    return(multiplyByConst(m, -1));
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m){
    pMultiplyByConst(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m){
    int i, j, k;
    float matrix_copy[ROW_EFF(m)][COL_EFF(m)];
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            matrix_copy[i][j] = ELMT(m, i, j);
        }
    }
    float factor;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=i+1; j<COL_EFF(m); j++){
            if(matrix_copy[i][i] == 0){
                factor = 1;
            }else{
                factor = matrix_copy[j][i]/matrix_copy[i][i];
            }
            for(k=0; k<COL_EFF(m); k++){
                matrix_copy[j][k] = matrix_copy[j][k] - (matrix_copy[i][k]*factor);
            }
        }
    }
    float result=1;
    for(i=0; i<ROW_EFF(m); i++){
        result *= matrix_copy[i][i];
    }
    if(result ==(-0)){
        result = 0;
    }
    return result;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m){
    Matrix result_m;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result_m);
    int i, j;
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            ELMT(result_m, j, i)= ELMT(m, i, j);
        }
    }
    return result_m;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m){
    *m= transpose(*m);
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

float AvgRow(Matrix M, IdxType i){
    float count, num =0;
    for(int j=0; j<COL_EFF(M); j++){
        count += ELMT(M, i, j);
        // printf("%d\n", ELMT(M, i-1, j));
        // printf("%f\n", count);
        num++;
    }
    float average = count/num;
    // printf("%f\n", average);
    return average;
}

/* Menghasilkan rata-rata dari elemen pada baris ke-i */

/* Prekondisi: i adalah indeks baris efektif dari M */


float AvgCol(Matrix M, IdxType j){
    float count, num =0;
    for(int i=0; i<ROW_EFF(M); i++){
        count += ELMT(M, i, j);
        // printf("%d\n", ELMT(M, i, j-1));
        // printf("%f\n", count);
        num++;
    }
    float average = count/num;
    // printf("%f\n", average);
    return average;
}

/* Menghasilkan rata-rata dari elemen pada kolom ke-j */

/* Prekondisi: j adalah indeks kolom efektif dari M */


void MinMaxRow(Matrix M, IdxType i, ElType * max, ElType * min){
    *max = ELMT(M, i, 0);
    *min = ELMT(M, i, 0);
    for(int j=0; j< COL_EFF(M); j++){
        if(*max < ELMT(M, i, j)){
            *max = ELMT(M, i, j);
        }
        if(*min > ELMT(M, i, j)){
            *min = ELMT(M, i, j);
        }
    }
}

/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada baris i dari M

min berisi elemen minimum pada baris i dari M */


void MinMaxCol(Matrix M, IdxType j, ElType * max, ElType * min){
    *max = ELMT(M, 0, j);
    *min = ELMT(M, 0, j);
    for(int i=0; i< ROW_EFF(M); i++){
        if(*max < ELMT(M, i, j)){
            *max = ELMT(M, i, j);
        }
        if(*min > ELMT(M, i, j)){
            *min = ELMT(M, i, j);
        }
    }
}

/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada kolom j dari M

min berisi elemen minimum pada kolom j dari M */


int CountNumRow(Matrix M, IdxType i, ElType X){
    int count=0;
    for(int j=0; j<COL_EFF(M); j++){
        if(ELMT(M, i, j) == X){
            count +=1;
        }
    }
    return count;
}

/* Menghasilkan banyaknya kemunculan X pada baris i dari M */


int CountNumCol(Matrix M, IdxType j, ElType X){
    int count=0;
    for(int i=0; i<ROW_EFF(M); i++){
        if(ELMT(M, i, j) == X){
            count +=1;
        }
    }
    return count;
}

/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */


void RotateMat(Matrix *m){
    boolean allrotate = false;
    Matrix matrix;
    createMatrix(ROW_EFF(*m), COL_EFF(*m), &matrix);
    // int i=0, j=0;
    int layer= 0;
    while(!allrotate){
        if(ROW_EFF(*m) % 2 == 0){
            if(layer >= (ROW_EFF(*m)/2)-1){
                allrotate = true;
            }
        }else{
            if(layer >= (int)(ROW_EFF(*m)/2)){
                allrotate = true;
            }
        }
        for(int i= layer; i< ROW_EFF(*m)-layer; i++){
            for(int j= layer; j< COL_EFF(*m)-layer; j++){
                if(j==layer && i>layer){
                    ELMT(matrix, i-1, j) = ELMT(*m, i, j);
                    // displayMatrix(matrix);
                }else if(i == ROW_EFF(*m)-layer-1 && j>layer){
                    ELMT(matrix, i, j-1) = ELMT(*m, i, j);
                    // displayMatrix(matrix);
                }else if(i==layer && j < COL_EFF(*m)-layer-1){
                    ELMT(matrix, i, j+1) = ELMT(*m, i, j);
                    // displayMatrix(matrix);
                }else if(j == COL_EFF(*m)-layer-1 && i < ROW_EFF(*m)-layer-1){
                    ELMT(matrix, i+1, j) = ELMT(*m, i, j);
                    // displayMatrix(matrix);
                }else if (ROW_EFF(*m) % 2 != 0 && layer == (int)(ROW_EFF(*m)/2)-1){
                    ELMT(matrix, i, j) = ELMT(*m, i, j);
                    // displayMatrix(matrix);
                }
                // else{
                //     ELMT(matrix, i, j) = ELMT(*m, i, j);
                //     displayMatrix(matrix);
                // }
                // printf("%d ", ELMT(matrix, i, j));
            }
            // printf("\n");
            
        }
        layer++;
        // printf("%d\n", layer);
    }
    *m = matrix;
}

/* I.S. m terdefinisi dan IsSquare(m) */

/* F.S. m "di-rotasi" searah jarum jam */