#include<bits/stdc++.h>
using namespace std;

int BFS(vector<int> *graph, int n, int source){
    bool visited[n+1];
    int level[n+1];
    level[source]=0;
    memset(visited, false, sizeof(visited));
    visited[source]=true;
    cout<<source<<" "<<level[source]<<endl;
    queue <int> Q;
    int node,i;
    Q.push(source);
    while(!Q.empty()){
         node=Q.front();
         Q.pop();
         if(node!=source)
              cout<<node<<" "<<level[node]<<endl;
              for(i=0; i<graph[node].size(); ++i){
                   if(visited[graph[node][i]]==false){
                         Q.push(graph[node][i]);
                         visited[graph[node][i]]=true;
                         level[graph[node][i]]=level[node]+1;
                   }
              }
     }
     return 0;
}


int main(){
     int source,vertices,edges,x,y;
     cout<<"Enter the number of vertices and edges\n";
     cin>>vertices>>edges;
     vector<int> graph[vertices+1];
     cout<<"Enter the edges in terms of their end vertices\n";
     while(edges--){
          cin>>x>>y;
          graph[x].push_back(y);
          graph[y].push_back(x);
     }
     cout<<"Enter the source node\n";
     cin>>source;
     cout<<"\nBFS\nOrder of node visit with their level-\n";
     BFS(graph,vertices,source);
     return 0;
}
