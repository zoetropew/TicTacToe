# TicTacToe
A simple game of Tic Tac Toe

Features include:
1. Playing against the computer
2. Finding winner of completed board
3. Finding next move for O if given incomplete board

## Usage:
### Playing against the computer:
1. Run program without giving arguments for board. Program will print empty board and prompt user for move (you are X)
```sh
$ ./tictactoe
? | ? | ?
--+---+--
? | ? | ?
--+---+--
? | ? | ?
X:
```
2. Choose move (enter row and column. Giving 0 0 will be the top left square, and 2 2 will be the bottom right) Note: program will only take numbers 0-2. Other input will prompt the program to print "invalid move" until user gives valid move
```sh
X: 1 1
```
3. Program will print the board with your move, choose a move for O, print this new board, and then prompt you for your next move
```sh
? | ? | ?
--+---+--
? | X | ?
--+---+--
? | ? | ?
O: 0 1
? | O | ?
--+---+--
? | X | ?
--+---+--
? | ? | ?
X: 
```
4. Continue taking turns
5. Program will run until game ends and print ```X wins``` or ```O wins``` or ```draw```

### Finding winner of completed board:
1. Run program with the game board in the arguments. Type X, O, or ? (for empty space) in order from left to right and top to bottom on the board, filling in the whole board.
2. Program will print the given board and then print either a winner or a draw

Example:
```sh
$ ./tictactoe X O ? O X O ? ? X
X | O | ?
--+---+--
O | X | O
--+---+--
? | ? | X
X wins
```
Note: program does not currently screen for incorrect input. If user types characters other than X, O, or ? the board will print with these other characters, but they will be treated like ?s (empty spaces)

### Finding next move for O if given incomplete board:
1. Run program with the incomplete game board in the arguments. Type X, O, or ? (for empty space) in order from left to right and top to bottom on the board. You do not need to fill all 9 spaces. 
2. Program will print board and give a suggested next move for O

Example:
```sh
$ ./tictactoe X O ? O
X | O | ?
--+---+--
O | ? | ?
--+---+--
? | ? | ?
O: 1 1
```
Note: program does not currently screen for incorrect input. If user types characters other than X, O, or ? the board will print with these other characters, but they may interfere with finding the next move for O (the program may output ```O: -1 -1```)

