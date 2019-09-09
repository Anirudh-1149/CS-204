#include <bits/stdc++.h> 
using namespace std; 
int comp(string X,string Y)
{
	string XY=X.append(Y);
	string YX=Y.append(X);
	return XY.compare(YX)>0 ? 1:0;
}
int main()
{
	int T;
	vector<string> v;
	cin>>T;
	for(int i=0;i<T;i++)
 		{
  			int p;
  			cin>>p;
  			for(int q=0;q<p;q++)
			{
				string s;
				cin>>s;
				v.push_back(s);
			}
			sort(v.begin(),v.end(),comp);
			for(int j=0;j<v.size();j++)
			{
				cout<<v[j];
			}
			v.clear();
}
}
