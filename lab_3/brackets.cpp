#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	string input;
	cin>>T;
	int flag;
	while(T--){
		flag =0;
		stack <char> s;
		cin>>input;
		for(int i=0;i<input.length();i++){
			if(input[i] == '('||input[i] == '{'||input[i] == '['||input[i] == '<' ){
				s.push(input[i]);
			}
			else if(input[i] == '|'&&(s.empty() == 1 || s.top() != '|')){
					s.push(input[i]);

			}
			else if(s.empty()){
				cout<<"No"<<"\n";
				flag = 1;
				break;
			}
			else {
				if(input[i] ==')'){
					if(s.top() == '(')
						s.pop();
					else{
						cout<<"No"<<"\n";
						flag = 1;
						break;
					}
				}
				else if(input[i] == '}'){
					if(s.top() == '{')
						s.pop();
					else{
						cout<<"No"<<"\n";
						flag = 1;
						break;
					}
				}
				else if(input[i] == ']' ){
					if(s.top() == '[')
						s.pop();
					else{
						cout<<"No"<<"\n";
						flag = 1;
						break;
					}
				}
				else if(input[i] == '>'){
					if(s.top() == '<')
						s.pop();
					else{
						cout<<"No"<<"\n";
						flag = 1;
						break;
					}
				}
				else if(input[i] == '|'){
					if(s.top() == '|')
						s.pop();
				}
				
			}
		}
		if(flag == 0 && s.empty() == 1)
			cout<<"Yes"<<"\n";
		else if(flag == 0 && s.empty() == 0)
			cout<<"No"<<"\n";

	}
}
