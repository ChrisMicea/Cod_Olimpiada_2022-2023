#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ciclu.in");
ofstream fout("ciclu.out");

vector <int> v[100002];
int k[100003];
int n;
bool viz[100003];
bool ok = true;
int lenCiclu;

void read(void);
void dfs(int poz, int prev);

int main(){
    read();
    if(n == 1)
        fout<<"1\n";
    dfs(1, 0);
    fout<<lenCiclu<<"\n";
    fout.close();
    fin.close();
}

void read(void){
    int i, j, a;
    fin>>n;
    for(i = 1; i <= n; i++){
        fin>>j>>a;
        v[j].push_back(a);
        v[a].push_back(j);
        }
    }

void dfs(int poz, int prev){
    cout<<"suntem in nodul "<<poz<<"\n";
    int i, vecin;
    viz[poz] = true;
    k[poz] = k[prev] + 1;
    for(i = 0; i < v[poz].size(); i++){
        if(ok){
            vecin = v[poz][i];
            if(viz[vecin] && vecin != prev){
                lenCiclu =  k[poz] - k[vecin] + 1;
                ok = false;
                }
            else if(!viz[vecin])
                dfs(vecin, poz);
            }
        else break;
        }
    }