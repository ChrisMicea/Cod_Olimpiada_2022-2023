#include <iostream>

using namespace std;

void citire(int n);

int matrice[100][100], k, maxi, maxj, lista_linii_grad[100], nrMuchii, gradMax, gradMin = 10000;

int main()
{
    //ex.3
    /*int n, i, j;
    cin>>n;
    citire(n);
    (maxi > maxj) ? maxj = maxi : maxi = maxj;
    for(j = 1; j <= maxj; j++){
        for(i = 1; i <= maxi; i++){
            if(matrice[i][j]){
                if((i % 2) == (j % 2)){
                    matrice[i][j] = 0;
                    matrice[j][i] = 0;
                    //nrMuchii--;
                    }
                else nrMuchii++;
                }
            }
        }
    for(i = 1; i <= maxi; i++){
        for(j = 1; j <= maxj; j++)
            cout<<matrice[i][j]<<" ";
        cout<<endl;
        }
    cout<<nrMuchii / 2<<"\n";*/

    //ex.4
    /*int n, i, j;
    cin>>n>>k;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(i % k == j % k)
                cout<<"0 ";
            else cout<<"1 ";
            }
        cout<<"\n";
        }*/
    
    //ex.5
    /*int n, i, j;
    cin>>n;
    citire(n);
    for(i = 1; i <= n; i++)
        if(lista_linii_grad[i] < gradMin)
            gradMin = lista_linii_grad[i];
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(matrice[i][j] && (lista_linii_grad[i] == gradMax && lista_linii_grad[j] == gradMin) || (lista_linii_grad[i] == gradMin && lista_linii_grad[j] == gradMax)){
                matrice[i][j] = matrice[j][i] = 0;
                k++;
                }
            }
        }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            cout<<matrice[i][j]<<" ";
        cout<<endl;
        }
    if(k != 1)
        cout<<k<<" muchii au fost eliminate\n";
    else cout<<"o muchie a fost eliminata\n";*/

    //ex.6
    int n, m, i, j, val;
    bool ok;
    cin>>n;
    while(n--){
        ok = true;
        cin>>m;
        for(i = 1; i <= m; i++){
            for(j = 1; j <= m; j++){
                cin>>val;
                if(!val)
                    ok = false;
                }
            }
        if(ok)
            cout<<"graful e complet\n";
        else cout<<"graful nu e complet\n";
        }
}

//pt ex.3
/*void citire(int n){
    int i, j;
    while(n--){
        cin>>i>>j;
        //nrMuchii++;
        if(i > maxi)
            maxi = i;
        if(j > maxj)
            maxj = j;
        matrice[i][j] = matrice[j][i] = 1;
        //lista_linii_grad[i]++;
        //lista_linii_grad[j]++;
        }
    }*/

//pt ex.5
/*void citire(int n){
    int i, j;
    while(n--){
        cin>>i>>j;
        matrice[i][j] = matrice[j][i] = 1;
        lista_linii_grad[i]++;
        lista_linii_grad[j]++;
        if(lista_linii_grad[i] > gradMax)
            gradMax = lista_linii_grad[i];
        if(lista_linii_grad[j] > gradMax)
            gradMax = lista_linii_grad[j];
        }
    }*/