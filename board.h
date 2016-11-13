#ifndef BOARD_H
#define BOARD_H

class Cell{
public:

    Cell(int row, int col)
        :column_coordinate(col), row_coordinate(row), occupied(false), playerOwned(nullptr){
    }
    ~Cell(){}

    bool    occupy          (const Player& p);
    void    free            ();
    Player& changePossession(const Player& newPlayer);

    bool    isOccupied      ()const;
    bool    belongsTo       (const Player& p)const;

    int     getRow          ()const;
    int     getColumn       ()const;
    Player& getPlayerOwned  ()const;


private:
    int row_coordinate;
    int column_coordinate;

    bool occupied;
    Player& playerOwned;
};





class Board{
public:

    Board(int size);
    ~Board();

    bool playAt(const int row, const int col, const Player& p);
    Player& removeStone(const int row, const int col);
    int countStonesFor(const Player& p)const;

    bool isCellOccupied(const int row, const int col)const;
    bool isCellOwnedBy(const int row, const int col, const Player& p)const;
    bool isEmpty()const;
    bool isFull()const;

    int getSize()const;


private:
    int size;
    Cell** table;
    int occupiedCells;

    Cell getCell(int row, int col){return &board[row][col];}
};

#endif // BOARD_H
