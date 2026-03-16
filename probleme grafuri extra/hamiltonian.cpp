#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fisier.in");

int n, m, lant[100], k = 1, vizitat[100];
bool matrix[100][100], isHamilton = true;

void citire(void);
void parcurgere(int poz);

int main(){
    int i;
    fin>>n>>m;
    citire();
    parcurgere(1);
    if(k == n + 1){                                 //daca graful e conex
        for(i = 1; i <= n; i++)
            if(vizitat[i] > 2){                     //daca trece prin vreun nod mai mult de o data, nu e Hamiltonian
                isHamilton = false;                 //(e "> 2" acolo pt ca doar ultimul nod va avea vizitat cu valoarea 1, restul vor avea 2)
                break;
                }
        if(isHamilton){
            if(matrix[1][lant[k - 1]])              //daca exista muchie intre ultimul element parcusr si primul(in cazul acesta, 1 e primul)
                cout<<"e Hamiltonian\n";
            else cout<<"nu e Hamiltonian\n";
            }
        else cout<<"nu e Hamiltonian\n";
        }
    }

void citire(void){                                  //citirea elementelor
    int i, j;
    while(m--){
        fin>>i>>j;
        matrix[i][j] = matrix[j][i] = true;
        }
    }

void parcurgere(int poz){                           //parcurgerea matricei de adiacenta
    lant[k++] = poz;                                //tinem minte in ce ordine am parcurs nodurile; lant[k - 1] va fi mereu ultimul element parcurs                  
    vizitat[poz] = 1;                               //tinem minte care noduri au fost parcurse
    for(int i = 1; i <= n; i++)
        if(vizitat[i] == 0 && matrix[i][poz]){      //daca un nod nu a fost parcurs,
            parcurgere(i);                          //il parcurgem
            vizitat[poz]++;                         //apoi, tinem minte de cate ori a trecut prin fiecare nod parcurgerea
            }
    }