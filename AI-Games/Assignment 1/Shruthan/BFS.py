# -*- coding: utf-8 -*-
"""
Created on Thu May 16 16:44:04 2019

This file contains two functions,the main function and the one for BFS

@author: shruthan
"""
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
    
    BFS(adjList, s, n)
        
def BFS(graph, s, n):
    """
    Implements BFS given the graph, number of vertices and the source vertex.
    """
    #Implement queue using list. list.pop() to dequeue and list.insert(0,x) to enqueue.
    visited = [False] * n
    queue = []
    
    queue.insert(0, s)
    visited[s] = True
    while(queue):
        v = queue.pop()
        print(v, end= " ")
        
        for i in range(len(graph[v])):
            if (not visited[graph[v][i]]):
                queue.insert(0, graph[v][i] )
                visited[graph[v][i]] = True
                
    
           
if "__name__" == "__main__":
    main()