#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("pelican.in");
ofstream fout("pelican.out");

int main(){
    short int n, p, instructiune2;
    int k, i, j, sumInstruction = 0, sumInstruction2 = 0, lineZ = 0, columnZ = 0;;
    fin>>n>>p>>k;
    unsigned short int pelican[p][3];
    char instructiune1;
    for(i = 0; i < p; i++)
        fin>>pelican[i][0]>>pelican[i][1]>>pelican[i][2];                                       //citire date intrare
    //cout<<"main for\n";
    fin>>instructiune1>>instructiune2;
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
            fin>>instructiune1>>instructiune2;
            j++;
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
            fin>>instructiune1>>instructiune2;
            /*for(i = 0; i < p; i++){
                if(pelican[i][2] + instructiune2 <= 4)
                    pelican[i][2] += instructiune2;
                else pelican[i][2] = pelican[i][2] + instructiune2 - 4;
                }*/
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
            fin>>instructiune1;
            if(instructiune1 != 'Z'){
                lineZ = instructiune2 / n;
                columnZ = instructiune2 % n;
                for(i = 0; i < p; i++){
                    pelican[i][0] = lineZ;
                    pelican[i][1] = columnZ;
                    }
                }
            fin>>instructiune2;
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