#include <iostream>
#include <stdlib.h>
using namespace std;
int P[100],   M[100], i, n, pmin, prest;
int aux = 1;
void Inicializa(){
    int i, j;
    for(i=1; i<=n; i++) P[i] = 0;
    prest = 0;
    for (i=1; i<=n; i++){
        j = rand()%n+1;
        if (j <3*n/4){
            P[i]=1;  prest++;
        }
    }
    cout << "Configuracao inicial:     "; for(i=1; i<=n; i++) cout <<P[i]; cout << endl;
}
void RestaUm(){
    int i, j;
    for (i=1; i<=n-2; i++){
    	if ((P[i]==1)&&(P[i+1]==1)&&(P[i+2]==0)){
    		P[i] = 0;  P[i+1] = 0;  P[i+2] = 1;  prest--;
    		if (prest < pmin){
    			pmin = prest;
    			for(j=1; j<=n; j++) M[j]=P[j];
    			aux=0;
			}
			RestaUm();
			P[i] = 1;  P[i+1] = 1;  P[i+2] = 0;  prest++;
		}
	}
	for (i = 1; i<=n-2; i++){
		if ((P[i]==0)&&(P[i+1]==1)&&(P[i+2]==1)){
			P[i] = 1;  P[i+1] = 0;  P[i+2] = 0;  prest--;
			if (prest < pmin){
				pmin = prest;
				for(j=1; j<=n; j++) M[j]=P[j];
				aux=0;
			}
			RestaUm();
			P[i] = 0;  P[i+1] = 1;  P[i+2] = 1;  prest++;
		}
	}
	if (aux==1){
		for(j=1; j<=n; j++) M[j]=P[j];
	}
	
/*RestaUm:
    para i <- 1..n-2 incl.:
        se P[i] = 1 e P[i+1] = 1 e P[i+2] = 0:
            P[i] <- 0;  P[i+1] <- 0;  P[i+2] <- 1;  prest--;
            se  prest < pmin:
            	pmin <- prest
            RestaUm()
            P[i] <- 1;  P[i+1] <- 1;  P[i+2] <- 0;  prest++;
    para i <- 1..n-2 incl.:
        se P[i] = 0  e  P[i+1] = 1  e  P[i+2]) = 1:
            P[i] <- 1;  P[i+1] <- 0;  P[i+2] <- 0;  prest--;
            se  prest < pmin:
            	pmin <- prest
            RestaUm()
            P[i] <- 0;  P[i+1] <- 1;  P[i+2] <- 1;  prest++;
*/
}
int main(){
    while (true){
        cout <<"Informe o tamanho do tabuleiro: "; cin >> n;
        if (!n) break;
        Inicializa(); 
        pmin = prest;
		RestaUm();
        cout <<"Pinos restantes: " <<pmin <<endl;
        cout << "Configuraao final minima: ";
        for(i=1; i<=n; i++) cout << M[i]; cout <<endl << endl;
        for(int j=1; j<=n; j++) M[j]=0;
		aux=1;
    }
}
