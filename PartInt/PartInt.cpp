#include <iostream>
using namespace std;
int S[100], ns, soma, sol, n;


void Part(int t){
    int i, j;
/*  i <- t
    enquanto i <=n  e  soma + i <=n:
        S[++ns] <- i;  soma <- soma+i;
		se (soma = n):
		    Imprimir e contar
		senão:
			Part(i)
        ns--;  soma <- soma-i;
        i++;
*/
	i=t;
	while((i<=n) && (soma+i <= n)){
		S[++ns] = i;
		soma += i;
		if(soma==n){
			for(int j = 1; j<=n; j++){
				cout << S[j] << " ";
			}
			cout << endl;
			sol+=1;
		}else{
			Part(i);
		}
		S[ns]=0;
		
		ns--;
		soma-=i;
		i++;
	}

}
int main(){
    while (true){
        cout <<"n = "; cin >> n;
        ns = 0;   soma = 0;  Part(1);
        cout <<"Numero de solucoes: " <<sol <<endl;
        cin.get();
    }
}
