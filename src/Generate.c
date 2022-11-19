#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    srand(time(0));
    FILE* output_p = fopen("../bin/origin.txt","w");
    for(int i=0;i<10000;i++){
        fprintf(output_p,"%d\n",rand());
    }
    fclose(output_p);
    return 0;
}