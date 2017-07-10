#include <iostream>
#include "board.h"
#include "player.h"
#include "printer.h"

using namespace std;

int main(int argc, char *argv[])
{
    // dummy client code for demonstration so far

    int n = 9;
    Board board = Board(n);


    Player *p1 = new Player(),
        *p2 = new Player();
    Printer printer = Printer();


    board.playAt(0,0, p1);
    board.playAt(4,5, p2);
    board.playAt(6,7, p1);


    printer.printBoard(board, p1);
    cout << endl; cout << endl;


    board.removeStone(0,0);
    printer.printBoard(board, p1);

    delete p1, p2;
    return 0;
}
