#include<bits/stdc++.h>
using namespace std;

#define SIZE 10000 + 1

int distance[SIZE];
bool visit[SIZE];



void dijkstra(vector <pair<int,int>> graph[SIZE], start)
{
	memset(visit, false, sizeof(visit));
	multiset <pair<int,int>> s;

	for(int i=0 ;i<distance.size();i++)
		distance[i]=INT_MAX;
	distance[start]=0;
	
	s.insert({0,start});
	while(!s.empty())
	{
		pair<int,int> p = *s.begin();
		s.erase(s.begin());
		int x = p.s;
		int weight = p.f;
		if(vis[x]==false)
		{
			vis[x]=true;
			for(int i=0; i<v[x].size(); ++i)
			{
				int e= v[x][i].f;
				int w= v[x][i].s;
				if(dist[x] + w < dist[e])
				{
					dist[e]= dist[x] + w;
					s.insert({dist[e], e});
				}
			}
		}
	}
	
}

	

int main()
{
	int n, m;
	cout<<"Enter no. of vertices ";
	cin>>n;
	cout<<"/nEnter no. of edges ";
	cin>>m;
	
	int x,u,w;
	vector <pair<int,int>> graph[SIZE];
	for(int i=0; i<m; ++i)
	{
		cin>>u>>w>>x;
		graph[u].push_back(w,x);
		graph[w].push_back(u,x);
	}

	int start;
	cout<<"Enter starting node ";
	cin>>start;
	dijkstra(graph,start);
	

}