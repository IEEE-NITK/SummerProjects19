# -*- coding: utf-8 -*-
"""
Created on Thu May 16 18:07:04 2019

@author: shruthan
"""
 ## ASSUMES UNDIRECTED GRAPH ##
def main():
    """
    Creates a graph and calls the BFS function.
    """
    n = int(input("Enter the number of nodes: "))
    m = int(input("Enter the number of edges: "))
    
    adjList = [[] for i in range(n)]
    
    print("Enter the edges: ")
    for i in range(m):
        x, y = input().split(" ")
        x = int(x)
        y = int(y)
        adjList[x].append(y)
        adjList[y].append(x)
        
    s = int(input("Enter the source: "))
    
    DFS(adjList, s, n)
    
def DFS(graph, s, n):
    """
    Implements DFS given the graph, number of vertices and the source vertex.
    """
    # Stack implemented using list. list.append() and list.pop() inherently have LIFO structure.
    visited = [False] * n
    stack = []
    
    stack.append(s)
    visited[s] = True
    while(stack):
        v = stack.pop()
        print(v, end= " ")
        
        for i in range(len(graph[v])):
            if (not visited[graph[v][i]]):
                stack.append( graph[v][i] )
                visited[graph[v][i]] = True