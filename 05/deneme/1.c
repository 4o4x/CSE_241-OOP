#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE * fp;

    fp = fopen("merhaba.txt","w");

    int flag = 0
    

    for(int i=0;i<10;i++){

        if(flag == 0){
            fprintf(fp,"deneme");
            flag = 1;
        }

        else fprintf(fp,"\ndeneme");
    }

    

    

    fclose(fp);
}
