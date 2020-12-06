#pragma once

#include <iostream>
#include <location/location.h>
#include <utility>
#include <vector>

// Better than using magic numbers to indicate a tree :-)
enum class Object { empty, tree };

/*
 *  `World` class allows intuitive representation of input data
 *
 *  Mainly helps in accessing tree information at a given location
 *  using the overloaded subscript operator
 *
 *  The class is a vector of pairs, where each pair is a `Location`
 *  and an `Object`. This is not so intuitive... but I tried using
 *  an unordered_map with `Location` keys and `Object` values
 *  but I got a bunch of hashset issues that I was too tired to
 *  deal with...
 */

class World {
public:
    World(std::vector<std::pair<Location, Object>> input, uint32_t rbound,
          uint32_t cbound);
    ~World() = default;
    // Allows accessing `Object` information in the world by
    // subscripting using a `Location` ---- logic checks out
    const Object operator[](const Location &location) const;
    uint32_t get_row_boundary() const;

private:
    std::vector<std::pair<Location, Object>> map;
    uint32_t boundary_row;
    uint32_t boundary_col;
};
