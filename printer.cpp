#include "printer.h"

#include <string>
#include <iostream>

using namespace std;

Printer::Printer(const char emptyCell, const char player1, const char player2)
  :emptyCellIcon(emptyCell), player1Icon(player1), player2Icon(player2){

}

void Printer::printBoard(Board& board, const Player* player1){

  const string LTTRS = "ABCDEFGHJKLMNOPQRSTUVWXYZ";
  int n = board.size;

  // printing header
  for (int i=0; i<n/10+2; i++) cout << " "; // print offset created by row numbering
  for (int i=0; i<n; i++) cout << LTTRS.at(i) << " ";
  cout.put(cout.widen('\n'));
  cout.flush();
  for (int i=0; i<n/10+1; i++) cout << " ";
  cout << "+";
  for (int i=0; i<n; i++) cout <<"--";
  cout << "+";
  cout.put(cout.widen('\n'));
  cout.flush();

  // printing each row
  for (int i=0; i<n; i++){

    // printing row numbering at left side
    for (int j=0; j<n/10-i/10; j++) cout << " "; // print trailing spaces for formatting
    cout << i << "|";

    for (int j=0; j<n; j++){

        Cell c = board.getCell(i,j);
        if (!c.isOccupied()) cout << this->emptyCellIcon;
        else if (c.getPlayerOwned() == player1) cout << this ->player1Icon;
        else cout << this->player2Icon;

        cout << " ";
    }
    // printing row numbering at the right side
    cout << "|" << i;
    cout.put(cout.widen('\n'));
    cout.flush();
  }

  // printing footer
  for (int i=0; i<n/10+1; i++) cout << " ";
  cout << "+";
  for (int i=0; i<n; i++) cout <<"--";
  cout << "+";
  cout.put(cout.widen('\n'));
  cout.flush();
  for (int i=0; i<n/10+2; i++) cout << " ";
  for (int i=0; i<n; i++) cout << LTTRS.at(i) << " ";
  cout.put(cout.widen('\n'));
  cout.flush();

}
