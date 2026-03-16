#include <iostream>

using namespace std;

void citire(int m);
void parcurgere(int nodCurent);

int matrice[1000][1000], vizitat[1000], valParcurgere, n;

int main()
{
    int i, j, m, k;
    cin>>n>>m;
    citire(m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            if(matrice[i][j])
                matrice[i][j] = matrice[j][i] = 2;
        /*for(k = 1; k <= n; k++){
            for(j = 1; j <= n; j++)
                cout<<matrice[k][j]<<" ";
            cout<<"\n";
            }*/
        valParcurgere = 0;
        if(i > 1)
            parcurgere(1);
        else parcurgere(2);
        //cout<<"valparcurgere = "<<valParcurgere<<"\n";
        if(valParcurgere < n - 1)
            cout<<"1 ";
        else cout<<"0 ";
        for(j = 1; j <= n; j++)
            vizitat[j] = 0;
        for(j = 1; j <= n; j++)
            if(matrice[i][j] == 2)
                matrice[i][j] = matrice[j][i] = 1;
        }
}

void parcurgere(int nodCurent){
    vizitat[nodCurent] = 1;
    valParcurgere++;
    //cout<<"parcurs nodul "<<nodCurent<<"\n";
    for(int i = 1; i <= n; i++)
        if(matrice[nodCurent][i] == 1 && !vizitat[i])
            parcurgere(i);
    }

void citire(int m){
    int i, j;
    while(m--){
        cin>>i>>j;
        matrice[i][j] = matrice[j][i] = 1;
        }
    }
