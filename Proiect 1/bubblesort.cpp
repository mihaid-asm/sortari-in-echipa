#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
ifstream fin("vectori.in");
const int N=1e7;
int nr_vectori,marimi[10];
double vectori[10][N];
void bubble(int n, double v[N]){
    time_t inc,sfa;
    time(&inc);
        bool sortat;
        for(int i=n-1;i>0;i--){
            sortat=true;
            for(int j=0;j<i;j++){
                if(v[j]>v[j+1]){
                    swap(v[j],v[j+1]);
                    sortat=false;
                }
            }
            time(&sfa);
            if(difftime(sfa,inc)>120) break;
            if(sortat) break;
        }
}
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
        bubble(marimi[i],vectori[i]);
        time(&sfarsit);
        cout<<i+1<<". "<<sortat(marimi[i],vectori[i])<<" "<<difftime(sfarsit,inceput)<<"s\n";
    }
    fin.close();
    return 0;
}
