#include<iostream>
#include<fstream>
#include<ctime>
#include<algorithm>
using namespace std;
ifstream fin("vectori.in");
const int N=1e7;
int nr_vectori,marimi[10];
double vectori[10][N];
bool sortat(int n, double v[N]){
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]) return false;
    }
    return true;
}
int main(){
    time_t inceput, sfarsit;
    fin>>nr_vectori;
    for(int i=0;i<nr_vectori;i++){
        fin>>marimi[i];
        for(int j=0;j<marimi[i];j++){
            fin>>vectori[i][j];
        }
    }
    for(int i=0;i<nr_vectori;i++){
        time(&inceput);
        sort(vectori[i],vectori[i]+marimi[i]);
        time(&sfarsit);
        cout<<i+1<<". "<<sortat(marimi[i],vectori[i])<<" "<<difftime(sfarsit,inceput)<<"s\n";
    }
    fin.close();
    return 0;
}
