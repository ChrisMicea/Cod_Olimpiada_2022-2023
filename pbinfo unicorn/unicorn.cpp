/*#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("unicorn.in");
ofstream fout("unicorn.out");

void read(void);
void solveAndPrint(void);

const int maxn = 100003;
int n, max, maxpoz;
struct tort{
    int raza = 0, valoare = 0;
    }v[maxn];
struct dynamicprogram{
    int razaStart, valoareSum, nrAparitii = 0;
    dynamicprogram* prev;
    };

int main(){
    read();
    solveAndPrint();
    fin.close();
    fout.close();
    }

void read(void){
    int i;
    fin>>n;
    for(i = 1; i <= n; i++)
        fin>>v[i].raza>>v[i].valoare;
    }

void solveAndPrint(void){
    int i, nrOfDP = 1;
    dynamicprogram* first;
    dynamicprogram* last;
    dynamicprogram* dp;
    dp = new dynamicprogram;
    first = last = dp;
    dp->prev = NULL;
    dp->nrAparitii++;
    dp->razaStart = v[n].raza;
    dp->valoareSum = v[n].valoare;
    for(i = n - 1; i >= 1; i--){
        if(v[i].valoare)
        }    
    }*/

/*#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("unicorn.in");
ofstream fout("unicorn.out");

void read(void);
void solveAndPrint(void);

stack <int> tt;
const int maxn = 100003;
int n, maxim, maxpoz, maxNrAparitii = 0;
struct tort{
    int raza = 0, valoare = 0;
    }v[maxn];
struct dynamoprogr{
    int razaCurent = 0, valoareSum = 0, nrAparitii = 0, tata = 0;
    }dp[maxn];

int main(){
    read();
    solveAndPrint();
    fin.close();
    fout.close();
    }

void read(void){
    int i;
    fin>>n;
    for(i = n; i >= 1; i--)
        fin>>v[i].raza>>v[i].valoare;
    }

void solveAndPrint(void){
    int i, j;
    bool ok;
    dp[n].nrAparitii++;
    dp[n].razaCurent = v[n].raza;
    dp[n].valoareSum += v[n].valoare;
    for(i = n - 1; i >= 1; i--){
        ok = true;
        for(j = i + 1; j <= n; j++){
            //if(i == 1)
            //    cout<<"j == "<<j<<"\n";
            if(v[i].raza < dp[j].razaCurent && dp[i].valoareSum < dp[j].valoareSum + v[i].valoare){
                dp[i].tata = j;
                //if(i == 1)
                //    cout<<"here\n";
                dp[i].razaCurent = v[i].raza;
                dp[i].valoareSum = dp[j].valoareSum + v[i].valoare;
                dp[i].nrAparitii = dp[j].nrAparitii + 1;
                if(dp[i].valoareSum > maxim){
                    maxim = dp[i].valoareSum;
                    maxpoz = i;
                    maxNrAparitii = dp[i].nrAparitii;
                    }
                else if(dp[i].valoareSum == maxim)
                    if(dp[i].nrAparitii > maxNrAparitii){
                        maxim = dp[i].valoareSum;
                        maxpoz = i;
                        maxNrAparitii = dp[i].nrAparitii;
                        }
                ok = false;
                //break;
                }
            }
        if(ok){
            //cout<<"ok\n";
            dp[i].nrAparitii++;
            dp[i].razaCurent = v[i].raza;
            dp[i].valoareSum += v[i].valoare;
            dp[i].tata = 0;
            if(dp[i].valoareSum > maxim){
                    maxim = dp[i].valoareSum;
                    maxpoz = i;
                    maxNrAparitii = dp[i].nrAparitii;
                    }
            else if(dp[i].valoareSum == maxim)
                    if(dp[i].nrAparitii > maxNrAparitii){
                        maxim = dp[i].valoareSum;
                        maxpoz = i;
                        maxNrAparitii = dp[i].nrAparitii;
                        }
            }
        }
    //for(i = 1; i <= n; i++)
    //    cout<<dp[i].tata<<"\n";
    //    cout<<i<<": raza = "<<dp[i].razaCurent<<", valoaresum = "<<dp[i].valoareSum<<", nraparitii = "<<dp[i].nrAparitii<<"\n";
    for(i = maxpoz; dp[i].tata != 0; i = dp[i].tata)
        tt.push(n - i + 1);
    tt.push(n - i + 1);
    fout<<maxim<<" "<<dp[maxpoz].nrAparitii<<"\n";
    while(!tt.empty()){
        fout<<tt.top()<<" ";
        tt.pop();
        }
    fout<<"\n";
    }*/

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream fin("unicorn.in");
ofstream fout("unicorn.out");

