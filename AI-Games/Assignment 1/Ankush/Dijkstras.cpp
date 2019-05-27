#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

#define SIZE 100000 + 1


int dist [SIZE];
bool vis [SIZE];

int Dijkstra(vector<pair<int,int> > *graph, int n, int start, int end)
{
                                                
   int dist[n+1], node=0, distance=0, i;
     pair<int,int> VERTEX;
    
     memset(dist, SIZE , sizeof(dist));
     memset(vis, false , sizeof(vis));
     dist[start]=0;
     multiset <pair<int, int> > SET;
     SET.insert(make_pair(0,start));
     while(!SET.empty()){
          VERTEX=*SET.begin();
          distance=VERTEX.first;
          node=VERTEX.second;
          SET.erase(SET.begin());
          if(vis[node]==true)
              continue;
          else{
              vis[node]=true;
              for(i=0;i<graph[node].size();i++){
                    if(distance + graph[node][i].first < dist[graph[node][i].second])
                         dist[graph[node][i].second]= distance + graph[node][i].first ;
                    SET.insert(make_pair(dist[graph[node][i].second],graph[node][i].second));
              }
          }
     }
     return dist[end];
}


int main()
{
	int n,m,w;
	cout<<"Enter number of vertices"<<endl;
	cin>>n;
	cout<<"Enter number of edges"<<endl;
	cin>>m;

	int x,y;
	vector<pair<int,int> > a[n+2];

	 for(int i=0;i<m;i++) 
    {
        cin>>x>>y>>w; 
        a[x].push_back(make_pair(w,y));
        a[y].push_back(make_pair(w,x));
    }
	int start,end;
	cout<<"Enter starting and ending node"<<endl;
	cin>>start>>end;
	Dijkstra(a, n, start, end);
	
	
	
    getch();
}