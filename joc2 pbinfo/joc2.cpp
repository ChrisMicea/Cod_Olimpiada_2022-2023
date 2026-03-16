#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("joc2.in");
ofstream fout("joc2.out");

int matrixCitire[104][104], jocDiana[104][104], jocJohnny[104][104];
queue <int> q;

int main(){
    int i, j, n, m;
    int punctajDiana = 0, punctajJohnny = 0;
    fin>>n>>m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            fin>>matrixCitire[i][j];
    if(n == 1 || m == 1){
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                punctajDiana += matrixCitire[i][j];
        fout<<"3 "<<punctajDiana<<"\n";
        }     
    else{
        jocJohnny[n][1] = matrixCitire[n][1];                   //johnny stanga sau jos
        jocDiana[n][m] = matrixCitire[n][m];                    //diana dreapta sau jos
        q.push(n);
        q.push(m - 1);
        q.push(n - 1);
        q.push(m);
        while(!(q.empty())){
            i = q.front();
            q.pop();
            j = q.front();
            q.pop();
            //cout<<"i = "<<i<<", j = "<<j<<"\n";
            jocDiana[i][j] = max(jocDiana[i + 1][j], jocDiana[i][j + 1]) + matrixCitire[i][j];
            //if(i <= 2 || j <= 2)
            //fout<<"joc["<<i<<"]["<<j<<"] = "<<jocDiana[i][j]<<"\n";
            if(j - 1){
                if(q.front() != i){
                    q.push(i);
                    q.push(j - 1);
                    }
                }
            if(i - 1){
                if(q.front() != i - 1){
                    q.push(i - 1);
                    q.push(j);
                    }
                }
            }
        punctajDiana = jocDiana[1][1];

        q.push(n);
        q.push(2);
        q.push(n - 1);
        q.push(1);
        while(!q.empty()){
            i = q.front();
            q.pop();
            j = q.front();
            q.pop();
            jocJohnny[i][j] = max(jocJohnny[i + 1][j], jocJohnny[i][j - 1]) + matrixCitire[i][j];
            if(j + 1 <= m){
                if(q.front() != i){
                    q.push(i);
                    q.push(j + 1);
                    }
                }
            if(i - 1){
                if(q.front() != i - 1){
                    q.push(i - 1);
                    q.push(j);
                    }
                }
            }
        punctajJohnny = jocJohnny[1][m];
        //fout<<"punctajJohnny = "<<punctajJohnny<<"\n";
        //fout<<"punctajDiana = "<<punctajDiana<<"\n";
        if(punctajDiana > punctajJohnny)
            fout<<"1 "<<punctajDiana<<"\n";
        else if(punctajDiana == punctajJohnny)
            fout<<"3 "<<punctajDiana<<"\n";
        else fout<<"2 "<<punctajJohnny<<"\n";
        }
    fin.close();
    fout.close();
    }

/*#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("joc2.in");
ofstream fout("joc2.out");

int matrixCitire[104][104], jocDiana[104][104], jocJohnny[104][104];
int q[100003];

int main(){
    int i, j, n, m;
    int punctajDiana = 0, punctajJohnny = 0;
    int* top;
    int* bot;
    top = bot = q;
    fin>>n>>m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            matrixCitire[i][j] = 0;
    cout<<"here1\n";
    if(n == 1 || m == 1){
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                punctajDiana += matrixCitire[i][j];
        fout<<"3 "<<punctajDiana<<"\n";
        }     
    else{
        cout<<"here2\n";
        jocJohnny[n][1] = matrixCitire[n][1];                   //johnny stanga sau jos
        jocDiana[n][m] = matrixCitire[n][m];                    //diana dreapta sau jos
        *top = n;
        *(++top) = m - 1;
        *(++top) = n - 1;
        *(++top) = m;
        cout<<"here3\n";
        while(top > bot){
            i = *bot;
            cout<<"i = "<<i<<", ";
            bot++;
            j = *bot;
            cout<<"j = "<<j<<"\n";
            bot++;
            jocDiana[i][j] = max(jocDiana[i + 1][j], jocDiana[i][j + 1]) + matrixCitire[i][j];
            if(i - 1){
                *(++top) = i - 1;
                *(++top) = j;
                }
            if(j - 1){
                *(++top) = i;
                *(++top) =  j - 1;
                }
            }
        punctajDiana = jocDiana[1][1];
        cout<<"here3\n";
        top = bot = q;
        *top = n;
        *(++top) = 2;
        *(++top) = n - 1;
        *(++top) = 1;
        while(top > bot){
            i = *bot;
            bot++;
            j = *bot;
            bot++;
            jocJohnny[i][j] = max(jocJohnny[i + 1][j], jocJohnny[i][j - 1]) + matrixCitire[i][j];
            if(i - 1){
                *(++top) = i - 1;
                *(++top) = j;
                }
            if(j + 1 <= m){
                *(++top) = i;
                *(++top) = j + 1;
                }
            }
        punctajJohnny = jocJohnny[1][m];
        cout<<"here4\n";
        if(punctajDiana > punctajJohnny)
            fout<<"1 "<<punctajDiana<<"\n";
        else if(punctajDiana == punctajJohnny)
            fout<<"3 "<<punctajDiana<<"\n";
        else fout<<"2 "<<punctajJohnny<<"\n";
        }
    fin.close();
    fout.close();
    }*/