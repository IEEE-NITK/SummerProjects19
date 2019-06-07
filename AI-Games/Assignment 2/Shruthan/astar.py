# -*- coding: utf-8 -*-
"""
Created on Sat May 25 23:10:17 2019

@author: shruthan
"""

import heapq

# Class to create the square grid for the maze    
class SquareGrid:
    def __init__(self, width, height):
        """
        Sets the height and width of the maze and also stores the walls in a list.
        """
        self.width = width
        self.height = height
        self.walls = []
    
    def in_bounds(self, id):
        """
        Checks if a given point in within the maze. Returns True or False
        """
        (x, y) = id
        return 0 <= x < self.width and 0 <= y < self.height
    
    def passable(self, id):
        """
        passable(vertex), Returns True if the vertex is not a wall and False otherwise
        """
        return id not in self.walls
    
    def neighbors(self, id):
        """
        Returns all neighbors(diagonal moves not considered) of a cell in the grif
        """
        (x, y) = id
        results = [(x+1, y), (x, y-1), (x-1, y), (x, y+1)]
        if (x + y) % 2 == 0: results.reverse()
        #To ensure neighbors in grid are within the maze.
        results = filter(self.in_bounds, results) 
        #To ensure neighbors are not walls.
        results = filter(self.passable, results) 
        return results

# Class to create a graph and store weights of edges
class GridWithWeights(SquareGrid):
    """
    Inherits from the SquareGrid class.
    """
    def __init__(self, width, height):
        """
        Initialises height and weights and creates a dictionary to store the weights.
        """
        # Calls __init__  of base class ie., SquareGrid with parameters height and weight.
        super().__init__(width, height) 
        self.weights = {}
    
    def cost(self, from_node, to_node):
        """
        Gets the value corresponding to the key to_node. Returns 1 if key does not exist
        """
        return self.weights.get(to_node, 1) 





def reconstruct_path(came_from, start, goal):
    """
    Returns the path from start to goal by reconstructing the order of visiting vertices.
    Takes in came_from as an argument which specifies the parent of each vertex.
    """
    current = goal
    path = []
    while current != start:
        path.append(current)
        current = came_from[current]
    path.append(start)
    path.reverse() # To give the order of travel from the begining.
    
    return path

def heuristic(a, b):
    """
    Returns the Manhattan distance between the two points given as a and b.
    """
    (x1, y1) = a
    (x2, y2) = b
    return abs(x1 - x2) + abs(y1 - y2)



def a_star_search(graph, start, goal):
    """
    Implements the A* search algorithms given the graph (which is an instance of the class GridWithWeights), start and end points.
    """
    open_list = list()
    heapq.heappush(open_list, (0, start))
    closed_list = {}
    cost_so_far = {}
    closed_list[start] = None
    cost_so_far[start] = 0
    
    
    while open_list:
        current = heapq.heappop(open_list)[1]
        
        #If goal already reached.
        if current == goal:
            path = (reconstruct_path(closed_list, start, goal))
            break
            
            
        
        for neighbor in graph.neighbors(current):
            new_cost = cost_so_far[current] + graph.cost(current, neighbor)
            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                cost_so_far[neighbor] = new_cost
                priority = new_cost + heuristic(goal, neighbor)
                heapq.heappush(open_list, (priority, neighbor))
                closed_list[neighbor] = current
    return path
   
    






def main():
    
    h = int(input("Enter the height of the maze:"))
    w = int(input("Enter the width of the maze:"))
    
    graph = GridWithWeights(w,h)
    
    w = int(input("Enter the number of walls:"))
    print("Enter the walls as a,b :")
    for i in range(w):
        a, b = input().split(",")
        a = int(a)
        b = int(b)
        graph.walls.append((a, b))
    n = int(input("Enter number of vertices: "))
    print("Enter the vertices and weights as vertex_x,vertex_y,weight : ")
    for i in range(n):
    
        x, y, w = input().split(",")
        x = int(x)
        y = int(y)
        w = int(w)
        graph.weights[(x,y)] = w
        
    print("Enter the starting vertex: ")
    x1, y1 = input().split(",")
    x1 = int(x1)
    y1 = int(y1)
    start = (x1, y1)
    
    print("Enter the goal vertex: ")
    x2, y2 = input().split(",")
    x2 = int(x2)
    y2 = int(y2)
    goal = (x2, y2)
    
    
    
    a_star_search(graph, start, goal)
    
    
    
    
    

# Sample input from one of the resources. Can be used instead of the main function
graph = GridWithWeights(10, 10)
graph.walls = [(1, 7), (1, 8), (2, 7), (2, 8), (3, 7), (3, 8)]
graph.weights = {loc: 5 for loc in [(3, 4), (3, 5), (4, 1), (4, 2),
                                       (4, 3), (4, 4), (4, 5), (4, 6), 
                                       (4, 7), (4, 8), (5, 1), (5, 2),
                                       (5, 3), (5, 4), (5, 5), (5, 6), 
                                       (5, 7), (5, 8), (6, 2), (6, 3), 
                                       (6, 4), (6, 5), (6, 6), (6, 7), 
                                       (7, 3), (7, 4), (7, 5)]}
#Example search
a_star_search(graph, (0,0), (7,4))






