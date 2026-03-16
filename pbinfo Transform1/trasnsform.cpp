#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

const int nMax = 256003;
int n, x, y, maxim;
int v[nMax], tata[nMax], son[nMax], contor[nMax]; 

void read(void);
void solve(void);
int root(int nod);

int main(){
    read();
    solve();
    }

/*void read(void){
    fin>>n>>x>>y;
    for(int i = 1; i <= n; i++){
        fin>>v[i];
        sumPart[i] = sumPart[i - 1] + v[i];
        //cout<<v[i]<<" "<<sumPart[i]<<"\n";
        }
    }

void solve(void){
    int w, i, sum, j, val;
    for(i = 1; i <= n; i++){
        sum = 0;
        w = 1 + (x * i + y * v[i]) % n;
        sum += sumPart[i - 1];
        val = v[i];
        for(j = i; j <= n; j++){
            if(v[j] == val){
                sum += w;
                sumPart[j] = sumPart[j - 1] + w;
                v[j] = w;
                }
            else sum += v[j];
            }
        //for(int k = 1; k <= n; k++)
            //cout<<v[k]<<" ";
        //cout<<"\n";
        //cout<<"pt i = "<<i<<", sum = "<<sum<<", w = "<<w<<"\n";
        if(sum > maxim)
            maxim = sum;
        }
    fout<<maxim<<"\n";
    }*/

void read(void){
    int i, j;
    bool ok;
    fin>>n>>x>>y;
    for(i = 1; i <= n; i++){
        fin>>v[i];
        ok = false;
        for(j = i - 1; j >= 1; j--)
            if(v[j] == v[i]){
                contor[root(j)]++;
                tata[i] = j;
                son[j] = i;
                ok = true;
                break;
                }
        if(!ok){
            tata[i] = v[i] * -1;
            contor[i]++;
            }
        }
    /*for(i = 1; i <= n; i++)
        cout<<tata[i]<<" ";
    cout<<"\n";
    for(i = 1; i <= n; i++)
        cout<<son[i]<<" ";
    cout<<"\n";
    for(i = 1; i <= n; i++)
        cout<<contor[i]<<" ";
    cout<<"\n";*/
    }

void solve(void){
    int w, i, sum = 0, j, val;
    for(i = 1; i <= n; i++){
        w = 1 + (x * i + y * root(i)) % n;
        sum += w;
        }
    }

int root(int nod){
    if(tata[nod] < 0)
        return -1 * nod;
    else return root(tata[nod]);
    }