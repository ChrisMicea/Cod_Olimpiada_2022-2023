#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("platforma.in");
ofstream fout("platforma.out");

void case1(void);
void case2(void);
void case3(void);
void case4(void);

int opt;

int main(){
    fin>>opt;
    if(opt == 1)
        case1();
    else if(opt == 2)
        case2();
    else if(opt == 3)
        case3();
    else case4();
    }

void case1(void){
    int n, i, sir, contor = 0, prev = -1, val;
    bool read;
    fin>>n;
    for(i =  1; i <= n; ){
        if(!read)
            fin>>sir;
        else read = false;
        if(sir != i){
            val = sir;
            while(sir != i){
                contor++;
                i++;
                if(i > n){
                    cout<<"0\n";
                    return;
                    }
                fin>>sir;
                }
            if(contor != (val - 1) || val != prev){
                fout<<"0\n";
                return;
                }
            contor = 0;
            prev = sir;
            read = true;
            }
        else i++;
        prev = sir;
        }
    fout<<"1\n";
    }

void case2(void){
    ;
    }

void case3(void){
    ;
    }

void case4(void){
    ;
    }