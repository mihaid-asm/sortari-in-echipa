#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
ifstream fin("vectori.in");
const int N=1e7;
int nr_vectori,marimi[10];
double vectori[10][N];
double a[N],b[N],tmp[N];
void QuickSort(double v[], int st, int dr){
	if(st < dr){
		int m = (st + dr) / 2;
		double aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j){
			if(v[i] > v[j]){
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(v, st , i - 1);
		QuickSort(v, i + 1 , dr);
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
        QuickSort(vectori[i],0,marimi[i]-1);
        time(&sfarsit);
        cout<<i+1<<". "<<sortat(marimi[i],vectori[i])<<" "<<difftime(sfarsit,inceput)<<"s\n";
        /*for(int j=0;j<marimi[i];j++){
            cout<<vectori[i][j]<<" ";
        }*/
    }
    fin.close();
    return 0;
}
