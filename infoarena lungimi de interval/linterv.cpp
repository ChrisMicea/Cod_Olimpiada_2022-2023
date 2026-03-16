#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("linterv.in");
ofstream fout("linterv.out");

void quickSort(int left, int right);

int t, n, valori[5003][2], i, mijloc, j, d;
long long int valInterv;

int main(){
    fin>>t;
    while(t--){
        valInterv = 0;
        fin>>n;
        for(i = 0; i < n; i++)
            fin>>valori[i][0]>>valori[i][1];
        quickSort(0, n - 1);
        j = valori[0][0];
        d = valori[0][1];
        valInterv += (d - j);
        for(i = 1; i < n; i++){
            //cout<<"pt i = "<<i<<", valinterv = "<<valInterv<<"\n";
            if(d >= valori[i][1])
                continue;
            else if(d < valori[i][0]){
                j = valori[i][0];
                d = valori[i][1];
                valInterv += (d - j);
                }
            else{
                valInterv += (valori[i][1] - d);
                d = valori[i][1];
                }
            }
        fout<<valInterv<<"\n";
        }
    }

void quickSort(int left, int right){
    if(left < right){
        int mijloc = (left + right) / 2;
        swap(valori[mijloc][0], valori[left][0]);
        swap(valori[mijloc][1], valori[left][1]);
        i = left;
        j = right;
        d = 0;
        while(i < j){
            if(valori[i][0] > valori[j][0]){
                swap(valori[i][0], valori[j][0]);
                swap(valori[i][1], valori[j][1]);
                d = 1 - d;
                }
            else if((valori[i][0] == valori[j][0]) && (valori[i][1] > valori[j][1])){
                swap(valori[i][0], valori[j][0]);
                swap(valori[i][1], valori[j][1]);
                d = 1 - d;
                }
            i += d;
            j -= 1 - d;
            }
        quickSort(left, i - 1);
        quickSort(i + 1, right);
        }
    }