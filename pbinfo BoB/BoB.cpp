#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

ifstream fin("file.in");

struct listaDubla{
    listaDubla* prev; 
    listaDubla* next;
    long int valoare = 0;
    int greutate = 0;
    };

int main(){
    int n, sir[2][3000], i, j;
    listaDubla *start;
    listaDubla *curent;
    listaDubla *nou;
    bool ok;
    fin>>n;
    for(i = 0; i < n; i++)
        fin>>sir[0][i]>>sir[1][i];
    start = (listaDubla*)malloc(sizeof(listaDubla));
    start->greutate = sir[0][n - 1];
    start->valoare = sir[1][n - 1];
    start->next = NULL;
    start->prev = NULL;
    for(i = n - 2; i >= 0; i--){
        ok = false;
        for(curent = start; curent != NULL; curent = curent->next)
            if(sir[0][i] < curent->greutate){
                ok = true;
                sir[1][i] += curent->valoare;
                while((curent != NULL) && (sir[1][i] > curent->valoare))
                    curent = curent->prev;
                nou = (listaDubla*)malloc(sizeof(listaDubla));
                nou->greutate = sir[0][i];
                nou->valoare = sir[1][i];
                if(curent != NULL){
                    curent->next->prev = nou;
                    nou->prev = curent;
                    nou->next = curent->next;
                    curent->next = nou;
                    }
                else{
                    nou->next = start;
                    nou->prev = NULL;
                    start->prev = nou;
                    start = nou;
                    }
                break;
                }
            if(!ok){
                for(curent = start; curent->next != NULL && curent->valoare > sir[1][i]; curent = curent->next)
                    ;
                nou = (listaDubla*)malloc(sizeof(listaDubla));
                nou->greutate = sir[0][i];
                nou->valoare = sir[1][i];
                nou->next = curent;
                if(curent != start && curent->next != NULL || (curent->next == NULL && curent->valoare < sir[1][i])){
                    nou->prev = curent->prev;
                    curent->prev = nou;
                    nou->prev->next = nou;
                    }
                else if(curent == start){
                    if(curent->valoare < sir[1][i]){
                        nou->prev = curent->prev;
                        curent->prev = nou;
                        start = nou;
                        }
                    else{
                        nou->next = curent->next;
                        curent->next->prev = nou;
                        nou->prev = curent;
                        curent->next = nou;
                        }
                    }
                else{
                    curent->next = nou;
                    nou->next = NULL;
                    nou->prev = curent;
                    }
                }
        }
    cout<<start->valoare<<"\n";
    }