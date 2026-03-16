#include <iostream>

using namespace std;

short int k;
unsigned long long int n, numar, nmax; 
bool reprezentare[10000002];

void ciurEratostene(int val);

int main(){
    cin>>n>>k;
    numar = n * n;
    ciurEratostene(n);
    for(int i = 2; i <= n; i++)
        cout<<reprezentare[i]<<" ";
    }

void ciurEratostene(int val){
    cout<<"val = "<<val<<"\n";
    int i, j;
    for(i = 2; i * i <= val; i++){
        if(reprezentare[i]){
            cout<<"i = "<<i<<"\n";
            for(j = i * 2; j <= val; j += i){
                cout<<"j = "<<j<<"\n";
                reprezentare[j] = true;
                }
            }
        }
    }