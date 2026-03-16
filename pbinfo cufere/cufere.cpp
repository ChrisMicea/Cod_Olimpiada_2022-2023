#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cufere.in");
ofstream fout("cufere.out");

const int nmax = 27 * 10001 + 10;
short int n;
int ciur[103];
int frecv[103];

void readAndSolve1(void);
void read2(void);
void eratostene(void);

int main(){
    int p;
    fin>>p;
    if(p == 1){
        readAndSolve1();
        }
    else if(p == 2){
        eratostene();
        read2();
        }
    fin.close();
    fout.close();
    }

void readAndSolve1(void){
    short int i, x, temp, maxim = -1;
    fin>>n;
    for(i = 1; i <= 27 * n; i++){
        fin>>x;
        temp = ((x / 10) % 10) * 10 + (x % 10);
        if(temp > maxim)
            maxim = temp;
        x /= 100;
        frecv[temp] += ((x / 10) % 10) * 10 + (x % 10);
        }
    for(i = 10; i <= maxim; i++)
        if(frecv[i])
            fout<<i<<" "<<frecv[i]<<"\n";
    }

void read2(void){
    short int i, j, k, l, x, temp, maxim = -1;
    fin>>n;
    for(i = 1; i <= 27 * n; i++){
        fin>>x;
        temp = ((x / 10) % 10) * 10 + (x % 10);
        if(temp > maxim)
            maxim = temp;
        x /= 100;
        frecv[temp] += ((x / 10) % 10) * 10 + (x % 10);
        }
    l = 10;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= 3; j++){
            for(k = 1; k <= 9; k++){
                while(frecv[l] == 0 && l <= 100)
                    l++;
                if(l >= 100){
                    fout<<0<<" ";
                    continue;
                    }
                if(ciur[l] == 1){
                    if(frecv[l] - 16 >= 0){
                        fout<<16 * 100 + l<<" ";
                        frecv[l] -= 16;
                        }
                    else if(frecv[l] < 16){
                        fout<<frecv[l] * 100 + l<<" ";
                        frecv[l] = 0;
                        }
                    }
                else{
                    if(l == 105)
                        cout<<"?\n";
                    if(frecv[l] - 64 >= 0){
                        fout<<64 * 100 + l<<" ";
                        frecv[l] -= 64;
                        }
                    else if(frecv[l] < 64){
                        fout<<frecv[l] * 100 + l<<" ";
                        frecv[l] = 0;
                        }
                    }
                }
            fout<<"\n";
            }
        }
    }

void eratostene(void){
    int i, j;
    ciur[1] = -1;
    for(i = 2; i <= 97; i++)
        if(!ciur[i]){
            for(j = 2 * i; j <= 101; j += i)
                ciur[j] = -1;
            ciur[i] = 1;
            }
    }