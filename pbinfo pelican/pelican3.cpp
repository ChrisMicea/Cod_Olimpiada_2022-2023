#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("pelican.in");
ofstream fout("pelican.out");

int main(){
    short int n, p, instructiune2, pozZ = 0, nrR = 0, nrRCurent = 0;
    int k, i, j, sumInstruction = 0, sumInstruction2 = 0, lineZ = 0, columnZ = 0, l = 0;
    fin>>n>>p>>k;
    short int instruct2[k];
    char instruct1[k];
    unsigned short int pelican[p][3];
    char instructiune1;
    for(i = 0; i < p; i++)
        fin>>pelican[i][0]>>pelican[i][1]>>pelican[i][2];                                       //citire date intrare
    for(i = 0; i < k; i++)
    //cout<<"main for\n";
    for(i = 0; i < k; i++){
        fin>>instruct1[i]>>instruct2[i];
        if(instruct1[i] == 'Z'){
            pozZ = i;
            nrRCurent = nrR;
            }
        else if(instruct1[i] == 'R')
            nrR = (nrR + instruct2[i]) % n;
        }
    if(pozZ > 0){
        lineZ = instruct2[pozZ] / n;
        columnZ = instruct2[pozZ] % n;
        for(i = 0; i < p; i++){
            pelican[i][0] = lineZ;
            pelican[i][1] = columnZ;
            }
        l = pozZ;
        for(i = 0; i < p; i++){
            if(pelican[i][2] + nrRCurent <= 4)
                pelican[i][2] += nrRCurent;
            else pelican[i][2] = pelican[i][2] + nrRCurent - 4;
            }
        }
    l++;
    //cout<<"l = "<<l<<", pozZ = "<<pozZ<<", nrRcurent = "<<nrRCurent<<"\n";
    k = k - l;
    if(k){
        instructiune1 = instruct1[l];
        instructiune2 = instruct2[l];
        }
    for(j = 0; j < k;){
        //sumInstruction = sumInstruction2 = 0;
        while(instructiune1 == 'A' && j < k){                                                   //cazul 'A' = deplasare cumulam pasii
            //cout<<"sunt in A\n";
            if(sumInstruction2 > 0){
                for(i = 0; i < p; i++){
                if(pelican[i][2] + sumInstruction2 <= 4)
                    pelican[i][2] += sumInstruction2;
                else pelican[i][2] = pelican[i][2] + sumInstruction2 - 4;
                }
                sumInstruction2 = 0;
                //cout<<"dupa R\n";
                //for(i = 0; i < p; i++)
                    //cout<<pelican[i][0]<<" "<<pelican[i][1]<<pelican[i][2]<<"\n";
                }
            sumInstruction += instructiune2;
            instructiune1 = instruct1[l];
            instructiune2 = instruct2[l++];
            j++;
            //cout<<"j de la A ++\n";
            }
        while(instructiune1 == 'R' && j < k){                                                                //cazul 'R' = zbor
            //cout<<"sunt in R\n";
            if(sumInstruction > 0){                                                              //daca avem pasi de la cauzl 'A' de executat
                sumInstruction %= n;
                for(i = 0; i < p; i++){
                    if(pelican[i][2] == 2)
                        pelican[i][1] = (pelican[i][1] + sumInstruction) % n;
                    else if(pelican[i][2] == 3)
                        pelican[i][0] = (pelican[i][0] + sumInstruction) % n;
                    else if(pelican[i][2] == 1){
                        if(sumInstruction < pelican[i][0])
                            pelican[i][0] -= sumInstruction;
                        else pelican[i][0] = (pelican[i][0] + n - (sumInstruction % n)) % n;
                        }
                    else if(pelican[i][2] == 4){
                        if(sumInstruction < pelican[i][1])
                            pelican[i][1] -= sumInstruction;
                        else{
                            pelican[i][1] = (pelican[i][1] + n - (sumInstruction % n)) % n;
                            }
                        }
                    }
                sumInstruction = 0;
                //cout<<"dupa A"<<"\n";
                //for(i = 0; i < p; i++)
                    //cout<<pelican[i][0]<<" "<<pelican[i][1]<<pelican[i][2]<<"\n";
                }
            sumInstruction2 = (sumInstruction2 + instructiune2) % 4;
            instructiune1 = instruct1[l];
            instructiune2 = instruct2[l++];
            j++;
            }
        while(instructiune1 == 'Z' && j < k){                                                       //cazul 'Z' = zbor
            //cout<<"sunt in Z\n";
            if(sumInstruction > 0){                                                              //daca avem pasi de la cauzl 'A' de executat
                sumInstruction %= n;
                for(i = 0; i < p; i++){
                    if(pelican[i][2] == 2)
                        pelican[i][1] = (pelican[i][1] + sumInstruction) % n;
                    else if(pelican[i][2] == 3)
                        pelican[i][0] = (pelican[i][0] + sumInstruction) % n;
                    else if(pelican[i][2] == 1){
                        if(sumInstruction < pelican[i][0])
                            pelican[i][0] -= sumInstruction;
                        else pelican[i][0] = (pelican[i][0] + n - (sumInstruction % n)) % n;
                        }
                    else if(pelican[i][2] == 4){
                        if(sumInstruction < pelican[i][1])
                            pelican[i][1] -= sumInstruction;
                        else{
                            pelican[i][1] = (pelican[i][1] + n - (sumInstruction % n)) % n;
                            }
                        }
                    }
                sumInstruction = 0;
                }
            if(sumInstruction2 > 0){
                for(i = 0; i < p; i++){
                if(pelican[i][2] + sumInstruction2 <= 4)
                    pelican[i][2] += sumInstruction2;
                else pelican[i][2] = pelican[i][2] + sumInstruction2 - 4;
                }
                sumInstruction2 = 0;
                }
            //lineZ = instructiune2 / n;
            //columnZ = instructiune2 % n;
            instructiune1 = instruct1[l];
            if(instructiune1 != 'Z'){
                lineZ = instructiune2 / n;
                columnZ = instructiune2 % n;
                for(i = 0; i < p; i++){
                    pelican[i][0] = lineZ;
                    pelican[i][1] = columnZ;
                    }
                }
            instructiune2 = instruct2[l++];
            j++;
            }
        }
    if(instructiune1 == 'Z'){
        lineZ = instructiune2 / n;
                columnZ = instructiune2 % n;
                for(i = 0; i < p; i++){
                    pelican[i][0] = lineZ;
                    pelican[i][1] = columnZ;
                    }
        }
    if(sumInstruction > 0)                                                              //daca avem pasi de la cauzl 'A' de executat
            sumInstruction %= n;
            for(i = 0; i < p; i++){
                if(pelican[i][2] == 2)
                    pelican[i][1] = (pelican[i][1] + sumInstruction) % n;
                else if(pelican[i][2] == 3)
                    pelican[i][0] = (pelican[i][0] + sumInstruction) % n;
                 else if(pelican[i][2] == 1){
                    if(sumInstruction < pelican[i][0])
                        pelican[i][0] -= sumInstruction;
                    else pelican[i][0] = (pelican[i][0] + n - (sumInstruction % n)) % n;
                    }
                  else if(pelican[i][2] == 4){
                    if(sumInstruction < pelican[i][1])
                        pelican[i][1] -= sumInstruction;
                    else{
                        pelican[i][1] = (pelican[i][1] + n - (sumInstruction % n)) % n;
                        }
                    }
                }
    for(i = 0; i < p; i++)
        fout<<pelican[i][0]<<" "<<pelican[i][1]<<"\n";              //afisare
    return 0;
    }