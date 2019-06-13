#include <iostream>
#include <string.h>
using namespace std;
struct retorno{int valor; int l; int c;};
char resp, Tb[4][4]; bool fim;  int v, x, y; retorno r;

void ImprimeTb(){
    int i,j;
    for (i=1; i<=3; i++){ for (j=1; j<=3; j++) cout<<Tb[i][j]; cout<<endl;}
}
int AnalisaTb(){
    int i, j, k, c1; char s1[4], s2[4],s3[4],s4[4],s5[4],s6[4],s7[4],s8[4]; 
    s1[0]=Tb[1][1]; s1[1]=Tb[1][2]; s1[2]=Tb[1][3]; s1[3]=0;
    s2[0]=Tb[2][1]; s2[1]=Tb[2][2]; s2[2]=Tb[2][3]; s2[3]=0;
    s3[0]=Tb[3][1]; s3[1]=Tb[3][2]; s3[2]=Tb[3][3]; s3[3]=0;
    s4[0]=Tb[1][1]; s4[1]=Tb[2][1]; s4[2]=Tb[3][1]; s4[3]=0;
    s5[0]=Tb[1][2]; s5[1]=Tb[2][2]; s5[2]=Tb[3][2]; s5[3]=0;
    s6[0]=Tb[1][3]; s6[1]=Tb[2][3]; s6[2]=Tb[3][3]; s6[3]=0;
    s7[0]=Tb[1][1]; s7[1]=Tb[2][2]; s7[2]=Tb[3][3]; s7[3]=0;
    s8[0]=Tb[1][3]; s8[1]=Tb[2][2]; s8[2]=Tb[3][1]; s8[3]=0;
    if (strcmp(s1,"ooo")==0 || strcmp(s2,"ooo")==0 || strcmp(s3,"ooo")==0 || strcmp(s4,"ooo")==0 ||
        strcmp(s5,"ooo")==0 || strcmp(s6,"ooo")==0 || strcmp(s7,"ooo")==0 || strcmp(s8,"ooo")==0) k=-1;
    else if (strcmp(s1,"xxx")==0 || strcmp(s2,"xxx")==0 || strcmp(s3,"xxx")==0 || strcmp(s4,"xxx")==0 ||
        strcmp(s5,"xxx")==0 || strcmp(s6,"xxx")==0 || strcmp(s7,"xxx")==0 || strcmp(s8,"xxx")==0) k = 1;                    
    else{
        c1 = 0;  for (i=1; i<=3; i++) for (j=1; j<=3; j++) if (Tb[i][j]== '.') c1 = 1;
        if (c1 == 1) k = -2;
        else k = 0;
    }
    return k;
}
retorno Joga(char *modo){
    int i, l, c, vm, cm, lm; retorno ret;
    vm = AnalisaTb();
    if (vm > -2){ ret.valor = vm; return ret;}
    else{
        if (modo == "MIN") vm = 10; else vm = -10;
        i = 1;
        while (i <= 9){
            l = (i+2)/3; c = (i-1)%3 + 1;
            if (Tb[l][c] == '.'){
                if (modo == "MIN"){
                    Tb[l][c] = 'o';  ret = Joga("MAX");
                    if (vm > ret.valor) vm = ret.valor;
                }
                else{
                    Tb[l][c] = 'x';  ret = Joga("MIN");
                    if (vm < ret.valor){
                        vm = ret.valor;  cm = c; lm = l;
                    }    
                }
                Tb[l][c] = '.';
            }
            i++;
        }
        ret.c = cm;  ret.l = lm;  ret.valor = vm;
        return ret;
    }
}
int main(){
    while(true){
        cout<<"Novo jogo. Quer comecar? ";  cin >>resp;
        memset(Tb,'.',sizeof (Tb)); fim=0;  
        while (!fim){
			ImprimeTb();
			cout << endl;
			// Jogada do adversário
	        if((resp == 's') || (resp == 'sim') || (resp == 'SIM') || (resp == 'S')){
				while (true){
	                cout<<"Sua jogada: "; cin >>x >> y;
	                if (Tb[x][y] == '.') break;
	            }
            }
            resp = 's';
            Tb[x][y]='o';
            //
            //Jogada do computador
            v = AnalisaTb(); 
            if (v == -2){
                r = Joga("MAX");  Tb[r.l][r.c]= 'x'; v = AnalisaTb();
            }
            //FIM DE JOGO
            if (v > -2){
                fim = 1; ImprimeTb();
                if (v == -1) cout<<"Voce venceu."<<endl;
                else if (v == 0) cout<<"Empate."<<endl;
                else cout<<"Venci."<<endl;
            }
        }
    }
    return 0;
}
