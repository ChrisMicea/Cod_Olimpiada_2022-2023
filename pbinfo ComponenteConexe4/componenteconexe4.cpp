#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("file.in");

const int nmax = 100003;
int rang[nmax], tt[nmax], n, m;
stack <pair<int, int>> st;
stack <int> sol;

void read(void);
void solve(void);
void print(void);
int root(int nod);
void reuniune(int leftroot, int rightroot);

int main(){
    read();
    solve();
    print();
    fin.close();
    }

void read(void){
    int i, x, y;
    fin>>n>>m;
    for(i = 1; i <= m; i++){
        fin>>x>>y;
        st.push(make_pair(x, y));
        }
    }

void solve(void){
    int x, y, leftroot, rightroot;
    while(!st.empty()){
        sol.push(n);
        x = st.top().first;
        y = st.top().second;
        st.pop();
        leftroot = root(x);
        rightroot = root(y);
        reuniune(leftroot, rightroot);
        }
    }

int root(int nod){
    if(!tt[nod])
        return nod;
    else{
        int val = root(tt[nod]);
        tt[nod] = val;
        return val;
        }
    }

void reuniune(int leftroot, int rightroot){
    if(leftroot != rightroot){
        if(rang[leftroot] > rang[rightroot])
            tt[rightroot] = leftroot;
        else{
            tt[leftroot] = rightroot;
            if(rang[leftroot] == rang[rightroot])
                rang[rightroot] ++;
            }
        n--;
        }
    }

void print(void){
    while(!sol.empty()){
        cout<<sol.top()<<"\n";
        sol.pop();
        }
    }