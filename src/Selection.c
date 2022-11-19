#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(FILE* input,FILE* output){
    int raw_in[Max_g_size];
    for(int i=0;i<Max_g_size;i++){
        fscanf(input,"%d",raw_in+i);
    }

    for(int i=0;i<Max_g_size-1;i++){
        int min = i;
        for(int j=i+1;j<Max_g_size;j++){
            if(raw_in[j]<raw_in[min]){
                min = j;
            }
        }
        swap(&raw_in[i],&raw_in[min]);
    }

    for(int i=0;i<Max_g_size;i++){
        fprintf(output,"%d\n",raw_in[i]);
    }
}

int main(){
    FILE* input = fopen("../bin/origin.txt","r");
    FILE* output = fopen("../bin/Selection.txt","w");
    SelectionSort(input,output);
    fclose(input);
    fclose(output);
    return 0;
}