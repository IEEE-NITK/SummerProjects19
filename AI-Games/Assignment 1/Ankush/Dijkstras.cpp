#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

#define SIZE 100000 + 1


int dist [SIZE];
bool vis [SIZE];

void dijkstra(vector < pair < int , int > > v [SIZE])
{
                                                // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[1] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue
    s=v.second;
    s.insert({0 , 1});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.s; int wei = p.f;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].f; int w = v[x][i].s;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
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
	vector<int>a[n+2];

	 for(int i=0;i<m;i++) 
    {
        cin>>x>>y>>w; 
        a[x].push_back(make_pair(y,w));
        a[y].push_back(make_pair(x,w));
    }
	int start;
	cout<<"Enter starting node"<<endl;
	cin>>start;
	Dijkstra(a);
	for(int i=1;i<=n;i++)
    {
        cout<<"Vertex: "<<i<<" , Distance: ";
        dis[i]!=INF? cout<<dis[i]<<"\n" : cout<<"-1\n";
    }
	cout<<endl;
	
	
	
    getch();
}