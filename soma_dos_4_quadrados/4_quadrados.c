#include <stdio.h>
#include <math.h>

int V[5] = {0,0,0,0,0};
int i;
int np=0;
void Quadrado(int n){
    for(i=1; i<=4; i++){
        if(pow(V[1],2) + pow(V[2],2) + pow(V[3],2) + pow(V[4],2) < n){
            np+=1;
            V[np]=i;
            if(pow(V[1],2) + pow(V[2],2) + pow(V[3],2) + pow(V[4],2) == n){
            	printf("%d %d %d %d \n", V[4], V[3], V[2], V[1]);
			}else{
            	Quadrado(n);
            }
            V[np]=0;
            np-=1;
        }
    }
}

void main(){
    int n;
    scanf("%d", &n);
    Quadrado(n);
}
