#include <location/location.h>

// Nothing interesting to comment about here

Location::Location(uint32_t row_0, uint32_t col_0)
    : location(std::make_pair(row_0, col_0)) {}

Location operator+(const Location &location,
                   const std::pair<uint32_t, uint32_t> &step) {
    return {location.row() + step.first, location.col() + step.second};
}

bool operator==(const Location &l1, const Location &l2) {
    return (l1.row() == l2.row()) && (l1.col() == l2.col());
}

uint32_t Location::row() const { return location.first; }

uint32_t Location::col() const { return location.second; }
