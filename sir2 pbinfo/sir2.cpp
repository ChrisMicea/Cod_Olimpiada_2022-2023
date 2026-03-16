#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sir2.in");
ofstream fout("sir2.out");

int main(){
    int n, m, matrix[303][303], i, j, k, nmax;
    fin>>n>>m;
    fout<<n - (m - 1)<<"\n";
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            if(j == 1 || j == i)
                matrix[i][j] = 1;
            else{
                nmax = i - (j - 1);
                for(k = 1; k <= nmax; k++)
                    matrix[i][j] = (matrix[i][j] + matrix[i - k][j - 1]) % 104729;
                }
            if(i == n && j == m){
                fout<<matrix[i][j];
                return 0;
                }
            }
        }
    }