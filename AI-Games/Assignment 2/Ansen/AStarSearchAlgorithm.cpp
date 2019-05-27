//  A* search
// assumes the graph as a grid and uses manhattan distance as heuristic


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl '\n'
#define rep(i,k,n) for(int i=k;i<n;i++)
#define pii pair<int,int>
#define tii pair<int,pii>
#define mp make_pair

// global variable for graph
int** graph;
int M,N;

// function to calculate manhattan distance
int m_dist(pii s1, pii s2)
{
    return abs(s1.first-s2.first)+ abs(s1.second-s2.second);
}

void A_star( pii start, pii end)
{
     vector <pii> path;
     map <pii,bool> visited;
     map <pii,int> cost_till_now;
     map<pii,pii> came_from;
     cost_till_now[start]=0;
     came_from[start]={-1,-1};
     priority_queue <tii, vector<tii>, greater<tii> > pq; 
     pq.push({0,start});
     while(!pq.empty())
     {
         pii current =pq.top().second;
         pq.pop();
         if(visited[current])
            continue;
         visited[current]=true;
         if(current==end)
            break;
         int x=current.first;
         int y=current.second;
         
         if(x<N)
         {
             pii right=mp(x+1,y);
             int f_n=cost_till_now[current]+graph[x+1][y];
             int new_cost=f_n;
             int g_n=m_dist(end,right);
             if(graph[x+1][y]!=-1&&(cost_till_now.find(right)==cost_till_now.end()||f_n<cost_till_now[right]))
             {
                 cost_till_now[right]=new_cost;
                 came_from[right]=current;
                 pq.push({f_n+g_n,right});
             }
             
         }
         if(y>1)
         {
             pii down=mp(x,y-1);
             int f_n=cost_till_now[current]+graph[x][y-1];
             int new_cost=f_n;
             int g_n=m_dist(end,down);
             
             if(graph[x][y-1]!=-1&&(cost_till_now.find(down)==cost_till_now.end()||f_n<cost_till_now[down]))
             {
                 cost_till_now[down]=new_cost;
                 came_from[down]=current;
                 pq.push({f_n+g_n,down});
             }
             
         }
         if(x>1)
         {
             pii left=mp(x-1,y);
             int f_n=cost_till_now[current]+graph[x-1][y];
             int new_cost=f_n;
             int g_n=m_dist(end,left);
             if(graph[x-1][y]!=-1&&(cost_till_now.find(left)==cost_till_now.end()||f_n<cost_till_now[left]))
             {
                 cost_till_now[left]=new_cost;
                 came_from[left]=current;
                 pq.push({f_n+g_n,left});
             }
             
         }
         if(y<M)
         {
             pii up=mp(x,y+1);
             int f_n=cost_till_now[current]+graph[x][y+1];
             int new_cost=f_n;
             int g_n=m_dist(end,up);
             if(graph[x][y+1]!=-1&&(cost_till_now.find(up)==cost_till_now.end()||f_n<cost_till_now[up]))
             {
                 cost_till_now[up]=new_cost;
                 came_from[up]=current;
                 pq.push({f_n+g_n,up});
             }
             
         }
        
         
     }
     stack <pii> temp;
     temp.push(end);
     while(temp.top()!=start)
     {
         temp.push(came_from[temp.top()]);
     }
     cout<<"required path is:"<<nl;
     while(temp.top()!=end)
     {
        cout<<"("<<temp.top().first<<","<<temp.top().second<<")"<<"-> ";
        temp.pop();
        
     }
     cout<<"("<<temp.top().first<<","<<temp.top().second<<")"<<nl;
}
int main()
{
    // considering the map as an M X N grid;
    // enter no of rows and columns of grid //
    cin>>M>>N;
    // 1 based indexing
    int ** map = new int*[N+1];
    rep(i,0,N+1)
        map[i]=new int[M+1];
   // enter cost to move to cell// 
   // enter -1 for cost, if cell is blocked //
    rep(i,1,M+1)
    {
        // for a particular row (const y) 
        rep(j,1,N+1)
        {
            //enter cost of moving to cell (x,y)  
            cin>> map[i][j];
            
        }
    }
    graph=map;
    
    pii start,end;
    // enter co-ordinates of source cell
    cin>>start.first>>start.second;
    //enter co-ordinates of destination cell
    cin>>end.first>>end.second;
    
    if(start.first<1||start.first>N||start.second<1||start.second>M)
    { 
        cout<<"invalid starting position";
        return 0;
    }
    if(map[end.first][end.second]==-1)
    {
        cout<<"no valid path";
        return 0;
    }
    if(end.first<1||end.first>N||end.second<1||end.second>M)
    {
        cout<<"invalid destination";
        return 0;
    }
    A_star(start,end);
 
}
/*
 sample input 1
 
 4 4 
3 6 2 10 
1 3 2 11 
8 5 -1 13 
1 4 5 4 
1 1
4 4    

sample output 1:

required path is:
(1,1)-> (2,1)-> (2,2)-> (3,2)-> (4,2)-> (4,3)-> (4,4)

*/


