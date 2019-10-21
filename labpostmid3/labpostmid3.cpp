#include<bits/stdc++.h>
using namespace std;

int Mat[10000][10000]={0};
int Visi[10000][10000]={0};
int Maxval=0;
int Maxi=0;

bool isvalid(int i,int p,int m,int n)
{
	if(i>=0&&i<m && p>=0&&p<n && Visi[i][p]==0 && Mat[i][p]==1){
		return true;
	}
	return false;
}

void BFS(int i,int p,int m,int n)
{	
	Visi[i][p]=1;
	Maxi++;
	if(isvalid(i-1,p,m,n)){
		BFS(i-1,p,m,n);
	}
	if(isvalid(i+1,p,m,n)){
		BFS(i+1,p,m,n);
	}
	if(isvalid(i,p-1,m,n))
		BFS(i,p-1,m,n);
	if(isvalid(i,p+1,m,n))
		BFS(i,p+1,m,n);
}

int main()
{
	int m,n;
	cin>>m>>n;
	int k;
	cin>>k;
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		Mat[x-1][y-1]=1;
	}
	for(int i=0;i<m;i++)
	{
		for(int p=0;p<n;p++)
		{	if(Maxi>Maxval)
			Maxval=Maxi;
			Maxi=0;
			if(isvalid(i,p,m,n)){BFS(i,p,m,n);}
		}
	}
	cout<<Maxval;

}
