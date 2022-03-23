# BoardGame2D Report 

#### BoardGame2D is an abstract base class which has following functions:

- **playUser**(with paramater): it takes a string as a parameter and plays the game accordingly. It is pure virtual
- **playUser**(without parameter):  it takes a string from the user for the next move in a loop and plays the game until it is over. It also prints the board between the moves. It is pure virtual
- **playAuto**: Computer plays a random move. It is pure virtual.
- **playAutoAll**: Computer plays random moves until game is over and It also prints the board between the moves. It is pure virtual.
- **boardScore**: It returns game score. 0 is the best score. It is pure virtual.
- **endGame**: It checks if game is over. It is pure virtual.
- **initialize**: It initializes the board. It is pure virtual.
- **playVector**: It is static function which takes a vector of BoardGame2D * objects.  It plays all the games in the vector until they end.
- **print** and **operator<<** : Its prints the game on the screen starting from the top left corner of the terminal. **print** is pure virtual.



### BoardGame2D has following derived class

- ### PegSolitare

- ### EightPuzzle



## PegSolitare

##### This class plays the type 2 game of [this](https://upload.wikimedia.org/wikipedia/commons/thumb/4/47/Peg_Solitaire_game_board_shapes.svg/1920px-Peg_Solitaire_game_board_shapes.svg.png). It has following functions , data and class:



### Cell class

The class Cell holds the position of the cell (A, B, C, etc) and the row number (1, 2, 3, etc). 



### **playUser**(with paramater):

It takes a string parameter. String format is "XY D". 

​		X is character to represent rows.

​		Y is intiger to represent columns.

​		D is direction to represents the initials of the Right Left Up and Down directions.

If string input is valid it checks if the the move is valid. If move is valid it plays the move.



### **playUser**(without paramater):

It takes a string from the user for the next move and call playUser with this string in a loop and plays until game is over. It also prints the board between the moves.



 ### playAuto:

It generates random inputs until it finds a valid move. When it find,plays one move.



### playAutoAll:

It call playAuto for the next move in a loop and plays until game is over.It also prints the board between the moves.



### endGame:

checks if game is over. If game is over returns ***true*** else return ***false***.



### boardScore:

Returns number of pegs for current board. 1 is best score.



### initialize:

Initialize the type 2 game of [this](https://upload.wikimedia.org/wikipedia/commons/thumb/4/47/Peg_Solitaire_game_board_shapes.svg/1920px-Peg_Solitaire_game_board_shapes.svg.png).



### print:

prints the game on the screen starting from the top left corner of the terminal.



### inputCheck

Takes a string parameter and checks if input string is valid. If it is valid then returns ***true***. Else returns ***false***. 



#### 2D Cell Vector

PegSolitare game holds as a 2D vector of vector of Cell in here.







## EightPuzzle

##### This class plays [this](https://en.wikipedia.org/wiki/15_puzzle) for a 3x3 board. It has following functions , data;



### **playUser**(with paramater):

It takes a string parameter. String format is "XY D". 

​		X is character to represent rows.

​		Y is intiger to represent columns.

​		D is direction to represents the initials of the Right Left Up and Down directions.

If string input is valid it checks if the the move is valid. If move is valid it plays the move.



### **playUser**(without paramater):

It takes a string from the user for the next move and call playUser with this string in a loop and plays until game is over. It also prints the board between the moves.



 ### playAuto:

It generates random inputs until it finds a valid move. When it find,plays one move.



### playAutoAll:

It call playAuto for the next move in a loop and plays until game is over. It also prints the board between the moves.



### endGame:

checks if game is over. If game is over returns ***true*** else return ***false***.



### boardScore:

Counts puzzle pieces that are not in the right place and returns it. 0 is best score.



### initialize:

Initializes the solved version of puzzle and It plays one million random move. So the puzzle is mixed up.

With this method, we avoid unsolvable puzzles because we are mixing up a solved puzzle.



### print:

prints the game on the screen starting from the top left corner of the terminal.



### inputCheck

Takes a string parameter and checks if input string is valid. If it is valid then returns ***true***. Else returns ***false***. 



#### 2D Intiger Vector

EightPuzzle game holds as a 2D vector of vector of Intiger in here.




