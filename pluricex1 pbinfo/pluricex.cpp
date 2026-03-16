#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("pluricex1.in");
ofstream fout("pluricex1.out");

struct membru{
    int nrMaterii;
    int discipline[11];
    }elev[23];

void backtrack(int poz, int sol[], int nr, int elevii[], int nrElev, int solCurent[]);
void afis(int elevii[]);
void combinari(int poz, int elevii[], int nrelev);

int n, k, d, solut[11];

int main(){
    fin>>n>>k>>d;
    int i, j, elevii[23], solCurent[11];
    for(i = 0; i < n; i++){
        fin>>elev[i].nrMaterii;
        for(j = 0; j < elev[i].nrMaterii;  j++)
            fin>>elev[i].discipline[j];
        }
    elevii[0] = -1;
    backtrack(0, solut, 0, elevii, 0, solCurent);
    }

void backtrack(int poz, int sol[], int nr, int elevii[], int nrElev, int solCurent[]){
    int i, j, h, solNul[11], u, nrCurent = nr;
    bool prezent, ok = true;
    for(u = 0; u < d; u++)
        solCurent[u] = sol[u];
    for(i = poz; i < n; i++){
        for(j = 0; j < elev[i].nrMaterii; j++){
            prezent = false;
            for(h = 0; h < nr; h++){
                if(elev[i].discipline[j] == solCurent[h]){
                    prezent = true;
                    break;
                    }
                }
            if(!prezent){
                solCurent[nrCurent++] = elev[i].discipline[j];
                //cout<<"pt i = "<<i<<", se adauga "<<elev[i].discipline[j]<<" pe pozitia "<<nrCurent - 1<<"\n";
                //if(elevii[nrElev] != i){
                    //elevii[nrElev] = i;
                    //ok = false;
                    //}
                }
            }
        
        /*if(!ok)
            nrElev++;
        if(nrCurent == d && nrElev < k && ok){
            if(i == 5)
                cout<<"5 bagat, nrelev = "<<nrElev + 1<<", poz = "<<poz<<"\n";*/
            elevii[nrElev] = i;
            nrElev++;
            //}
        /*if(i == 4){
            for(u = 0; u < d; u++)
                cout<<solCurent[u]<<" ";
            cout<<"\n";
            }*/
        if(nrElev > k)
            return;
        /*else if(nrElev < k && nrCurent == d){
            combinari(i + 1, elevii, nrElev);
            nrCurent = nr;
            nrElev--;
            continue;
            }*/
        else if(nrElev < k && nrCurent <= d && (n - i >= k - nrElev)){
            //cout<<"back\n";
            backtrack(i + 1 , solCurent, nrCurent, elevii, nrElev, solNul);
            nrCurent = nr;
            }
        else if(nrElev == k && nrCurent == d){
            //cout<<"afisam\n";
            afis(elevii);
            nrCurent = nr;
            }
        for(u = 0; u < d; u++)
            solCurent[u] = sol[u];
        nrCurent = nr;
        nrElev--;
        ///cout<<"return, i increments from "<<i<<" to "<<i + 1<<", nrElev devine "<<nrElev<<" din "<<nrElev + 1<<"\n";
        /*if(i == 4){
            for(u = 0; u < d; u++)
                cout<<solCurent[u]<<" ";
            cout<<"\n";
            }*/
        }
    }

void afis(int elevii[]){
    for(int i = 0; i < k; i++)
        fout<<elevii[i] + 1<<" ";
    fout<<"\n";
    /*for(int i = 0; i < k; i++)
        cout<<elevii[i] + 1<<" ";
    cout<<"\n";*/
    }

void combinari(int poz, int elevii[], int nrelev){
    for(int i = poz; i < n; i++){
        elevii[nrelev++] = i;
        if(nrelev == k)
            afis(elevii);
        else if(n - i >= k - nrelev)
            combinari(i + 1, elevii, nrelev);
        nrelev--;
        }
    }