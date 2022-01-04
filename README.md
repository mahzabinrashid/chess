# Chess

## Summary

CS 246 - Object-Oriented Software Development
Chess Game

Team Members : Inqiyad Patwary, Mahzabin Rashid Fariha, Sadman Ahmed

Our team developed this chess engine for our CS246 Final Project (Fall 2021)

The chess game provides different functionalities from the assignment specification:

- Graphical interface using the XWindow Library
- 1 level of difficulty for the computer AI
- Setup Mode
- Play Modes of
  - Player vs Player
  - Player vs Computer

## Command Interpreter Instructions

- <i>game white-player black-player</i> starts a new game.
  - <i>white-player</i> & <i>white-player</i> parameters can be either <i>human</i> or <i>computer[1-4]</i>
- <i>resign</i> concedes the game to your opponent
- capital letters represent white pieces, otherwise black pieces

  | Letter | K    | Q     | R    | B      | N      | P    |
  | ------ | ---- | ----- | ---- | ------ | ------ | ---- |
  | Piece  | King | Queen | Rook | Bishop | Knight | Pawn |

  <br>

- To move: <i>move src dst</i> (ex. <i>move e2 e4</i>)

- castling is specified by two-square move for the king

  - black: <i>move e1 g1</i>
  - white: move e1 c1

- Pawn promotion additionally specify the piece type to which the pawn is promoted: move e7 e8 Q.

- <i>setup</i> enters setup mode that can set up initial board configurations(can only be done when game is not running)

  - <i>\+ piece position</i> places the piece on the position (ex. <i>+ K e1</i>), replaces if a piece already exists
  - <i>\- position </i> removes the piece from the position(ex. <i>- e1</i>), takes no action if there is nothing
  - <i>= colour</i> makes it colour’s turn to go next(ex. <i>= white</i>)
  - <i>done</i> leaves setup mode

## Design & Planning

For how our team tackled the project: <a href="plan.pdf">Plan</a>
For our UML: <a href="uml.pdf">Plan</a>
