#include<bits/stdc++.h>
using namespace std; 

int partition(double arr[], int l, int p); 
/*double isort(double arr[],int l,int p){
    int i;
    for(i=l-1;i<p+1 -(p+1)%5;i+=5){
        sort(arr+i,arr+i+4);
    }
    i-=5
    sort(arr+i,arr+i+(p+1)%5-1)
    int y;
    if(p%2==0)
        y=p/5;
    else
        y= p/5+1;
    double arr2[y];
    for(int s=0;s<p;s+=5){
        arr2[p] = arr[2+p]
    }
}*/


double Blum(double arr[], int l, int p, int k) 
{ 
    int pos = partition(arr, l, p); 
    if (pos-l == k-1) 
        return arr[pos]; 
    if (pos-l > k-1)  
        return Blum(arr, l, pos-1, k); 
    return Blum(arr, pos+1, p, k-pos+l-1); 
} 
  
void swap(double *x, double *y) 
{ 
    double temp = *x; 
    *x = *y; 
    *y = temp; 
} 
int partition(double arr[], int l, int r) 
{ 
    double x = arr[r];
    int i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int main()
{
	int k;
	cin>>k;
	while(k--){
		int p;
		cin>>p;
		double arr[p];
		double x,y;
		for(int i=0;i<p;i++){
			cin>>x>>y;
			arr[i] = sqrt(pow(x,2)+pow(y,2));
		}
		double d;
		if(p%2==0)
			d = Blum(arr,0,p-1,p/2);
		else
			d = Blum(arr,0,p-1,p/2+1);
		cout<<d<<"\n";	
	}
}
