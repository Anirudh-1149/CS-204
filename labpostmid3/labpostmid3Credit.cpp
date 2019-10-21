#include<bits/stdc++.h>
using namespace std;

int Mat[10000][10000]={0};
int Visi[10000][10000]={0};
int Maxval[100]={0};
int Maxi=0;
int color;

bool isvalid(int i,int p,int m,int n)
{
	if(i>=0&&i<m && p>=0&&p<n && Visi[i][p]==0){
		return true;
	}
	return false;
}

void BFS(int i,int p,int m,int n)
{	
	Visi[i][p]=1;
	Maxi++;
	if(isvalid(i-1,p,m,n)&&Mat[i-1][p]==Mat[i][p]){
		BFS(i-1,p,m,n);
	}
	if(isvalid(i+1,p,m,n)&&Mat[i+1][p]==Mat[i][p]){
		BFS(i+1,p,m,n);
	}
	if(isvalid(i,p-1,m,n)&&Mat[i][p-1]==Mat[i][p])
		BFS(i,p-1,m,n);
	if(isvalid(i,p+1,m,n)&&Mat[i][p+1]==Mat[i][p])
		BFS(i,p+1,m,n);
}

int main()
{
	int m,n,c;
	cin>>m>>n>>c;
	for(int i=0;i<m;i++)
	{
		for (int p = 0; p < n; ++p)
		{
			int co;
			cin>>co;
			Mat[i][p]=co;
		}
	}
	color=0;
	for(int i=0;i<m;i++)
	{
		for(int p=0;p<n;p++)
		{	if(Maxi>Maxval[color])
			Maxval[color]=Maxi;
			Maxi=0;
			color=Mat[i][p];
			if(isvalid(i,p,m,n)){BFS(i,p,m,n);}
		}
	}
	int max=0;
	int i=0;
	int col;
	while(c--)
	{
		if(Maxval[i]>max){
			max=Maxval[i];
			col=i;
		}
		i++;
	}
	cout<<max<<" "<<col;
}
