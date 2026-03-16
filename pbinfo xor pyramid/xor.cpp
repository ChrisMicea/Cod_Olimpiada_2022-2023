#include <iostream>

using namespace std;

void pyramid(int numbers[], int n);

int main(){
    int n, i;
    cin>>n;
    int numbers[n];
    for(i = 0; i < n; i++)
        cin>>numbers[i];
    while(n--){
        pyramid(numbers, n);
        }
    cout<<numbers[0]<<"\n";
    }

void pyramid(int numbers[], int n){
    int i = 1, j = 0;
    while(n--){
        numbers[j++] = numbers[i] ^ numbers[i - 1];
        i++;
        }
    numbers[i] = -1;
    }