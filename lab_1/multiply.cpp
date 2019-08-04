#include <bits/stdc++.h>
#include <cstring>
using namespace std;
string multiply_(string s,char num,int index){
    string mul;
    int n1 = s.size();
    int carry = 0;
    for(int i=n1-1;i>=0;i--){
        mul+=to_string(((s[i]-'0'+0)*(num-'0'+0)+carry)%10);
        carry = ((s[i]-'0'+0)*(num-'0'+0)+carry)/10;
        if (i==0&&carry!=0){
          mul+=to_string(carry);
          }
    }
  string reversed(mul);
	reverse(reversed.begin(), reversed.end());
	for(int i=0;i<index;i++){
        reversed+=to_string(0);
    }
    return reversed;
}

string add_(string num1,string num2){
  string sum;
	int n1 = num1.size();
	int n2 = num2.size();
	int carry = 0;
	if(n2>n1){
		string temp = num1;
		num1 = num2;
		num2 = temp;
		int t;
		t = n1;
		n1 = n2;
		n2 = t;
	}
	for(int i=n1-1;i>=0;i--){
		if(i>=n1-n2){
			sum += to_string((num1[i]+num2[i+n2-n1]+carry-'0'-'0')%10);
			carry = (num1[i]+num2[i+n2-n1]+0-'0'-'0')/10;
			}
		else{
			sum+= to_string(num1[i]-'0');
		    }
    if (i==0&&carry!=0){
      sum+=to_string(carry);
      }
			         }

	string reversed(sum);
	reverse(reversed.begin(), reversed.end());
	return reversed;
}

int main(){
    string num1,num2,sum;
    int T;
    cin>>T;
    while(T--){
    sum = '0';
    cin>>num1>>num2;
    int n1 = num1.size();
	  int n2 = num2.size();
	  int carry = 0;
	  if(n2>n1){
		    string temp = num1;
		    num1 = num2;
		    num2 = temp;
		    int t;
		    t = n1;
		    n1 = n2;
		    n2 = t;
	}
  string arr[n2];
  for(int i =n2-1;i>=0;i--){
    arr[i] = multiply_(num1,num2[i],n2-i-1);
  }
  for(int i =n2-1;i>=0;i--){
    sum = add_(sum,arr[i]);
  }
  cout<<sum<<"\n";
}

    return 0;
}
