#include <bits/stdc++.h>
#include <cstring>
using namespace std;



int main(){
	string num1,num2;
	int T;
    cin>>T;
    while(T--){
    string sum;
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
	for(int i=n1-1;i>=0;i--){
		if(i>=n1-n2){
			sum += to_string((num1[i]+num2[i+n2-n1]+carry-'0'-'0')%10);
			carry = (num1[i]+num2[i+n2-n1]+0-'0'-'0')/10;
			}
			else{
			sum+= to_string((num1[i]-'0'+carry)%10);
            carry =(num1[i]-'0'+carry)/10;
		    }
		if (i==0&&carry!=0) {
			sum+=to_string(carry);
		}
			         }

	string reversed(sum);
	reverse(reversed.begin(), reversed.end());
	cout<<reversed<<"\n";
	}
	return 0;
}
