# TicTacToe
A project done for a C & Systems Programming class (CS221) at the University of San Francisco.

Features include:
1. Playing against the computer
2. Finding winner of completed board
3. Finding next move for O if given incomplete board

## Usage:
Playing against the computer:
1. Run program without giving arguments for board. Program will print empty board and prompt user for move (you are X)
2. Choose move (enter row and column. Giving 0 0 will be the top left square, and 2 2 will be the bottom right)
3. Program will print the board with your move, choose a move for O, print this new board, and then prompt you for your next move
4. Continue taking turns
5. Program will run until there is a winner or a draw, which will be printed.

Finding winner of completed board:
1. Run program with the game board in the arguments. Type X, O, or ? (for empty space) in order from left to right and top to bottom on the board, filling in the whole board. Example:
```c
./main X O ? O X O ? ? X
```
2. Program will print the given board and then print either a winner or a draw

Finding next move for O if given incomplete board:
1. Run program with the incomplete game board in the arguments. Type X, O, or ? (for empty space) in order from left to right and top to bottom on the board. You do not need to fill all 9 spaces.
