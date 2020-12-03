#include <day_03/day_03.h>

/*
 *  My brain is too fried to come up with time/space complexity today
 */

namespace day_03 {
World parse_input(const std::vector<std::string> &input) {
    /*
     *  Takes in the output of utils::read_file() to parse
     *  and create the `World` data structure from input
     */

    // should this be a typedef?
    std::vector<std::pair<Location, Object>> buffer;
    // iterating through each "location" on the input grid
    for (uint32_t row{0}; row < input.size(); row++) {
        for (uint32_t col{0}; col < input[row].size(); col++) {
            // adds a `Location` and an `Object` for each "location" on the grid
            // Represent presence of tree with `Object::tree` enumeration
            // Everything else is `Object::empty`
            buffer.push_back(
                {{row, col},
                 (input[row][col] == '#') ? Object::tree : Object::empty});
        }
    }
    // Need row/col boundaries of World for infinite extension to the right
    uint32_t boundary_r{static_cast<uint32_t>(input.size())};
    uint32_t boundary_c{static_cast<uint32_t>(input[0].size())};
    // Returning an instance of the `World` parsed!
    return {buffer, boundary_r, boundary_c};
}

uint32_t part_one(const World &world,
                  const std::pair<uint32_t, uint32_t> &step) {
    /*
     *  Takes in the `World` obtained through `parse_input()`
     *  and a 2-dimensional step to advance through the world
     *
     *  `step` is {1,3} by default to simplify actual part_one call
     */
    Location p{};       // starting at {0,0}
    uint32_t objects{}; // object count
    // Step through world till bottom reached
    while (p.row() < world.get_row_boundary()) {
        // Only add to the count if tree encountered
        objects += world[p] == Object::tree ? 1 : 0;
        p = p + step;
    }
    return objects;
}

uint32_t part_two(const World &world) {
    /*
     *  Takes in the `World` obtaind through `parse_input()`
     *  and solves part 2, described inside
     */

    // vector of `step`s. Each is used to walk through the world
    std::vector<std::pair<uint32_t, uint32_t>> steps{
        {1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}};
    uint32_t result{1};
    for (const auto &step : steps) {
        // for each `step` size, count tree occurrences and multiply to result
        result *= part_one(world, step);
    }
    return result;
}
} // namespace day_03
