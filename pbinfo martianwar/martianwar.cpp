/*#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("file.in");
//ofstream fout("pamant.out");

const int nmax = 250000;

int n, m, q, Use[nmax + 3], sol[nmax + 3], nrsons[nmax + 3];
int level[nmax + 3], low[nmax + 3];
vector <int> G[nmax + 3];
int nrMuchii;

void read();
void print();
void dfs(int nod, int tata);
void solve();

int main(){
    read();
    solve();
    print();
    }

void read(){
    fin>>n>>m>>q;
    //m++;
    //q--;
    for(int i = 1; i <= m; i++){
        int x, y;
        fin>>x>>y;
        //cout<<x<<" "<<y<<"\n";
        G[x].push_back(y);
        G[y].push_back(x);
        }
    }

void print(){
    //for(int i = 1; i <= n; i++)
    //    if(sol[i])
    //        fout<<i<<" ";
    }

void dfs(int nod, int tata){
    //cout<<"am mers din "<<tata<<" in "<<nod<<"\n";
    Use[nod] = 1;
    //bool frunza = false;
    level[nod] = level[tata] + 1;
    low[nod] = level[nod];
    for(auto vecin : G[nod]){
        if(vecin == tata)
            continue;
        if(!Use[vecin]){
            nrsons[nod]++;
            dfs(vecin, nod);
            low[nod] = min(low[nod], low[vecin]);               //mai intai se face dfs, se afla low-ul minim de pe toate ramura si apoi acel minim se propaga in sus
            //if(low[vecin] >= level[nod]){                        //e punct de articulatie
            //    sol[nod] = 1;
            //    }
            if(low[vecin] > level[nod])
                nrMuchii++;
            }
        else{
            low[nod] = min(low[nod], level[vecin]);
            }
        }
    if(tata == 0 && nrsons[nod] == 1)
        sol[nod] = 0;
    }

void solve(){
    int i, x, y;
    //dfs(1, 0);
    //cout<<nrMuchii<<"\n";
    while(q--){
        nrMuchii = 0;
        for(i = 1; i <= n; i++)
            Use[i] = 0;
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        dfs(1, 0);
        cout<<nrMuchii<<"\n";
        }
    }*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int nmax = 250000;

int n, m, q, Use[nmax + 3], sol[nmax + 3], nrsons[nmax + 3];
int level[nmax + 3], low[nmax + 3];
vector <int> G[nmax + 3];
int nrMuchii;

void read();
void dfs(int nod, int tata);
void solve();

int main(){
    read();
    solve();
    }

void read(){
    cin>>n>>m>>q;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        }
    }

void dfs(int nod, int tata){
    Use[nod] = 1;
    level[nod] = level[tata] + 1;
    low[nod] = level[nod];
    for(auto vecin : G[nod]){
        if(vecin == tata)
            continue;
        if(!Use[vecin]){
            nrsons[nod]++;
            dfs(vecin, nod);
            low[nod] = min(low[nod], low[vecin]);
            if(low[vecin] > level[nod])
                nrMuchii++;
            }
        else{
            low[nod] = min(low[nod], level[vecin]);
            }
        }
    if(tata == 0 && nrsons[nod] == 1)
        sol[nod] = 0;
    }

void solve(){
    int i, x, y;
    while(q--){
        nrMuchii = 0;
        for(i = 1; i <= n; i++)
            Use[i] = 0;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        for(i = 1; i <= n; i++)
            if(!Use[i])
                dfs(i, 0);
        cout<<nrMuchii<<"\n";
        }
    }