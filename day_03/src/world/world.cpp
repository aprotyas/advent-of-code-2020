#include <world/world.h>

// Standard functions for the most part bar the subscript overload

World::World(std::vector<std::pair<Location, Object>> input, uint32_t rbound,
             uint32_t cbound)
    : map(input), boundary_row(rbound), boundary_col(cbound) {}

const Object World::operator[](const Location &location) const {
    /*
     *  Subscript operator overload of the `World` class
     *  Allows accessing `Object` information at a specific `Location`
     *  in the `World`
     */

    // If trying to access a row which is out of bounds, simply return empty

    // This is not correct, should have an assert or exception of some sort
    // here but it isn't necessary for the program
    if (location.row() >= boundary_row) {
        return Object::empty;
    } else {

        /*
         *  When accessing a position in bound, first convert the location
         *  to an "effective" location by performing a modulo operation
         *  on the column field of the location. This gives the same effect
         *  as the forever extending to the right world pattern
         */
        Location modulo_loc{location.row(), location.col() % boundary_col};
        // For each location, search for its presence in the World
        // Then, return the Object information at that location
        for (int id{0}; id < map.size(); id++) {
            if (map[id].first == modulo_loc) {
                return map[id].second;
            }
        }
        return Object::empty;
    }
}

uint32_t World::get_row_boundary() const { return boundary_row; }
