#ifndef PLAYER_H
#define PLAYER_H

#include <string>


class Player{
  std::string name;

public:


  Player()
    :name(""){
    }

  Player(const std::string name)
    :name(name){
    }

  ~Player(){}

  std::string getName()const{return this->name;}

  bool operator==(const Player &other){ return (this == &other); }
  bool operator!=(const Player &other){ return !(*this == other); }

};


#endif // PLAYER_H
