#include "board.h"

bool Cell::occupy(const Player& p){
    if (this->occupied) return false;

    this->occupied = true;
    this->playerOwned = p;

    return true;
}

void Cell::free(){

    this->occupied = false;
    this->playerOwned = nullptr;
}

Player& Cell::changePossession(const Player& newPlayer){
    Player& oldPlayer = this->playerOwned;

    this->occupy(newPlayer);

    return oldPlayer; // may be NULL
}

bool Cell::isOccupied()const{
    return this->occupied;
}

bool Cell::belongsTo(const Player& p)const{
    return this->playerOwned == p;
}

int Cell::getRow()const{
    return this->row_coordinate;
}

int Cell::getColumn()const{
    return this->column_coordinate;
}

Player& Cell::getPlayerOwned()const{
    return playerOwned;
}


Board::Board(int size)
    :size(size), occupiedCells(0){

    table = new Cell[size];
    for (int col=0; col<size; col++){
        table[col] = new Cell[size];
        for (int row=0; row<size; row++){
            table[row][col] = new Cell(row, col);
        }
    }
}

Board::~Board(){
    for (int col=0; col<size; coll++){
        delete[] table[col];
    }
    delete[] table;
}


int Board::getSize()const{ return size;}
bool Board::isFull()const{ return occupiedCells==size*size;}
bool Board::isEmpty()const{ return occupiedCells==0;}

bool Board::isCellOwnedBy(const int row, const int col, const Player &p) const{

    return getCell(row,col).belongsTo(p);
}

bool Board::isCellOccupied(const int row, const int col) const{
    return getCell(row,col).isOccupied();
}

int Board::countStonesFor(const Player &p)const{

    int count=0;
    for (int row=0; row<size; row++){
        for (int col=0; col<size; col++){
            if (getCell(row,col).belongsTo(p)){
                count++;
            }
        }
    }
    return count;
}

Player& Board::removeStone(const int row, const int col){
    Cell c = getCell(row,col);
    Player& p = c.getPlayerOwned();
    c.free();
    return p;
}

bool Board::playAt(const int row, const int col, const Player& p){
    Cell c =getCell(row,col);
    if (c.isOccupied()) return false;

    c.occupy(p);
    return true;
}

