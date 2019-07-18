from board import board
from pynput import keyboard, mouse
from time import sleep


board = board()

def main():
    board.shuffle()
    board.refresh()

    # Collect events until released
    with keyboard.Listener(
            on_press=on_press,
            on_release=on_release) as listener:
        listener.join()

def on_press(key):
    board.refresh()

def on_release(key):

    if key == keyboard.Key.esc:

        return False
    elif key == keyboard.Key.up:
        board.board, board.emptyLoc = board.moveUp(board.board, board.emptyLoc)
    elif key == keyboard.Key.down:
        board.board, board.emptyLoc = board.moveDown(board.board, board.emptyLoc)
    elif key == keyboard.Key.right:
        board.board, board.emptyLoc = board.moveRight(board.board, board.emptyLoc)
    elif key == keyboard.Key.left:
        board.board, board.emptyLoc = board.moveLeft(board.board, board.emptyLoc)
    elif key == keyboard.Key.shift:
        print("Solving")
        moves = board.solve()
        for move in moves:
            board.moves[move](board.board, board.emptyLoc)
            board.refresh()
            sleep(1)
    board.refresh()


listener = mouse.Listener(
    on_press=on_press,
    on_release=on_release)
listener.start()

if __name__ == "__main__":
    main()
