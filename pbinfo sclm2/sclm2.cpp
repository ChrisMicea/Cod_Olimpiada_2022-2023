#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sclm2.in");
ofstream fout("sclm2.out");

int main(){
    unsigned int n, lmax = 0;
    int i, j;
    unsigned int sir[100002], DP[100002];
    fin>>n;
    for(i = 0; i < n; i++)
        fin>>sir[i];
    DP[n - 1] = 1;
    for(i = n - 1; i >= 0; i--)
        for(j = i + 1; j < n; j++)
            if(sir[i] <= sir[j] && DP[j] + 1 > DP[i]){
                DP[i] = DP[j] + 1;
                if(DP[i] > lmax)
                    lmax = DP[i];
                }
    fout<<lmax<<"\n";
    }