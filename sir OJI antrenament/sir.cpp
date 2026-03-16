/*#include <iostream>
#include <fstream>
#undef next

using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

struct sir{
    int val;
    sir* next;
    };

void read(void);
void solve(void);
void precalc(void);

int n, q, lastVal, k = 1;
unsigned long long int sumPart[1000003];
sir* first;
sir* last;
sir* contor;

int main(){
    read();
    precalc();
    solve();
    fin.close();
    fout.close();
    }

void read(void){
    int i;
    fin>>n>>q;
    first = last = new sir;
    fin>>first->val;
    if(first->val)
        lastVal = first->val;
    sumPart[k++] = first->val;
    for(i = 2; i <= n; i++){
        last->next = new sir;
        fin>>last->next->val;
        sumPart[k] = sumPart[k - 1] + last->next->val;
        k++;
        lastVal = last->next->val;
        last = last->next;
        }
    }

void solve(void){
    int l, r;
    //for(int i = 1; i <= 50; i++)
    //    cout<<sumPart[i]<<" ";
    //cout<<"\n";
    while(q--){
        fin>>l>>r;
        fout<<sumPart[r] - sumPart[l - 1]<<"\n";
        }
    }

void precalc(void){
    int i = n, nrNenul, j;
    nrNenul = lastVal;
    sir* firstIntermediar;
    //sir* curent;
    //cout<<"lastval = "<<lastVal<<"\n";
    //for(i = 0; i < n; i++){
    //    sumPart[i] = sumPart[i - 1] + contor->val;
    //    contor = contor->next;
    //    }
    while(i <= 100002){
        //if(k >= 14)
        //    return;
        //if(k >= 20)
        //    return;
        //for(j = 0, curent = first; j < n; j++, curent = curent->next){
        //    cout<<curent->val<<" ";
        //    }
        //cout<<"\n";
        last->next = new sir;
        if(nrNenul % 2){
            last->next->val = ++lastVal;
            nrNenul++;
            }
        else last->next->val = 0;
        sumPart[k] = sumPart[k - 1] + last->next->val;
        k++;
        last = last->next;
        if(first->val)
            nrNenul--;
        firstIntermediar = first->next;
        delete first;
        first = firstIntermediar;
        i++;
        }
    }*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

int main(){
    int n, n2, q, useless, l, r;
    fin>>n>>q;
    n2 = n;
    while(n2--){
        fin>>useless;
        }
    while(q--){
        fin>>l>>r;
        fout<<(l + r) * (r - l + 1) / 2<<"\n";
        }
    }