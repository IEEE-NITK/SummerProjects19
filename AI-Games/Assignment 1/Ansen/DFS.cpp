#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define pb push_back


void DFS_Iterative( vector< vector<int> > graph, int source)
{
    
	unordered_map<int,bool> visited;
	stack <int> s;
	s.push(source);
	
	while(!s.empty())
	{
		int temp= s.top();
		s.pop();
		if(visited[temp]==true)
		    continue;
		    
		cout<<temp<<"->";
		visited[temp]=true;
		for(int i=0;i<graph[temp].size();i++)
		{
		    
			if(visited[graph[temp][i]]==false)
			{
				s.push(graph[temp][i]);
			}
		}
		
	}
}
void DFS_Recursive( vector<vector<int> > graph,int source, unordered_map<int,bool> &visited)
{
    if(visited[source]==false)
    {
        cout<<source<<"->";
        visited[source]=true;
        for(int i=0;i<graph[source].size();i++)
            DFS_Recursive(graph,graph[source][i],visited);
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
	
	
	cout<<" DFS ITERATIVE"<<ln;
	DFS_Iterative(graph,source);
	cout<<ln;
	
	cout<<"DFS RECURSIVE"<<ln;
	
	// hashmap to check if node is visited for recursive DFS
	unordered_map<int,bool> visited;
	DFS_Recursive(graph,source,visited);
	
}
