#include <bits/stdc++.h> 
using namespace std; 
  
  int main(){
  	long long int num;
  	cin>>num;
  	long long int root = sqrt(num);
  	int flag =0;
  	for(int i =2;i<root+1;i++){
  		if(num%i==0){
  			flag=1;
  			break;
  		}
  	}
  	if(flag==0)
  		cout<<"Prime";
  	else
  		cout<<"Not a Prime";
  }