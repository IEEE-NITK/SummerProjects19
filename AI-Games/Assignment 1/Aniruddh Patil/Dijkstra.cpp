#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f
 
vii *G;   
vi Dist; 
void Dijkstra(int source, int N) {
    priority_queue<pii, vector<pii>, greater<pii> > Q; 
    Dist.assign(N,INF);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            int v = c.second;
            int w = c.first;
            if(Dist[v] > Dist[u]+w){
                Dist[v] = Dist[u]+w;
                Q.push({Dist[v],v});
            }
        }
    }
}

int main() {
    int N, M, u, v, w, source; 
    cin >> N >> M;             
    G = new vii[N+1];
    
    for(int i=0;i<M;++i){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    cin >> source;
    Dijkstra(source,N);
    
    for(int i=0;i<N;i++)
        cout<<Dist[i]<<" ";
    cout<<endl;
    
    return 0;
}