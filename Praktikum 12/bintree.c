/* File : bintree.h */
/* ADT pohon biner */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#include "boolean.h"
#include <stdio.h>
#include "bintree.h"
#include "stdlib.h"

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree new_tree= (BinTree) malloc (sizeof(TreeNode));
    if(new_tree != NULL){
        ROOT(new_tree)= root;
        LEFT(new_tree)= left_tree;
        RIGHT(new_tree)= right_tree;
    }
    return new_tree;
}
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p= NewTree(root, left_tree, right_tree);
}
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val){
    Address new_node= (Address) malloc (sizeof(TreeNode));
    if(new_node != NULL){
        ROOT(new_node)= val;
    }
    return new_node;
}
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p){
    free(p);
}
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p){
    return (p == NULL);
}
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p){
    return(!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL);
}
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p){
    return(!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL);
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p){
    return(!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL);
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p){
    return(!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL);
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p){
    if(isTreeEmpty(p)){
        printf("()");
    }else{
        printf("(");
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void printInorder(BinTree p){
    if(isTreeEmpty(p)){
        printf("()");
    }else{
        printf("(");
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void printPostorder(BinTree p){
    if(isTreeEmpty(p)){
        printf("()");
    }else{
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
        printf(")");
    }
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void indentation_print_tree(BinTree p, int count, int h){
    if(!isTreeEmpty(p)){
        int indent_count= count * h;
        while(indent_count > 0){
            printf(" ");
            indent_count--;
        }
        printf("%d\n", ROOT(p));
        indentation_print_tree(LEFT(p), count+1, h);
        indentation_print_tree(RIGHT(p), count+1, h);
    }
}

void printTree(BinTree p, int h){
    indentation_print_tree(p, 0, h);
}
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/

int rob1(BinTree root){
    if(isTreeEmpty(root)){
        return 0;
    }else if(isOneElmt(root)){
        return ROOT(root);
    }else{
        int p= rob1(LEFT(root));
        int q= rob1(RIGHT(root));
        if(p > q){
            return p + ROOT(root);
        }else{
            return q + ROOT(root);
        }
    }
}
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.

int rob2(BinTree root){
    if(isTreeEmpty(root)){
        return 0;
    }else if(isOneElmt(root)){
        return ROOT(root);
    }else{
        int temp1 = ROOT(root);
        if(!isTreeEmpty(LEFT(root))){
            temp1 += (rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root))));
        }
        if(!isTreeEmpty(RIGHT(root))){
            temp1 += (rob2(LEFT(RIGHT(root))) + rob2(RIGHT(RIGHT(root))));
        }
        int temp2 = rob2(LEFT(root)) + rob2(RIGHT(root));
        if(temp1 > temp2){
            return temp1;
        }else{
            return temp2;
        }
    }
}
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.
