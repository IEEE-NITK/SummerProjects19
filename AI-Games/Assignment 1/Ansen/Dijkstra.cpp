#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ln '\n'
#define pi pair<int,int>

void dijkstra(vector <vector<pi>> graph, int source)
{
    int count=0;
	priority_queue < pi ,vector<pi>, greater<pi> > pq; 
	vector<int> dist;
	dist.resize(graph.size());
	unordered_map<int,bool> visited;
	
	for(int i=0 ;i<dist.size();i++)
		dist[i]=INT_MAX;
	
	dist[source]=0;
	pq.push({0,source});
	
	while(!pq.empty()&&count!=graph.size()-1)
	{
		pi temp=pq.top();
		pq.pop();
		int t_dist=temp.first;
		int t_source=temp.second;
		if(visited[t_source])
		    continue;
		visited[t_source]=true;
		count++;
		for(int i=0;i<graph[t_source].size();i++)
		{
			int t1_dist=graph[t_source][i].second;
			int t1_source=graph[t_source][i].first;
			if(dist[t_source]+t1_dist<dist[t1_source])
			{
		    	dist[t1_source]=min(dist[t1_source],dist[t_source]+t1_dist);
		    	pq.push({dist[t1_source],t1_source});
			}
			
		}
		
	}
	for(int i=1;i<graph.size();i++)
	{
		cout<<i<<"  ->  "<<dist[i]<<ln;
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
	vector< vector<pi> > graph;
	// assuming all v vertices are numbered 1 to v
	graph.resize(v+1);
	
	for(int i=0;i<e;i++)
	{
		int x,y,edge_weight;
		cin>>x>>y>>edge_weight; // for undirected graph
		
		// adding x to y's adjacency list and vice versa
		graph[x].pb({y,edge_weight});
		graph[y].pb({x,edge_weight});
		
	}
	
	int source;
	cout<< " enter source node"<<ln;
	cin>>source;
	cout<< "Vertex"<<"  ->  "<<"distance from source: "<<ln;
	dijkstra(graph,source);
	
	
}
