#include<bits/stdc++.h>
using namespace std;


int dfs1(vector<int> graph[], int start, int n)
{
	stack<int> s;
	s.push(start);
	bool visit[n+2];
	memset(visit, sizeof(visit),false);
	visit[start]=true;
	
	while(!s.empty())
	{
		int top = s.top();
		cout<<top<<"->";
		s.pop();
		
		for(int i=0; i<graph[top].size();++i)
		{
			if(visit[graph[top][i]]==false)
			{
				s.push(graph[top][i]);
				visit[graph[top][i]]=true;
			}
		}
	}
}


int dfs2(vector<int> graph[], int start, int n, bool visit[])
{
	if(visit[start]==false)
	{	
		cout<<start<<"->";
		visit[start]=true;
		for(int i=0;i<graph[start].size();++i)
		{	
			if(visit[graph[start][i]]==false)
				dfs2(graph, graph[start][i], n, visit);
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
	
	int u,w;
	vector<int> graph[n+2];
	for(int i=0; i<m; ++i)
	{
		cin>>u>>w;
		graph[u].push_back(w);
		graph[w].push_back(u);
	}

	int start;
	cout<<"Enter source vertex ";
	cin>>start;
	dfs1(graph, start, n);
	
	bool  visit[n+2];
	memset(visit, sizeof(visit), false);
	dfs2(graph, start, n, visit);
}