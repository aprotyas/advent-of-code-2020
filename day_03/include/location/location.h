#pragma once

#include <utility> // std::pair

/*
 *  `Location` class represents its namesake in a `World`
 *  This class allows efficient stepping through a `World` mainly
 */

class Location {
public:
    Location(uint32_t row_0 = 0, uint32_t col_0 = 0);
    ~Location() = default;
    uint32_t row() const;
    uint32_t col() const;
    friend bool operator==(const Location &l1, const Location &l2);

private:
    // location represented as a pair of <row, col> unsigned integers
    std::pair<uint32_t, uint32_t> location;
};

Location operator+(const Location &location,
                   const std::pair<uint32_t, uint32_t> &step);
