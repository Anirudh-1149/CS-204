#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int compare(string num1,string num2){
  int flag=1;
    int n1 = num1.size();
    int n2 = num2.size();
    if(n1==n2){
        for(int i = 0;i<n1;i++){
            if(num1[i]>num2[i]){
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
      sum+= to_string((num1[i]-'0'+carry)%10);
            carry =(num1[i]-'0'+carry)/10;
        }
    if(i==0&&carry!=0){
      sum+=to_string(carry);
      }
               }

  string reversed(sum);
  reverse(reversed.begin(), reversed.end());
  return reversed;
}
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
string subtract_(string num1,string num2){
  string sum;
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
  return reversed;

}

string multilplication_(string num1,string num2){
  string sum;
  sum = '0';
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
return sum;
}


int main(){
    string num1,num2,sum,reaminder,prod,check;
    check = "1";
    string addition = "2";
    string q= "3";
    int T;
    cin>>T;
    while(T--){
    cin>>num1>>num2;
    int n1 = num1.size();
    int n2 = num2.size();
    string quotient = "1";
    for(int i=n1-n2-1;i>0;i--){
      quotient.push_back('0');
    }
    if(compare(multilplication_(num2,q),num1)){
      if(compare(num1,multilplication_(num2,addition))){
        quotient = addition;
        reaminder = subtract_(num1,multilplication_(num2,addition));
      }
      else if(compare(num1,num2)){
        quotient = check;
        reaminder = subtract_(num1,num2);
      }
      if(compare(reaminder,num2)){
        quotient = add_(quotient,check);
        reaminder = subtract_(reaminder,num2);
      }

    }
    else{
    do{
      quotient = add_(quotient,addition);
      prod = multilplication_(num2,quotient);
      reaminder = subtract_(num1,prod);
    }while(compare(reaminder,multilplication_(num2,addition)));
    if(compare(reaminder,num2)){
        reaminder = subtract_(reaminder,num2);
        quotient = add_(quotient,check);
    }
    if(compare(num2,subtract_(num1,multilplication_(num2,subtract_(quotient,check))))&&reaminder!="0"){
        quotient = subtract_(quotient,check);
        reaminder = subtract_(num1,multilplication_(num2,subtract_(quotient,check)));
    }
  }
    cout<<"Quotient"<<":"<<quotient<<"\n"<<"Remainder"<<":"<<reaminder;
  }



    return 0;
  }
