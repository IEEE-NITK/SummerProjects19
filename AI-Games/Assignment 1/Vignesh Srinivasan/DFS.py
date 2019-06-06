#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 25 11:59:11 2019

@author: vignesh_srinivasan
"""
#DFS Algorithm

def main():
    print('Enter the number of vertices: ')
    n=int(input())
    print('Enter the number of edges: ')
    e=int(input())
    print('Enter the edges: ')
    adjlist=[[] for i in range(n+2)]
    for i in range(e):
        u,v=input().split(' ')
        u=int(u)
        v=int(v)
        adjlist[u].append(v)
        adjlist[v].append(v)
    print('Enter the source vertex: ')
    s=int(input())
    
    stack=[]
    visited=[False]*(n+2)
    
    stack.append(s)
    visited[s]=True
    
    while(len(stack)!=0):
        s=stack.pop()
        print(s, end=' ')
        
        for i in adjlist[s]:
            if (visited[i]==False):
                stack.append(i)
                visited[i]=True
         
if __name__=='__main__':
    main()
        