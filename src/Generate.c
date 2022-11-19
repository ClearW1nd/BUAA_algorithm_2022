#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "global.h"

int main(){
    srand(time(0));
    FILE* output_p = fopen("../bin/origin.txt","w");
    for(int i=0;i<Max_g_size;i++){
        fprintf(output_p,"%d\n",rand());
    }
    fclose(output_p);
    return 0;
}