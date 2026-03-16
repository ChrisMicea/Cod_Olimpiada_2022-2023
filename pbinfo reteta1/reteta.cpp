#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("reteta1.in");
ofstream fout("reteta1.out");

void read(void);
void backtrack(int poz, int sum, int nrOfMedicamente);
bool isSol(int nrOfMedicamente, int sum);

const int nmax = 20, mmax = 17;
float n, m, costuri[nmax], solmin = 100000;
vector <int> retete[mmax];
bool useReteta[mmax], useMedicament[nmax];

int main(){
    read();
    cout<<"aici\n";
    backtrack(1, 0, 0);
	cout<<"aici\n";
    fin.close();
    fout.close();
    }

void read(void){
    int i, p, x, val;
    fin>>n>>m;
    for(i = 1; i <= m; i++){
        fin>>p>>x;
        retete[i].push_back(p);
        while(x--){
            fin>>val;
            retete[i].push_back(val);
            }
   	}
    for(i = 1; i <= n; i++)
   	    fin>>costuri[i];
    }

void backtrack(int poz, int sum, int nrOfMedicamente){
    int i, j, p;
    bool ok;
    vector <int> recentlyUsed;
    for(i = poz; i <= m; i++){
        ok = true;
        fout<<"poz = "<<poz<<", i = "<<i<<", sum = "<<sum<<"\n";
        useReteta[i] = true;
        p = retete[i][0];
        for(j = 1; j < retete[i].size(); j++){
            if(!useMedicament[retete[i][j]]){
                sum += costuri[retete[i][j]] / p;
                useMedicament[retete[i][j]] = true;
                recentlyUsed.push_back(j);
                nrOfMedicamente++;
                }
            else{
                if(poz == 2){
                    fout<<"retete[i][j] = "<<retete[i][j]<<"\n";
                    fout<<"not ok, "<<"i = "<<i<<"\n";
                    for(int y = 1; y <= n; y++)
                        fout<<useMedicament[y]<<" ";
                    fout<<"\n";                    
                    }
                ok = false;
                break;
                }
            }
        if(ok && !isSol(nrOfMedicamente, sum)){
            for(int y = 1; y <= n; y++)
                fout<<useMedicament[y]<<" ";
            fout<<"\n"; 
            backtrack(poz + 1, sum, nrOfMedicamente);
            }
        for(j = 0; j < recentlyUsed.size(); j++){
            useMedicament[recentlyUsed[j]] = false;
            sum -= costuri[retete[i][j]] / retete[i][0];
            nrOfMedicamente--;
            }
        recentlyUsed.clear();
        for(int y = 1; y <= n; y++)
                fout<<useMedicament[y]<<" ";
            fout<<"\n"; 
        }
    }

bool isSol(int nrOfMedicamente, int sum){
    fout<<"sol, cu sum = "<<sum<<"\n";
    if(nrOfMedicamente == n){
   	    if(solmin > sum)
   		    solmin = sum;
   	    return true;
   	    }
    fout<<"false returnat\n";
    return false;
    }
