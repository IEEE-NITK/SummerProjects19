#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ln '\n'

void BFS(vector<vector<int> > graph,int source)
{
	unordered_map <int,bool> visited;
	unordered_map <int,int> level;
    queue<int> q;
    level[source]=0;
    q.push(source);
    visited[source]=true;
    while(!q.empty())
    {
    	int temp=q.front();
    	q.pop();
    	cout<<temp<<"->";
    	for(int i=0;i<graph[temp].size();i++)
    	{
    		if(!visited[graph[temp][i]])
    		{
    			q.push(graph[temp][i]);
    			visited[graph[temp][i]]=true;
    			level[graph[temp][i]]=level[temp]+1;
			}
		}
    	
    	
	}
}

int main()
{
	int v,e;
	cout<<"enter no of vertices"<<ln;
	cin>>v;
	cout<< "enter no of edges "<<ln;
	cin>>e;
	
	// adjacency list
	vector< vector<int>> graph;
	// assuming all v vertices are numbered 1 to v
	graph.resize(v+1);
	
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		
		// adding x to y's adjacency list and vice versa
		graph[x].pb(y);
		graph[y].pb(x);
		
	}
	
	int source;
	cout<< " enter source node"<<ln;
	cin>>source;
	cout <<"DFS"<<ln;
	BFS(graph,source);
	
	
	
}
