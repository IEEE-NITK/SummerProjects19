#include<bits/stdc++.h>
using namespace std;




int bfs(vector<int> graph[],int level[], int start, int n)
{
	queue<int> q;
	q.push(start);
	bool visit[n+2];
	memset(visit, sizeof(visit), false);
	level[start]=0;
	visit[start] = true;
							
	while(!q.empty())
	{
		int vertex = q.front();
		q.pop();
	
		for(int i=0; i<graph[vertex].size(); ++i)
		{
			if(visit[graph[vertex][i]]==false)
			{
				q.push(graph[vertex][i]);
				level[graph[vertex][i]]=level[vertex]+1;
				visit[graph[vertex][i]]=true;
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
	int level[20];
	bfs(graph,level, start, n);
	

}