#include <iostream>
using namespace std;
struct retorno {int valor; int np;}; 
int npt, npret;  retorno r, T[100001];

retorno Avalia(int n, string modo){
    int i, npm, valorm;  retorno ret;
    if (n == 0){
        if (modo == "MAX") ret.valor = -1;
        else ret.valor= 1;
        ret.np = 0;
        return ret;
    }
    // PODA DE MEMORIZAÇÂO
    else if (T[n].np != 0){
        ret = T[n];
        if (modo == "MIN") ret.valor = -ret.valor;
        return ret;
	}
	
    else{ 
        if (modo == "MAX"){
            valorm = -2;  
            for (i=1; i<= min(3,n); i++){
                ret = Avalia(n-i,"MIN");
                if (ret.valor > valorm){
                    valorm = ret.valor;
                    npm = i;  ret.np=npm;
                    //PODA DE VALOR LIMITE
					if (valorm==1) return ret;
					
                }
            }
        }
        else{
            valorm = 2;  
            for (i=1; i<= min(3,n); i++){
                ret = Avalia(n-i,"MAX");
                if (ret.valor < valorm){
                    valorm = ret.valor;
                    npm = i;  ret.np=npm;
                    //PODA DE VALOR LIMITE                    
                    if (valorm==-1) return ret;   
										                 
                }                
            }
        }
        ret.valor=valorm; ret.np=npm;  
		T[n]=ret;  if (modo == "MIN") T[n].valor = -T[n].valor;
        return ret;
    }
}
void Comeca(){
     cout<<endl<<"Num. de palitos: "; cin >> npt; cout<<endl;
}
void ImprPal(int n){
    cout<<"Palitos restantes ("<< n <<"): ";
    for (int i=1; i<=min(n,100); i++) cout <<'|'; cout<<endl;
}
int main(){
    for (int i=0; i<=100000; i++) T[i].np=0;
	Comeca();
    while (true){
        ImprPal(npt);
        r=Avalia(npt,"MAX");   npt = npt-r.np;
        cout <<endl<<"Retiro " << r.np << " palito(s). ";  ImprPal(npt);
        if (npt == 0) cout <<"Fim de jogo. Ganhei."<<endl;
        else{
            cout<<endl<<"Retira quantos palitos? "; cin >>npret;
            while((npret<1) || (npret>3)){
            	cout<<endl<<"Voce pode apenas retirar de 1 a 3 palitos. Retira quantos palitos? "; cin >>npret;
			}
			npt=npt-npret;
            if (npt == 0) cout <<"Fim de jogo. Voce ganhou."<<endl;                 
        }
        if (npt == 0) Comeca();
    }
}
