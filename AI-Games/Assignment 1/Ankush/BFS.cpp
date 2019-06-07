#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


   int level[10]; 
    bool vis[10]; 
   void bfs(int s,vector <int> v[] ) 
	{
        queue <int> q;
        q.push(s);
        level[ s ] = 0 ;  
        vis[ s ] = true;
        while(!q.empty())
        {
            int r = q.front();
            cout<<r<<"->";
			q.pop();
            for(int i = 0;i < v[ r ].size() ; i++)
            {
                if(vis[ v[ r ][ i ] ] == false)
                {
            
                    level[ v[ r ][ i ] ] = level[ r ]+1;                 
                     q.push(v[ r ][ i ]);
                     vis[ v[ r ][ i ] ] = true;
      
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
	bfs(start,graph);
	cout<<endl;
	
	
	
    getch();
}