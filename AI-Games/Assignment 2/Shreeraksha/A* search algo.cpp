//A*search algorithm
//Assuming there exists atleast one path connecting the source and destinaiton
//Manhattan distance is taken for heutritics.

#include<bits/stdc++.h>
#include <functional>
#include <queue>
#define MAX 50
#define mp(a,b) make_pair(a,b)
using namespace std;

struct nodes{
    int dist;
    bool value=false;
    int cost;
    long g,h,f=0;
}S[MAX*MAX],*source,*dest,*NODE,*PARENT;

int main(){
    int n,i,j,x,y,a,f,h,g,DIS;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > open;
    set<int> close;
    queue<int> succ;
    cout<<"Enter the size of the square maze:\n";
    cin>>n;
    cout<<"Enter the matrix using 0 and 1\n";
    cout<<"(where '0' reprsent obstacle and '1' represent free space)\n\n";
    cout<<"Following is a valid entry\n";
    cout<<"     1 0 1 0\n";
    cout<<"     1 1 0 1\n";
    cout<<"     0 0 1 0\n";
    cout<<"     1 1 1 1\n\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a;
            if(a){
                S[i*n + j].value=true;
                S[i*n + j].dist=i*n + j;
            }
        }
    }

    cout<<"Enter the cost of the following nodes (given index):\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(S[i*n + j].value){
                cout<<"("<<i+1<<","<<j+1<<"): ";
                cin>>S[i*n + j].cost;
            }
        }
    }

    cout<<"Enter the coordinate of source (1 - based indexing)\n";
    cin>>i>>j;
    i--;
    j--;
    source=&S[i*n + j];
    cout<<"Enter the coordinate of destination (1 - based indexing)\n";
    cin>>x>>y;
    x--;
    y--;
    dest=&S[x*n + y];
    source->g=source->cost;
    source->f=0;
    source->h=abs(i-x) + abs(j-y);
    open.push(mp(source->f,source->dist));
    while(!open.empty()){
        auto val= open.top();
        open.pop();
        PARENT=&S[val.second];
        i=(PARENT->dist)/n;
        j=(PARENT->dist)%n;
        if(j!=n-1 && S[i*n + j+1].value){
              succ.push(i*n + j+1);
        }
        if(j!=0 && S[i*n + j-1].value){
              succ.push(i*n + j - 1);
        }
        if(i!=n-1 && S[i*n + j + n].value){
              succ.push(i*n + j + n);
        }
        if(i!=0 && S[i*n + j - n].value){
              succ.push(i*n + j - n);
        }
        while(!succ.empty()){
              DIS=succ.front();
              succ.pop();
              NODE=&S[DIS];
              g = PARENT->g + NODE->cost;
              i=(NODE->dist)/n;
              j=(NODE->dist)%n;
              h = abs(i - x) + abs(j - y);
              if(NODE->f==0){
                  NODE->g=g;
                  NODE->h=h;
                  NODE->f=g+h;
                  open.push(mp(NODE->f,NODE->dist));
              }
              else{
                  if(S[DIS].f > f){
                      NODE->g=g;
                      NODE->h=h;
                      NODE->f=g+h;
                      open.push(mp(NODE->f,NODE->dist));
                      if(close.find(NODE->dist)!=close.end()){
                          close.erase(NODE->dist);
                      }
                  }
              }
          }
          close.insert(i*n + j - n);
    }
    cout<<"Shortest path from start to goal is "<<dest->f<<endl;
    return 0;
}
