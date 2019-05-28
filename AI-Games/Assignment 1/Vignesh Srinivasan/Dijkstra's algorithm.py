#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 25 17:16:54 2019

@author: vignesh_srinivasan
"""

#Dijkstra's algorithm

def dijkstra(graph,n,source):
    dist=[0]*(n)
    queue=[]
    for i in range(1,n):
        dist[i]=float('inf')

    for i in range(n):
        queue.append(i)
        
    while(len(queue)!=0):
        v=queue[0]
        for i in queue:
            if(dist[i]<dist[v]):
                v=i
        queue.remove(v)

        for i in range(n):
            if ((dist[v]+graph[i][v]<dist[i]) & (graph[v][i]!=0)):
                dist[i]=dist[v]+graph[i][v]

    return dist

def main():
    print('Enter the number of vertices: ')
    n=int(input())
    print('Enter the number of edges: ')
    e=int(input())
    print('Enter the edges and its weight: ')
    matrix = [[0 for i in range(n)] for j in range(n)]
    for i in range(e):
        u,v,c=input().split(' ')
        u=int(u)
        v=int(v)
        c=int(c)
        matrix[u][v]=c
        matrix[v][u]=c
    print('Enter the source vertex: ')
    s=int(input())
    
    dist=dijkstra(matrix,n,s)
    print("Shortest path: ",dist)
    print("Vertex\tDistance")
    for i in range(n):
        print(i,"\t", dist[i])

if __name__=='__main__':
    main()
