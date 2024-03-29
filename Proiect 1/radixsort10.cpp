#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
ifstream fin("vectoriradix.in");
const int N=1e7;
int nr_vectori,marimi[10];
int vectori[10][N];
int output[N+1];
int getMax(int n, int v[]){
    int maxim=v[0];
    for(int i=1;i<n;i++)
    if(v[i]>maxim) maxim=v[i];
    return maxim;
}
void countingSort(int v[],int s,int place){
    int counting[10]={0};
    for(int i=0;i<s;i++) counting[(v[i]/place)%10]++;
    for(int i=1;i<10;i++) counting[i]+=counting[i-1];
    for(int i=s-1;i>=0;i--){
        output[counting[(v[i]/place)%10]-1]=v[i];
        counting[(v[i]/place)%10]--;
    }
    for(int i=0;i<s;i++) v[i]=output[i];
}
void radix_sort(int n, int v[]){
  int maxim=getMax(n,v);
  for(int place=1;maxim/place>0;place*=10)
    countingSort(v,n,place);
}
bool sortat(int n, int v[N]){
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
        radix_sort(marimi[i],vectori[i]);
        time(&sfarsit);
        cout<<i+1<<". "<<sortat(marimi[i],vectori[i])<<" "<<difftime(sfarsit,inceput)<<"s\n";
        /*for(int j=0;j<marimi[i];j++){
            cout<<vectori[i][j]<<" ";
        }*/
    }
    fin.close();
    return 0;
}
