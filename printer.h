#ifndef PRINTER_H
#define PRINTER_H

#include "board.h"
#include "player.h"

class Board;

class Printer{
public:
  Printer(const char emptyCell='.', const char player1='x', const char player2='o');
  ~Printer(){}

  void printBoard(Board& board, const Player* player1);


private:
  char emptyCellIcon;
  char player1Icon;
  char player2Icon;
};


#endif //PRINTER_H
