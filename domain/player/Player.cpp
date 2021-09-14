//
// Created by Passos, Arthur on 23/11/20.
//

#include "Player.h"

uint64_t Player::getID() {
    return id;
}

std::string Player::getName() {
    return name;
}

Player::Player(const uint32_t id, const std::string &name) : id(id), name(name) {}
