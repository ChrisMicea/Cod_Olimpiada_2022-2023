#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ceas.in");
ofstream fout("ceas.out");

int main(){
    unsigned int n, rez = 0;
    unsigned short c, x, val;
    cin>>c>>x>>n;
    if(c == 1){
        while(n--){
            cin>>val;
            while(val){
                if(val % 10 == x)
                    rez++;
                val /= 10;
                }
            }
        cout<<rez<<"\n";
        }
    else if(c == 2){
        while(n--){
            cin>>val;
            while(val / 10 != 0){
                if(val % 10 > 2 && (val / 10) % 10 > 2){
                    //cout<<"caz1\n";
                    val /= 100;
                    if(val)
                        rez += 2;
                    else rez++;
                    }
                else if(val % 10 <= 2 && (val / 10) % 10 == 1){
                    //cout<<"caz2\n";
                    val /= 100;
                    if(val)
                        rez++;
                    }
                else{
                    //cout<<"caz3\n";
                    val /= 10;
                    if(val)
                        rez++;
                    }
                }
            }
        cout<<rez<<"\n";
        }
    return 0;
    }