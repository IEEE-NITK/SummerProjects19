//Heuristic values are given as input calculated using Manhattan distance
/*Sample input->
10   	//edges
10		//vertices
0 1 1
0 3 2
1 2 3
1 4 7
3 4 3		// vertices across edges along weights
4 6 7
6 7 4
7 9 2
7 8 3
8 5 5
5 4 3 4 3 3 2 1 2 0   //heuristic values
0 9 // start, stop points
*/
/*Corressponding maze->
	(1,1),(1,2),(1,3),(None)
	(2,1),(2,2),(None),(None)
	(None),(3,2),(3,3),(None)
	(None),(None),(4,3),(None)

	(1,1)->source
	(4,3)->goal
*/
/*
finally the path from the output->
0->3->4->6->7->9
OR
1,1->2,1->2,2->3,2->3,3->4,3
*/
#include<bits/stdc++.h>
using namespace std;

void astar(int v,vector<int>heuristic,vector<pair<int,int>>adj[],int source,int goal){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.emplace(make_pair(0,source));
	vector<int>cost_so_far(v,100000);  //initial high value
	vector<int>came_from(v,100000);	   //initial high value
	bool visited[v]; memset(visited,false,sizeof(visited));
	cost_so_far[source]=0;
	int current,new_cost,priority,neighbor;
	while(!pq.empty()){
		current=pq.top().second;
		pq.pop();
		visited[current]=true;
		if(current==goal)
			break;
		for(int i=0;i<adj[current].size();i++){
			neighbor=adj[current][i].first;
			//adj[current][i].first will give the neighbors of current vertex
			new_cost=cost_so_far[current] + adj[current][i].second;
			if((new_cost < cost_so_far[neighbor]) || visited[neighbor]==false){
				cost_so_far[neighbor]=new_cost;
				priority=new_cost+heuristic[neighbor];
				pq.emplace(make_pair(priority,neighbor));
				came_from[neighbor]=current;
			}
		}

	}
	for (int i = 0; i < came_from.size(); ++i)
	{
		cout<<came_from[i]<<" ";
	}
}

int main(){
	int e,v,u,w,source,weight,goal;
	cout<<"enter number of edges: ";
	cin>>e;
	cout<<"enter number of vertices: ";
	cin>>v;
	cout<<"tell the vertices between which there exist an edge and corressponding weights\n";
	
	vector<pair<int,int>>adj[v];

	for (int i = 0; i < e; ++i)
	{
		cin>>u>>w>>weight;
		adj[u].push_back(make_pair(w,weight));
		//adj[u].push_back(weight);
		adj[w].push_back(make_pair(u,weight));
		//adj[w].push_back(weight);
	}
	vector<int>heuristic;
	cout<<"enter heuristic values:\n";
	for (int i = 0; i < v; ++i)
	{
		int x;cin>>x;
		heuristic.push_back(x);
	}
	cout<<"enter the source node and goal node: ";
	cin>>source>>goal;
	cout<<endl<<"Adjacency list"<<endl;
	for (int i = 0; i < v; ++i)
	{
		cout<<i<<" -> ";
		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout<<adj[i][j].first<<","<<adj[i][j].second<<"->";
		}
		cout<<endl;
	}
	cout<<endl;

	astar(v,heuristic,adj,source,goal);	
}