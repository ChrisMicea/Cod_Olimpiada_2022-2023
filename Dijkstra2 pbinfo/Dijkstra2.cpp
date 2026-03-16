#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("dijkstra2.in");
ofstream fout("dijkstra2.out");

void read(void);
void Dijkstra(int poz);

int n, m, start;
int D[100003];
bool S[100003];
vector <pair<int, int>> v[100003];

int main(){
    read();
    for(int i = 1; i <= n; i++){
        cout<<i<<":";
        for(int j = 0; j < v[i].size(); j++)
            cout<<"("<<v[i][j].first<<","<<v[i][j].second<<") ";
        cout<<"\n";
        }
    Dijkstra(start);
    for(int i = 1; i <= n; i++)
        fout<<D[i]<<" ";
    fin.close();
    fout.close();
    }

void read(void){
    int i, j, val;
    fin>>n>>m>>start;
    while(m--){
        fin>>i>>j>>val;
        v[i].push_back(make_pair(j, val));
        v[j].push_back(make_pair(i, val));
        }
    }

void Dijkstra(int poz){
    int vecin, cost;
    for(int i = 1; i <= n; i++){
        D[i] = 1000000;
        S[i] = false;
        }
    D[poz] = 0;
    for(int i = 1; i <= n; i++){
        int minim = 1000000, nod;
        for(int j = 1; j <= n; j++)
            if(D[j] < minim && S[j] == false){
                minim = D[j];
                nod = j;
                }
        S[nod] = 1;
        for(int k = 0; k < v[nod].size(); k++){
            vecin = v[nod][k].first;
            cost = v[nod][k].second;
            D[vecin] = min(D[vecin], D[nod] + cost);
            }
        }
    }