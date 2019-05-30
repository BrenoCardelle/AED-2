#include <stdio.h>

int np = 0;
int P[4] = {0,0,0,0};
int q,n;
int cont=0;

void Comb(int t){
    int i;
    for(i = t; i<=n; i++){
        np = np + 1;
        P[np] = i;
        if(np == q){
            if(cont <=50){
                cont+=1;
                printf("%d,%d,%d \n", P[1],P[2],P[3]);
            }
        }else{Comb(i+1);}
        np = np - 1;
    }
}

int main(){

scanf("%d %d", &n, &q);

Comb(1);

}
