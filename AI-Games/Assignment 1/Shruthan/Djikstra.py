# -*- coding: utf-8 -*-
"""
Created on Fri May 17 19:49:59 2019

@author: shruthan
"""
 ## ASSUMES UNDIRECTED GRAPH ##

def main():
    """
    Creates a graph as a Adjacency matrix. Calls the djikstra function and prints the shortest distance.
    """
    # Standard graph theory notation for number of nodes and edges. 
    m = int(input("Enter the number of edges: "))
    n = int(input("Enter the number of nodes: "))
    graph = [[0 for i in range(n)] for j in range(n)]
    
    print("Enter the edges as vertex1 vertex2 weight: ") #Sample 0 1 3
    for i in range(m):
        x, y, w = input().split(" ")
        x = int(x)
        y = int(y)
        w = int(w)
        graph[x][y] = w
        graph[y][x] = w

    source = int(input("Enter the source: "))
    
    dist = djikstra(graph, n, source)
    dest = int(input("Enter the destination vertex: "))
    print("Shortest distance =", dist[dest])
        
def djikstra(graph, n, s):
    """
    Implements Djikstra's Algorithm
    """
    dist = [0 for i in range(n)] 
    q = []
    for i in range(n):
        if (i != s):
            dist[i] = float('inf') #Set initial distancd of all vertices except source as infinity.
        q.append(i)
    
    #For behaviour of minimum priority queue 
    while q:
        v = q[0]
        for t in q:
            if (dist[t] < dist[v]):
                v = t
        #Remove vertex in queue(q) with least distance from q. 
        q.remove(v)
        
        for i in range(n):
            #To check for neighbours
            if (graph[v][i] > 0):
                new = dist[v] + graph[v][i]
                if new < dist[i]:
                    dist[i] = new
        
    return dist
    
if __name__ == "__main":
    main()
    
    
    

        
    
    
    
    
