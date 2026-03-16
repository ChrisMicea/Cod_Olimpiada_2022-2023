#include <iostream>

using namespace std;

int main(){
    int n;
    long long int m;
    cin>>n>>m;
    int i, contorSolMax = n - 2;
    if(m == 0)
        cout<<n<<" "<<n<<"\n";
    else{
        if(n > 2 * m)
            cout<<(n - 2 * m)<<" ";
        else cout<<"0 ";
        m--;
        for(i = 3; m > 0; i++){
            m -= (i - 1);
            contorSolMax--;
            }
        cout<<contorSolMax<<"\n";
        }
    }