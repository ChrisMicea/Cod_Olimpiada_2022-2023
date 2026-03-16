#include <iostream>
#include <cmath>

using namespace std;

int x[100];						//x e nr mare, x[0] = cate cifre are, x[1] - cifra unitatilor, x[2] a zecilor...

void produsMare(int n);

int main(){
	int n, pow;
    cin>>n;
    pow = n * (n - 1) / 2;
    if(n == 0)
        cout<<0;
    else{
        x[0] = 1;
        x[1] = 1;					//initializam nr cu 1
        cout<<"pow = "<<pow<<"\n";
        while(pow){
        	produsMare(3);
            for(int i = 1; i <= x[0]; i++)
                cout<<x[i];
            cout<<"\n";
            pow--;
        	}
        cout<<"aici\n";
        for(int i = 1; i <= x[0]; i++)
            cout<<x[i];
        }
}

void produsMare(int n){
    int i, t = 0;
    for(i = 1; i <= x[0]; i++, t /= 10){
    	t += x[i] * n;
        x[i] = t % 10;				//adaugam produsul, in t mai ramane restul ce nu incape in o cifra
     	}							//(ceea ce tinem minte, ca pe foaie)
    for(; t; t/=10){
        x[0]++;						//mai adaugam o cifra
        x[x[0]] = t % 10;			//acea cifra va fi de la rest
    	}
	}