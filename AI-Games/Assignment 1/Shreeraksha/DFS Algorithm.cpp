#include<bits/stdc++.h>
using namespace std;

int IterativeDFS(vector<int> *graph, int n, int source, bool *visited){
     stack <int> st;
     int node,i;
     visited[source]=true;
     cout<<source;
     st.push(source);
     while(!st.empty()){
          node=st.top();
          st.pop();
          if(node!=source)
               cout<<" -> "<<node;
          for(i=0; i<graph[node].size(); ++i){
               if(visited[graph[node][i]]==false){
                    st.push(graph[node][i]);
                    visited[graph[node][i]]=true;
               }
          }
      }
      return 0;
}


int RecursiveDFS(vector<int> *graph, int n, int node, bool *visited, int source){
    if(visited[node]==false){
         visited[node]=true;
         if(node!=source)
              cout<<" -> "<<node;
         else
              cout<<node;
         for(int i=0; i<graph[node].size();i++){
               if(visited[graph[node][i]]==false){
                     RecursiveDFS(graph, n, graph[node][i], visited,source);
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
     bool visited[vertices+1];
     memset(visited, false, sizeof(visited));
     cout<<"\nDFS using Iteration\n";
     IterativeDFS(graph,vertices,source,visited);
     memset(visited, false, sizeof(visited));
     cout<<"\n\nDFS using Recursion\n";
     RecursiveDFS(graph, vertices, source, visited, source);
     return 0;
}
