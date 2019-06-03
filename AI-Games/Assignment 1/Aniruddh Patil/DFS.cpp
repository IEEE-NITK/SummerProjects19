#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

void iterative( vector< vector<int> > graph, int source)
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
void recursive( vector<vector<int> > graph,int source, unordered_map<int,bool> &visited)
{
    if(visited[source]==false)
    {
        cout<<source<<"->";
        visited[source]=true;
        for(int i=0;i<graph[source].size();i++)
            recursive(graph,graph[source][i],visited);
    }
}


int main()
{
	int v,e;
	cout<<"Vertices"<<endl;
	cin>>v;
	cout<< "Edges "<<endl;
	cin>>e;

	vector< vector<int>> graph;
	graph.resize(v+1);

	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	int source;
	cout<<"Source"<<endl;
	cin>>source;


	cout<<"Iterative"<<endl;
	iterative(graph,source);
	cout<<endl;

	cout<<"Recursive"<<endl;

	
	unordered_map<int,bool> visited;
	recursive(graph,source,visited);

}