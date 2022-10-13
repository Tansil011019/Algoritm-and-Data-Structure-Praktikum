#include <stdio.h>
#include "wordmachine.h"
// #include "wordmachine.c"
// #include "charmachine.h"
// #include "charmachine.c"

boolean checkword(Word check_value, char *dummy);

int main(){
    char nol[] = "nol";
    char satu[] = "satu";
    char dua[] = "dua";
    char tiga[] = "tiga";
    char empat[]= "empat";
    char lima[]= "lima";
    char enam[]= "enam";
    char tujuh[]= "tujuh";
    char delapan[]= "delapan";
    char sembilan[] = "sembilan";
    char sepuluh[]= "sepuluh";
    char sebelas[]= "sebelas";
    char seratus[]= "seratus";
    char belas[]= "belas";
    char puluh[]= "puluh";
    char ratus[]= "ratus";

    STARTWORD();
    int temp_value= 0;
    boolean check= false;
    while(!endWord){
        IgnoreBlanks();
        if(checkword(currentWord,sepuluh)){
            temp_value+=10;
            check= true;
        }else if(checkword(currentWord,sebelas)){
            temp_value+=11;
            check= true;
        }else if(checkword(currentWord,belas)){
            temp_value+=10;
            check= true;
        }else if(checkword(currentWord,puluh)){
            temp_value = temp_value - (temp_value % 100) + (temp_value % 100) * 10;
            check= true;
        }else if(checkword(currentWord,ratus)){
            temp_value*=100;
            check= true;
        }else if(checkword(currentWord,seratus)){
            temp_value+=100;
            check= true;
        }else if(checkword(currentWord, nol)){
            check= true;
        }else if(checkword(currentWord, satu)){
            temp_value++;
            check= true;
        }else if(checkword(currentWord, dua)){
            temp_value+=2;
            check= true;
        }else if(checkword(currentWord, tiga)){
            temp_value+=3;
            check= true;
        }else if(checkword(currentWord, empat)){
            temp_value+=4;;
            check= true;
        }else if(checkword(currentWord, lima)){
            temp_value+=5;
            check= true;
        }else if(checkword(currentWord,enam)){
            temp_value+=6;
            check= true;
        }else if(checkword(currentWord,tujuh)){
            temp_value+=7;
            check= true;
        }else if(checkword(currentWord,delapan)){
            temp_value+=8;
            check= true;
        }else if(checkword(currentWord,sembilan)){
            temp_value+=9;
            check= true;
        }else{
            if(check){
                printf("%d ", temp_value);
                temp_value= 0;
                check= false;
            }
            for(int i= 0; i<currentWord.Length; i++){
                printf("%c", currentWord.TabWord[i]);
            }
        }
        // printf("%d ", temp_value);
        ADVWORD();
        if(!check && !endWord){
            printf(" ");
        }
    }
    if (check){
        printf("%d", temp_value);
    }
    printf("\n");
    return 0;
}

boolean checkword(Word check_value, char *dummy){
    int dummy_len= 0;
    while(dummy[dummy_len]!='\0'){
        dummy_len++;
    }
    if(dummy_len != check_value.Length){
        return false;
    }else{
        for(int i=0; i<dummy_len; i++){
            if(dummy[i]!=check_value.TabWord[i]){
                return false;
            }
        }
    }
    return true;
}