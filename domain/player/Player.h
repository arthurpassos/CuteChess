//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_PLAYER_H
#define CHESS1_PLAYER_H


#include <string>
#include "IPlayer.h"

class Player : public IPlayer {
public:
    uint64_t getID() override;

    std::string getName() override;

    Player(uint32_t id, const std::string &name);

private:
    const uint32_t id;
    const std::string name;
};


#endif //CHESS1_PLAYER_H
