#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void IterativeDFS(vector<int> graph[],int start, int n)
{
	stack<int> p;
	p.push(start);
	bool visited[n+2];

	//Initialising visited array with False
	memset(visited,sizeof(visited),false);

	visited[start]=true;

	while(!p.empty())
	{
		int top = p.top();
		cout<<top<<" ->";
		p.pop();
		for(int i=0;i < graph[top].size();++i)
		{
			if(visited[graph[top][i]]==false)
			{
				p.push(graph[top][i]);
				visited[graph[top][i]]=true;
			}
		}
	}
}



int main()
{
	int n,m;
	cout<<"Enter number of vertices"<<endl;
	cin>>n;
	cout<<"Enter number of edges"<<endl;
	cin>>m;

	int x,y;
	// Declaring Adjacency list to store the vector.
	vector<int>graph[n+2];

	for(int i=0;i<m;++i)
	{
		cout<<"Enter";
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int start;
	cout<<"Enter starting node"<<endl;
	cin>>start;
	IterativeDFS(graph,start,n);
	cout<<endl;
	
	
	
    getch();
}