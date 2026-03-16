#include <iostream>
#include <fstream>
#include <stack>
#include <cmath>

using namespace std;

ifstream fin("expeditie.in");
ofstream fout("expeditie.out");

void read(void);
void solve(void);

int t[33][33], a[33][33], dptimp[33][33];
int n, m, k;
stack <pair<int, int>> st;
stack <int> energy;

int main(){
    read();
    solve();
    fin.close();
    fout.close();
    }

void read(void){
    int i, j;
    fin>>n>>m>>k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            fin>>a[i][j];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            fin>>t[i][j];
    }

void solve(void){
    int i, j, energCurent, energFin = -1;
    st.push(make_pair(n, m));
    dptimp[n][m] = 100000;
    energy.push(a[n][m]);
    while(!st.empty()){
        i = st.top().first;
        j = st.top().second;
        st.pop();
        energCurent = energy.top();
        energy.pop();
        if(i + 1 <= n && energCurent + abs(a[i + 1][j]) <= k){
            if(i + 1 == n && j == m && dptimp[i][j] + t[i + 1][j] < dptimp[n][m]){
                dptimp[i + 1][j] = dptimp[i][j] + t[i + 1][j];
                energFin = energCurent + abs(a[i + 1][j]);
                }
            else dptimp[i + 1][j] = dptimp[i][j] + t[i + 1][j];
            if(a[i + 1][j] < 0)
                energy.push(0);
            else energy.push(energCurent + abs(a[i + 1][j]));
            st.push(make_pair(i + 1, j));
            }
        if(j + 1 <= m && energCurent + abs(a[i][j + 1]) <= k){
            if(i == n && j + 1 == m && dptimp[i][j] + t[i][j + 1] < dptimp[n][m]){
                dptimp[i][j + 1] = dptimp[i][j] + t[i][j + 1];
                energFin = energCurent + abs(a[i][j + 1]);
                }
            else dptimp[i][j + 1] = dptimp[i][j] + t[i][j + 1];
            if(a[i][j + 1] < 0)
                energy.push(0);
            else energy.push(energCurent + abs(a[i][j + 1]));
            st.push(make_pair(i, j + 1));
            }
        if(i + 1 <= n && j + 1 <= m && energCurent + abs(a[i + 1][j]) <= k){
            if(i + 1 == 1 && j + 1 == 1 && dptimp[i][j] + t[i + 1][j + 1] < dptimp[1][1]){
                dptimp[i + 1][j + 1] = dptimp[i][j] + t[i + 1][j + 1];
                energFin = energCurent + abs(a[i + 1][j + 1]);
                }
            else dptimp[i + 1][j + 1] = dptimp[i][j] + t[i + 1][j + 1];
            if(a[i + 1][j + 1] < 0)
                energy.push(0);
            else energy.push(energCurent + abs(a[i + 1][j + 1]));
            st.push(make_pair(i + 1, j + 1));
            }
        }
    if(energFin = -1)
        fout<<"Nu exista drum";
    else fout<<dptimp[n][m]<<"\n"<<energFin;
    }