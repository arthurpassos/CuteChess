//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_IPLAYER_H
#define CHESS1_IPLAYER_H

#include <cstdint>
#include <string>

struct IPlayer {
    virtual uint64_t getID() = 0;
    virtual std::string getName() = 0;

    virtual ~IPlayer() = default;
};

#endif //CHESS1_IPLAYER_H
