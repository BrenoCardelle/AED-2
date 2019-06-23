#include <stdio.h>

void Guloso(int* Vet, int n){
    int j, aux, cont;
    aux = Vet[0];
    cont = 0;
    while(1){
        for(j=0; j<4; j++){
            if(Vet[j] < Vet[j+1] && cont+Vet[j+1]<=n){
                aux = Vet[j+1];
            }else if(cont+Vet[j]<=n){aux = Vet[j];}
        }
        cont+=aux;
        printf("[%d] ", aux);
        if(cont == n){
            printf(" = %d", cont);
            break;
        }
    }
}

int main(){

    int V[5];
    int aux, m, i, k, n, a;
    for(i=0; i<5; i++){
        printf("Entre com o elemento do vetor: ");
        scanf("%d", &aux);
        V[i]=aux;
    }
    for(i=0; i<5; i++){
        for(k=i; k<5; k++){
            if(V[i] > V[k]){
                a = V[i];
                V[i] = V[k];
                V[k] = a;
            }
        }
    }
    if((V[4]/V[3])*V[3] == V[4]){
        m = V[4]/V[3];
    }else{m = (V[4]/V[3]) + 1;}
    //printf("m = %d", m);

    n = V[3]*m;

    int valor;
    printf("Entre com o valor: ");
    scanf("%d", &valor);

    Guloso(V, valor);

    return 0;
}
