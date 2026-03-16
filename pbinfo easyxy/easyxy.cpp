#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("easyxy.in");
ofstream fout("easyxy.out");

void read(void);
void Build(int Nod, int Left, int Right);
void query(int nod, int left, int right, int qleft, int qright);

const int nmax = 100003;
int n, m, sir[nmax];
struct arbore{
    vector <int> v;
    }arbint[4 * nmax];
vector <int> qvector;

int main(){
    int x, y, z;
    read();
    Build(1, 1, n);
    while(m--){
        fin>>x>>y>>z;
        qvector.clear();                              //il facem sa aiba dimensiunea/sa contina 0 elemente
        query(1, 1, n, x, y);
        sort(qvector.begin(), qvector.end());
        fout<<qvector[z - x]<<"\n";
        }
    }

void read(void){
    fin>>n>>m;
    int i, x, y, z;
    for(i = 1; i <= n; i++)
        fin>>sir[i];
    }

void Build(int Nod, int Left, int Right){
    if(Left==Right){
        arbint[Nod].v.push_back(sir[Left]);
        return;
        }
    int Mid = (Left + Right) / 2;
    Build(2 * Nod, Left, Mid);
    Build(2 * Nod + 1, Mid + 1, Right);
    int i;
    for(i = 0; i < arbint[2 * Nod].v.size(); i++)
        arbint[Nod].v.push_back(arbint[2 * Nod].v[i]);
    for(i = 0; i < arbint[2 * Nod + 1].v.size(); i++)
        arbint[Nod].v.push_back(arbint[2 * Nod + 1].v[i]);
    sort(arbint[Nod].v.begin(), arbint[Nod].v.end());
    }

void query(int nod, int left, int right, int qleft, int qright){
    if(right < qleft || left > qright)
        return;
    else if(right <= qright && left >= qleft){
        for(int i = 0; i < arbint[nod].v.size(); i++)
            qvector.push_back(arbint[nod].v[i]);
        return;
        }
    int mid = (left + right) / 2;
    query(2 * nod, left, mid, qleft, qright);
    query(2 * nod + 1, mid + 1, right, qleft, qright);
    }
