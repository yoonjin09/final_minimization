#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define MAX_COUNT 40
//#define MAX_LENGTH 128

typedef struct{
  int num;
  int binary[10];
  int epi;
  char numeric[16];
  int numericcount; // 0020 이면 0과 2로 numericcount 2
  int isdontcare; //1이면 minterm, 0이면 dontcare
} Variable;

void converttotwo(int varcount, int epicount, Variable* Epilist, Variable* list, int a , int A){
    for(int b=0; b<varcount; b++){
        if(list[a].binary[b] == list[A].binary[b]){
            Epilist[epicount].binary[b] = list[a].binary[b]; //원래는 '-'를 넣어서 표현했지만 0,1 이 아닌 수 를 집어 넣어준 것
        }
        else Epilist[epicount].binary[b]= 2;     
    }
}

int countsame(int varcount, Variable list, Variable s){ //samecount 개수 확인하는 함수
    int samecount=0;
    int b=0;
    while(b<varcount){
        if(list.binary[b] == s.binary[b]) samecount++;
        //printf("same: %d\n",samecount);
        b++;
    }
    return samecount;
}


void printBinary(int epicount, int varcount, Variable* s){
    for(int a=0; a<epicount; a++){
        int count=0;
        for(int j=0; j< varcount; j++){
        count++;
        printf("%d ",s[a].binary[j]);
        if(count%varcount==0)printf("  %d\n",s[a].epi);
        }
    }
}

void printNumeric(int epicount, int varcount, Variable* s){
    for(int a=0; a<epicount; a++){
        int count=0;
        printf("numericcount :%d",s[a].numericcount);
        for(int j=0; j< s[a].numericcount; j++){
            printf(" %d",s[a].numeric[j]);
        }
        printf("\n");
    }
}


void print2darray(int tokencount, int mintermcount, int **twod_array){
    for(int z=0; z<tokencount; z++){
        for(int y=0; y<mintermcount; y++){
        printf("%d",twod_array[z][y]);
        }
        printf("\n");
    }
}
