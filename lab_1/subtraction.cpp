#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int compare(string num1,string num2){
  int flag=0;
    int n1 = num1.size();
    int n2 = num2.size();
    if(n1==n2){
        for(int i = 0;i<n1;i++){
            if(num1[i]>=num2[i]){
                flag = 1;
                break;
            }
            if(num1[i]<num2[i]){
            flag = 0;
            break;}
        }
        return flag;
        }
    else{
        return (n1>n2);
    }
}

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
	for(int i=n1-1;i>=0;i--){
		if(i>=n1-n2){
            if(num1[i]-num2[i+n2-n1]+carry<0){
			    sum += to_string(10+(num1[i]-num2[i+n2-n1]+carry));
			    carry = -1;
            }
            else{
                        sum += to_string((num1[i]-num2[i+n2-n1]+carry));
                        carry =0;

            }
		}
		else{
			if (num1[i]-'0'+carry< 0) {
				sum += to_string(10+(num1[i]-'0'+carry));
                carry = -1;
			}
			else{
                    sum+=to_string(num1[i]-'0'+carry);
		    carry = 0;
			}
		}
			         }
        for(int i = sum.size()-1;i>=0;i--){
            if(sum[i] == '0'&&sum.size()!=1)
            sum.pop_back();
            else
            break;
        }

	string reversed(sum);
	reverse(reversed.begin(), reversed.end());
	cout<<reversed;
	}
    return 0;

}

