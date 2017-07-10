#ifndef BOARD_H
#define BOARD_H

#include <vector>

//#include "util.h"
#include "printer.h"
#include "player.h"


class Cell{
public:

    Cell(int row, int col)
        :column_coordinate(col), row_coordinate(row), occupied(false), playerOwned(NULL){
    }
    ~Cell(){}

    bool    occupy          (Player* p);
    void    free            ();
    Player* changePossession(Player* newPlayer);

    bool    isOccupied      ()const;
    bool    belongsTo       (const Player* p)const;

    int     getRow          ()const;
    int     getColumn       ()const;
    Player* getPlayerOwned  ()const;


private:
    int row_coordinate;
    int column_coordinate;

    bool occupied;
    Player* playerOwned;
};





class Board{
    friend class Printer;
public:

    Board(int size);
    ~Board();

    bool    playAt        (const int row, const int col, Player* p);
    Player* removeStone   (const int row, const int col);
    int     countStonesFor(const Player* p);

    bool isCellOccupied   (const int row, const int col);
    bool isCellOwnedBy    (const int row, const int col, const Player* p);
    bool isEmpty          ()const;
    bool isFull           ()const;

    int getSize           ()const;


private:
    int size;
    std::vector< std::vector<Cell> > table;
    int occupiedCells;

    Cell& getCell(const int row,const int col);
};

#endif // BOARD_H
