#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
ifstream fin("vectori.in");
const int N=1e7;
int nr_vectori,marimi[10];
double vectori[10][N];
double a[N],b[N],tmp[N];
void shell_sort(int n, double v[]) {
    for(int interval=n/2;interval>0;interval/=2){
        for(int i=interval;i<n;i+=1){
            double temp=v[i];
            int j;
            for(j=i;j>=interval&&v[j-interval]>temp;j-=interval){
                v[j]=v[j-interval];
            }
            v[j] = temp;
        }
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
        shell_sort(marimi[i],vectori[i]);
        time(&sfarsit);
        cout<<i+1<<". "<<sortat(marimi[i],vectori[i])<<" "<<difftime(sfarsit,inceput)<<"s\n";
        /*for(int j=0;j<marimi[i];j++){
            cout<<vectori[i][j]<<" ";
        }*/
    }
    fin.close();
    return 0;
}
