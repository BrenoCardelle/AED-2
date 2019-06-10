#include <stdio.h>
#include <math.h>

int V[5] = {0,0,0,0,0};

int quadrado(int n){
    int aux = sqrt(n);
    if(pow(aux,2) == n){
        V[3] = aux;
        aux-=1;
        printf("%d %d %d %d \n", V[1], V[2], V[3], V[4]);
    }
    for(int i=1; i<=4; i++){
        if(V[1] + V[2] + V[3] + V[4] <= n){
                V[5-i]=aux;
            if()
        }else{
            if(pow(aux,2) + pow(aux-i,2) < n){

            }
        }
    }

    return V;
}

void main(){
    int n;
    scanf("%d", &n);
    printf("%d", quadrado(n));

}
