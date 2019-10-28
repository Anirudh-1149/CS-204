#include<bits/stdc++.h>
using namespace std;
int flag=0;
class graph
{
public:
	int V;
	list <int>* adj;
	int * colour;
	int * visited;
	graph(int V);	
	list<int>q;
	void addedge(int x,int y);
	void is_bipartite();
	void BFS();

};

graph::graph(int V){
	this->V=V;
	adj= new list<int>[V];
	colour = new int[V];
	visited = new int[V];
	for(int i=0;i<V;i++)
	{
		colour[i]=-1;
		visited[i]=0;
	}
}

void graph::addedge(int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void graph::is_bipartite()
{
	colour[0]=0;
	visited[0]=1;
	q.push_back(0);
	BFS();
	for(int z=0;z<V;z++)
	{
		if(!visited[z]){
		colour[z]=0;
		visited[z]=1;
		q.push_back(z);
		}
	}
}
void graph::BFS()
{
	int v = q.front();
	while(!q.empty())
	{
		q.pop_front();
		for(auto i:adj[v])
		{
			if(colour[i]==-1){
				q.push_back(i);
				colour[i]=1-colour[v];
				visited[i]=1;
			}
			else if(colour[i]==colour[v])
				flag=1;
		}
		BFS();
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	graph g(n);
	int edge=m;
	while(edge--)
	{
		int x,y;
		cin>>x>>y;
		g.addedge(x,y);
	}
	g.is_bipartite();
	if(flag)
		cout<<"NO";
	else
		cout<<"YES";
}
