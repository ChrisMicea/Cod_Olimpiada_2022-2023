#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
    int n, prev1, prev2, aux;
    cin>>n;
    cout<<"n == "<<n<<"\n";
    prev1 = 1;
    prev2 = 2;
    if(n == 1)
        cout<<1<<"\n";
    else if(n == 2)
        cout<<2<<"\n";
    else{ 
        n -= 2;
        while(n--){
            aux = prev1;
            prev1 = prev2;
            prev2 = (aux + 1 + prev2) % 777013;
            cout<<"aux = "<<aux<<", prev2 = "<<prev2<<"\n";
            }
        cout<<prev2<<"\n";
    	}
}