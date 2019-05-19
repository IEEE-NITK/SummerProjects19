#include<bits/stdc++.h>
#define INF 1000007
using namespace std;

int Dijkstra(vector<pair<int,int>> *graph, int n, int start, int finish){
     int dist[n+1], node=0, distance=0, i;
     pair<int,int> VERTEX;
     bool visited[n+1];
     memset(dist, INF , sizeof(dist));
     memset(visited, false , sizeof(visited));
     dist[start]=0;
     multiset <pair<int, int>> SET;
     SET.insert(make_pair(0,start));
     while(!SET.empty()){
          VERTEX=*SET.begin();
          distance=VERTEX.first;
          node=VERTEX.second;
          SET.erase(SET.begin());
          if(visited[node]==true)
              continue;
          else{
              visited[node]=true;
              for(i=0;i<graph[node].size();i++){
                    if(distance + graph[node][i].first < dist[graph[node][i].second])
                         dist[graph[node][i].second]= distance + graph[node][i].first ;
                    SET.insert(make_pair(dist[graph[node][i].second],graph[node][i].second));
              }
          }
     }
     return dist[finish];
}

int main(){
     int start,finish,vertices,edges,x,y,wt;
     cout<<"Enter the number of vertices and edges\n";
     cin>>vertices>>edges;
     vector<pair<int,int>> graph[vertices+2];
     cout<<"Enter the end points of directed edges (starting and ending point) and weight\n";
     while(edges--){
          cin>>x>>y>>wt;
          graph[x].push_back(make_pair(wt,y));
     }
     cout<<"Enter the starting and finishing node\n";
     cin>>start>>finish;
     cout<<"\nDijkstra's algorithm.....\n";
     cout<<"Smallest weight = "<<Dijkstra(graph, vertices, start, finish)<<endl;
     return 0;
}
