#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
ifstream fin("vectori.in");
const int N=1e7;
int nr_vectori,marimi[10];
double vectori[10][N];
double a[N],b[N],tmp[N];
void merge_sort(double v[N],int st,int dr){
	if(st<dr){
		int m=(st+dr)/2;
		merge_sort(v,st,m);
		merge_sort(v,m+1,dr);
		int i=st,j=m+1,k=0;
		while(i<=m&&j<=dr)
			if(v[i]<v[j])
				tmp[++k]=v[i++];
			else
				tmp[++k]=v[j++];
		while(i<=m)
			tmp[++k]=v[i++];
		while(j<=dr)
			tmp[++k]=v[j++];
		for(i=st,j=1;i<=dr;i++,j++)
			v[i]=tmp[j];
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
        merge_sort(vectori[i],0,marimi[i]-1);
        time(&sfarsit);
        cout<<i+1<<". "<<sortat(marimi[i],vectori[i])<<" "<<difftime(sfarsit,inceput)<<"s\n";
        /*for(int j=0;j<marimi[i];j++){
            cout<<vectori[i][j]<<" ";
        }*/
    }
    fin.close();
    return 0;
}
