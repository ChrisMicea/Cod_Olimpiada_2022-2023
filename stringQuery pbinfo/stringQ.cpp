#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("stringQ.in");

struct arboreInterv{
    int left, right;
    int nrDistinct;
    char v[27];
    arboreInterv* tata;
    arboreInterv* son1;
    arboreInterv* son2;
    };

int n;
arboreInterv* originea = new arboreInterv;

int main(){
    int i;
    fin>>n;
    originea->left = 1;
    originea->tata = NULL;
    for(i = 1; i <= n; i++)
        fin>>originea->v[i];                            //nu e bine
    originea->right = i - 1;
    fin.close();
    }