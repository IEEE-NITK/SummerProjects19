#include<bits/stdc++.h>
using namespace std;

//start the vertex numbering from 0 in the input

int iter_dfs(vector<int>adj[],int source, int v){
	stack<int>st;
	st.push(source);
	bool visited[v]={false};
	visited[source]=1;
	int i;
	while(!st.empty()){
		int vert;
		vert=st.top();
		cout<<vert<<" ->";
		st.pop();
		for (i = 0; i < adj[vert].size(); ++i)
		{
			if(visited[adj[vert][i]]==0){
				st.push(adj[vert][i]);
				visited[adj[vert][i]]=1;
			}
		}
	}
}


int main(){
	int e,v,u,w,source;
	cout<<"enter number of edges: ";
	cin>>e;
	cout<<"enter number of vertices: ";
	cin>>v;
	cout<<"tell the vertices between which there exist an edge\n";
	
	vector<int>adj[v];

	for (int i = 0; i < e; ++i)
	{
		cin>>u>>w;
		adj[u].push_back(w);
		adj[w].push_back(u);
	}
	cout<<"enter the source node: ";
	cin>>source;
	cout<<endl<<"Adjacency list"<<endl;
	for (int i = 0; i < v; ++i)
	{
		cout<<i<<" -> ";
		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout<<adj[i][j]<<" -> ";
		}
		cout<<endl;
	}
	cout<<endl;
	iter_dfs(adj,source,v);
}