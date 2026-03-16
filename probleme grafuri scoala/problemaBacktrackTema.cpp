#include <iostream>
using namespace std;

int x[50], n, contorLastThree, lastSol1[50], lastSol2[50], lastSol3[50], cazFinal;

void afis(){
    int j;
    for(j = 1; j <= n; j++)
        cout<<lastSol1[j]<<" ";
    cout<<endl;
    for(j = 1; j <= n; j++)
        cout<<lastSol2[j]<<" ";
    cout<<endl;
    for(j = 1; j <= n; j++)
        cout<<lastSol3[j]<<" ";
    cout<<endl;
    }

bool solutie(int k){
    return k == n;
    }

void back(int k){
    for(int i = 3; i <= 7; i += 2){
        x[k] = i;
        if(solutie(k)){
            if(!contorLastThree){
                contorLastThree++;
                for(int j = 1; j <= n; j++)
                    lastSol1[j] = x[j];
                }
            else if(contorLastThree == 1){
                contorLastThree++;
                for(int j = 1; j <= n; j++)
                    lastSol2[j] = x[j];
                }
            else if(contorLastThree == 2){
                contorLastThree++;
                for(int j = 1; j <= n; j++)
                    lastSol3[j] = x[j];
                }
            else{
                for(int j = 1; j <= n; j++)
                    lastSol1[j] = lastSol2[j];
                for(int j = 1; j <= n; j++)
                    lastSol2[j] = lastSol3[j];
                for(int j = 1; j <= n; j++)
                    lastSol3[j] = x[j];
                }
            }    
        else
            back(k + 1);
    }
    }

int main(){
    cin>>n;
    back(1);
    afis();
    return 0;
}