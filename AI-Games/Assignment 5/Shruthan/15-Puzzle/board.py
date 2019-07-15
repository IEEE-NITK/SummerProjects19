from copy import deepcopy
from os import system
from random import randint, seed
from queue import Queue

MAXR = 4
MAXC = 4
SHUFFLE_NUMBER = 20

class board:

    def __init__(self):
        self.goal = [[' 1', ' 2', ' 3', ' 4'],
                     [' 5', ' 6', ' 7', ' 8'],
                     [' 9', '10', '11', '12'],
                     ['13', '14', '15', '__']]
        self.board = deepcopy(self.goal)
        self.emptyLoc = [MAXR-1, MAXC-1]

        self.moves = { 0 : self.moveUp, 1 : self.moveRight, 2 : self.moveDown, 3 : self.moveLeft}


    def __repr__(self):
        for i in range(MAXR):
            for j in range(MAXC):
                print(self.board[i][j], end = " ")
            print()

        return ""


    def move(self, board, emptyLoc, x, y):

        if emptyLoc[0] + x < 0 or emptyLoc[0] + x > 3 or emptyLoc[1] + y < 0 or emptyLoc[1] + y > 3:
            return board, emptyLoc

        board[emptyLoc[0]][emptyLoc[1]], board[emptyLoc[0] + x][emptyLoc[1] + y] = board[emptyLoc[0] + x][emptyLoc[1] + y], board[emptyLoc[0]][emptyLoc[1]]
        emptyLoc[0] += x
        emptyLoc[1] += y

        return board, emptyLoc
    
    def shuffle(self):
        seed()
        for i in range(SHUFFLE_NUMBER):
            move = randint(0, 3)
            self.moves[move](self.board, self.emptyLoc)

        # To move empty space to right bottom corner.
        
        for i in range(MAXR):
            self.moves[2](self.board, self.emptyLoc)

        for i in range(MAXC):
            self.moves[1](self.board, self.emptyLoc)

    
    def moveUp(self, board, emptyLoc):
        return self.move(board, emptyLoc, -1 , 0)

    def moveDown(self, board, emptyLoc):
        return self.move(board, emptyLoc, 1 , 0)

    def moveLeft(self, board, emptyLoc):
        return self.move(board, emptyLoc, 0 , -1)

    def moveRight(self, board, emptyLoc):
        return self.move(board, emptyLoc, 0 , 1)

    def solve(self):


        def successors(board, emptyloc):
            # Four successors: up, down, left, right.
            bList = [deepcopy(board), deepcopy(board), deepcopy(board), deepcopy(board)]
            emptyLocList = [list(emptyloc), list(emptyloc), list(emptyloc), list(emptyloc) ]
            bList[0], emptyLocList[0] = self.moveUp(bList[0], emptyLocList[0])
            bList[1], emptyLocList[1] = self.moveRight(bList[1], emptyLocList[1])
            bList[2], emptyLocList[2] = self.moveDown(bList[2], emptyLocList[2])
            bList[3], emptyLocList[3] = self.moveLeft(bList[3], emptyLocList[3])

            return [[bList[0], emptyLocList[0], 0], [bList[1], emptyLocList[1], 1], [bList[2], emptyLocList[2], 2], [bList[3], emptyLocList[3], 3]]


        searched = set()
        queue = Queue()
        root = self.board

        queue.put({ "board" : root, "emptyLoc" : self.emptyLoc, "path" : []})

        while True:

            # If no solution
            if queue.empty():
                return []

            # Current node
            node = queue.get()

            
            if node["board"] == self.goal:
                return node["path"]
            
            if str(node["board"]) not in searched:
                searched.add(str(node["board"]))
                for child in successors(node["board"], node["emptyLoc"]):
                    if str(child[0]) not in searched:
                        queue.put({"board" : child[0], "emptyLoc" : child[1], "path" : node["path"] + [child[2]]})


            


    def refresh(self):
        system("cls") # If unix based terminal. replace cls with clear
        print("Welcome! Press Shift to auto-solve")
        print(self)

        if self.goal == self.board :
            print("Done! Press ESC to exit")
            return False
        return True
