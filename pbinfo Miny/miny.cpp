#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("miny.in");
ofstream fout("miny.out");

int nrCiur[22363], nrPrime[3003][2], k;

int cmmdc(int n, int m);
void ciur(void);

int main()
{
    int n, i, nrCur, produs = 1, j, nrPutMin = 100000, cmmdcCurent = -1;
    fin>>n;
    ciur();
    for(i = 0; i < n; i++){
        fin>>nrCur;
        produs *= nrCur;                //pt conditia
        produs %= 100;                  //      a

        for(j = 0; nrCur > 1 && j < k; j++)
            while(nrCur % nrPrime[j][0] == 0){
                nrPrime[j][1]++;
                nrCur /= nrPrime[j][0];
                }
        }

    fout<<produs / 10<<"\n";

    produs = 0;                                               //reutilizez variabila
    for(i = 0; i < k; i++){
        if(nrPrime[i][1]){
            produs++;
            if(cmmdcCurent == -1)
                cmmdcCurent = nrPrime[i][1];
            else cmmdcCurent = cmmdc(cmmdcCurent, nrPrime[i][1]);
            }
        }
    fout<<produs<<"\n";
    for(i = 0; i < k; i++){
        if(nrPrime[i][1]){
            fout<<nrPrime[i][0]<<" "<<nrPrime[i][1] / cmmdcCurent<<"\n";
            }
        }
}

void ciur(void){
    int i, j;
    nrCiur[1] = -1;
    for(i = 2; i <= 22363; i++) {
        if(!nrCiur[i]){
            nrPrime[k][0] = i;
            k++;
            for(int j = 2 * i; j <= 22363; j += i)
                nrCiur[j] = -1;
            }
        }
    }

int cmmdc(int n, int m){
    while(n != m)
        if(n > m)
            n -= m;
        else
            m -= n;
    return m;
    }