#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector <int> G[100];
int dist[100];
int parent[100];
int distance[100];
bool visit[100];

void Display(queue <int> Q, int sz){
    for(int i=0;i<sz;i++){
        cout<< Q.front() << " " ;
        Q.pop();
    }
    cout<< endl;
}

int BFS(int source, int destination){
    queue <int> Q;
    memset(dist,INF,sizeof dist);
    Q.push(source);
    dist[source] = 0;
    visit[source] = true;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(size_t i=0;i<G[u].size();i++){
            int v = G[u][i];

            while(!visit[v]){
                dist[v] = dist[u] + 1;
                visit[v] = true;
                parent[v] = u;
                Q.push(v);
            }
        }
        cout<< "Queue Operation : " << endl;
        Display(Q,Q.size());
    }
    return dist[destination];
}


int main() {
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++){
        int x,y;
        cin>> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout<< endl;

    int s,d;
    cin>> s>> d;
    cout<< BFS(s,d) << endl;

    cout<< "Path : " << endl;
    while(d!=s){
        cout<< d << " ";
        d = parent[d];
    }

    return 0;
}