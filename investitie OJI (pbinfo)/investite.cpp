#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("investitie.in");
ofstream fout("investitie.out");

int n, m, q, a[100003], nrRepetarePerm, perm[100003];
int matriceVal[5003][5003];

void readPartial(void);
void determinareRepetare(void);
void matrixConstruct(int perm[]);
int cmmdc(int x, int y);
int cmmmc(int x, int y);
void calculSolutie(void);

int main(){
    fin>>n;
    if(n == 1){
        int zi, zf, cl, cr;
        fin>>m>>n>>q;
        while(q--){
            fin>>zi>>zf>>cl>>cr;
            fout<<zf - zi + 1<<"\n";
            }
        }
    else{
        readPartial();
        determinareRepetare();
        calculSolutie();
        }
}

void readPartial(void){
    int i;
    fin>>m;
    for(i = 1; i <= n; i++)
        fin>>a[i];
    fin>>q;
    }

void determinareRepetare(void){
    int k, i, j;
    for(i = j = 1; i <= n; i++){
        k = 0;
        j = 1;
        perm[i] = a[i];
        do{
            matriceVal[j++][i] = perm[i];
            //cout<<"val = "<<matriceVal[j - 1][i]<<" ";
            perm[i] = a[perm[i]];
            k++;
            }while(perm[i] != a[i]);
        perm[i] = k;
        }
    k = cmmmc(perm[1], perm[2]);
    for(i = 3; i <= n; i++)
        k = cmmmc(k, perm[i]);
    nrRepetarePerm = k;
    matrixConstruct(perm);
    }

void matrixConstruct(int perm[]){
    int i, j;
    //cout<<"perm[8] = "<<perm[8]<<"\n";
    //cout<<matriceVal[1][8]<<"\n";
    //cout<<"n = "<<n<<", nrrepetareperm = "<<nrRepetarePerm<<", a[8] = "<<a[8]<<"\n";
    for(i = 1; i <= nrRepetarePerm; i++){
        for(j = 1; j <= n; j++){
            if(i % perm[j] != 0)
                matriceVal[i][j] = matriceVal[i % perm[j]][j] + matriceVal[i][j - 1];
            else if(perm[j] == 1){
                matriceVal[i][j] = a[j] +  + matriceVal[i][j - 1];
                }
            else{ 
                matriceVal[i][j] = matriceVal[perm[j]][j] + matriceVal[i][j - 1];
                //cout<<"i = "<<i<<", j = "<<j<<", matriceval curr = "<<matriceVal[perm[j]][j]<<", matrice prev = "<<matriceVal[i][j - 1]<<", perm[j] = "<<perm[j]<<"\n";
                }
            }
        }
    for(i = 1; i <= nrRepetarePerm; i++){
        for(j = 1; j <= n; j++)
            cout<<matriceVal[i][j]<<" ";
        cout<<"\n";
        }
    }

int cmmdc(int x, int y){
    int r;
    while(y != 0){
        r = x % y;
        x = y;
        y = r;
        }
    return x;
    }

int cmmmc(int x, int y){
    return x * y / cmmdc(x, y);
    }

void calculSolutie(void){
    int zi, zf, cl, cr, i;
    unsigned long long int sum;
    while(q--){
        sum = 0;
        fin>>zi>>zf>>cl>>cr;
            for(i = zi; i <= zf; i++){
                if(i % nrRepetarePerm)
                    sum += matriceVal[i % nrRepetarePerm][cr] - matriceVal[i % nrRepetarePerm][cl - 1];
                else sum += matriceVal[i][cr] - matriceVal[i][cl - 1];
                }
            fout<<sum<<"\n";
        }
    }