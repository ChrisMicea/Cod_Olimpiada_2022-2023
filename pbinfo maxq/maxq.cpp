#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxq.in");
ofstream fout("maxq.out");

void read(void);
void Build(int Nod, int Left, int Right);
void Update(int Nod, int Left, int Right, int Pos, int v);

int n, m;
const int maxn = 200003;
int arb[4 * maxn + 3], sir[maxn + 3];

int main(){
    int x, y, z, i;
    read();
    Build(1, 1, n);
    while(m--){
        fin>>x>>y>>z;
        if(!x){
            sir[++y] = z;
            Update(1, 1, n, x, y);
            }
        else{
            
            }
        }
    }

void read(void){
    int i;
    fin>>n;
    for(i = 0; i < n; i++)
        fin>>sir[i];
    fin>>m;
    }

void Build(int Nod, int Left, int Right){
    if(Left==Right){
        arb[Nod] = sir[Left];
        return;
        }
    int Mid = (Left + Right) / 2;
    Build(2 * Nod, Left, Mid);
    Build(2 * Nod + 1, Mid + 1, Right);
    //arb[Nod] = max(arb[Nod * 2], arb[Nod * 2 + 1]);           smecheria cu subsirul maxim
    if(arb[2 * Nod] < 0 && arb[Nod * 2 + 1] < 0)
        arb[Nod] = max(arb[Nod * 2], arb[Nod * 2 + 1]);
    else if(arb[2 * Nod] < 0)
        arb[Nod] = arb[Nod * 2 + 1];
    else if(arb[Nod * 2 + 1] < 0)
        arb[Nod] = arb[Nod * 2];
    else{
        
        }
    }

void Update(int Nod, int Left, int Right, int Pos, int v){
    //left, right - intuitiv; v - valoarea cu care trebuie updatat elementul de la pozitia poz; nod - pozitia curenta din vector/arbore
    if(Right==Left){                     //cauta,de fapt, pozitia in care left = right = pos
        arb[Nod]=v;
        return;
        }
    int Mid = (Left + Right) / 2;
    if(Pos <= Mid){
        Update(2 * Nod, Left, Mid, Pos, v);
        }
    else{
        Update(2 * Nod + 1, Mid + 1, Right, Pos, v);
        }
    //arb[Nod] = max(arb[2 * Nod], arb[2 * Nod + 1]);           smecheria cu subsirul maxim
    }
