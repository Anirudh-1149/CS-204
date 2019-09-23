#include<bits/stdc++.h>
using namespace std; 
  
int partition(int arr[], int l, int r, int k); 
int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);
    return arr[n/2]; 
} 
int Blum(int arr[], int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
        int i, median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
        int medOfMed = (i == 1)? median[i-1]: 
                                 Blum(median, 0, i-1, i/2); 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return Blum(arr, l, pos-1, k); 
        return Blum(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
} 
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int arr[], int l, int r, int x) 
{ 

    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
    i = l; 
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
		int arr[p];
		int x,y;
		for(int i=0;i<p;i++){
			cin>>x>>y;
			arr[i] = pow(x,2)+pow(y,2);
		}
		int d;
		if(p%2==0)
			d = Blum(arr, 0, n-1, p/2);
		else
			d = Blum(arr, 0, n-1, p/2+1);
		cout<<sqrt(d)<<"\n";	
	}
}