stack <int> tt;
const int maxn = 100003;
int n, maxim, maxLenTorturi, maxNrAparitii = 0; 
struct tort{
    int raza = 0, valoare = 0;
    }v[maxn];
struct TRIE{
    int nrOfSons, raza, valoare, indice, height;
    TRIE* tata;
    TRIE(){
        raza = nrOfSons = valoare = indice = height = 0;
        tata = NULL;
        }
    vector <TRIE*> son;
    };
TRIE* maxpoz;

void read(void);
void solveAndPrint(void);
void parcurgereTrie(TRIE* p);
int add(TRIE* p, int vIndex);

int main(){
    read();
    solveAndPrint();
    fin.close();
    fout.close();
    }

void read(void){
    int i;
    fin>>n;
    for(i = n; i >= 1; i--)
        fin>>v[i].raza>>v[i].valoare;
    }

void solveAndPrint(void){
    int i;
    TRIE* t = new TRIE;
    t->raza = 1000000001;
    t->height = 0;
    for(i = n; i >= 1; i--)
        add(t, i);
    parcurgereTrie(maxpoz);
    fout<<maxim<<" "<<maxpoz->height<<"\n";
    while(!tt.empty()){
        fout<<tt.top()<<" ";
        tt.pop();
        }
    fout<<"\n";
    /*for(i = maxpoz; dp[i].tata != 0; i = dp[i].tata)
        tt.push(n - i + 1);
    tt.push(n - i + 1);
    fout<<maxim<<" "<<dp[maxpoz].nrAparitii<<"\n";
    while(!tt.empty()){
        fout<<tt.top()<<" ";
        tt.pop();
        }
    fout<<"\n";*/
    }

int add(TRIE* p, int vIndex){
    bool ok = false;
    int i;
    if(v[vIndex].raza < p->raza){
        for(i = 0; i < p->nrOfSons; i++)
            if(add(p->son[i], vIndex))
                ok = true;
        if(!ok){
            p->nrOfSons++;
            TRIE* nou = new TRIE;
            p->son.push_back(nou);
            nou->raza = v[vIndex].raza;
            nou->valoare = v[vIndex].valoare + p->valoare;
            nou->indice = n - vIndex + 1;
            nou->height = p->height + 1;
            if(nou->valoare > maxim){
                maxim = nou->valoare;
                maxpoz = nou;
                /*int k = 1;
                TRIE* p2 = p;
                while(p2->tata != 0){
                    p2 = p2->tata;
                    k++;
                    }*/
                maxLenTorturi = nou->height;
                }
            else if(nou->valoare == maxim){
                /*int k = 1;
                TRIE* p2 = nou;
                while(p2->tata != NULL){
                    p2 = p2->tata;
                    k++;
                    }*/
                if(nou->height > maxLenTorturi){
                    maxLenTorturi = nou->height;
                    maxim = nou->valoare;
                    maxpoz = nou;
                    }
                }
            nou->tata = p;
            return 1;
            }
        }
    return 0;
    }

void parcurgereTrie(TRIE* p){
    if(p->tata != NULL){
        tt.push(p->indice);
        //u++;
        parcurgereTrie(p->tata);
        }
    /*cout<<"valoare = "<<p->valoare<<", raza = "<<p->raza<<", tata = "<<p->tata<<", nr fiilor = "<<p->nrOfSons<<"\n";
    for(int i = 0; i < p->nrOfSons; i++)
        parcurgereTrie(p->son[i]);*/
    }