//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_POSITION_H
#define CHESS1_POSITION_H
#include <unordered_set>
#include <cstdint>

class Position {

public:
    Position() = default;
    Position(uint8_t i, uint8_t j);

    uint8_t i;
    uint8_t j;

    bool operator==(const Position& other) const;
};

namespace std
{
    template<>
    struct hash<Position>
    {
        typedef Position argument_type;
        typedef std::size_t value_type;

        value_type operator()(argument_type const& s) const
        {
            std::hash<int> int_hasher;

            return int_hasher(s.i) ^ int_hasher(s.j);
        }
    };
}

#endif //CHESS1_POSITION_H
