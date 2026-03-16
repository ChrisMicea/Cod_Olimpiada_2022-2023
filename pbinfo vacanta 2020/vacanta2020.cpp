#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("festivaluri.in");
ofstream fout("festivaluri.out");

const int nmax = 103;

vector <pair<int, int>> graph[nmax];

int putere, n, m, z, r;
int festivaluri[nmax], drumuri[nmax];
int d[nmax];
bool viz[nmax];

void read(void);
void dijkstra(int poz);

int main(){
    int i, k = 0, j, sol = 0;
    read();
    dijkstra(z);
    for(i = 1; i <= n; i++)
        if(d[i] != 0 && d[i] != 1000000)
            for(j = 1; j <= r; j++)
                if(i == festivaluri[j])
                    drumuri[k++] = d[i];
    sort(drumuri, drumuri + k);
    for(i = 0; i < k; i++)
        if(drumuri[i] <= putere){
            putere -= drumuri[i];
            sol++;
            }
    fout<<sol;
    fin.close();
    fout.close();
    }

void read(void){
    int x, y, u;
    fin>>n>>m>>putere>>z>>r;
    while(m--){
        fin>>x>>y>>u;
        graph[x].push_back(make_pair(y, u));
        }
    for(x = 1; x <= r; x++)
        fin>>festivaluri[x];
    }

void dijkstra(int poz){
    int i, j, k, minim, nod;
    for(i = 1; i <= n; i++){
        d[i] = 1000000;
        viz[i] = false;
        }
    d[poz] = 0;
    for(i = 1; i <= n; i++){
        minim = 1000000;
        for(j = 1; j <= n; j++)
            if(d[j] < minim && viz[j] == false){
                minim = d[j];
                nod = j;
                }
        viz[nod] = true;
        for(k = 0; k < graph[nod].size(); k++){
            int vecin = graph[nod][k].first;
            int cost = graph[nod][k].second;
            d[vecin] = min(d[vecin], d[nod] + cost);
            }
        }
    }