#pragma once
#include <iostream>
#include <string>
#include <utils/utils.h>
#include <vector>

typedef std::string BoardingPass;

struct Seat {
    uint32_t row;
    uint32_t col;
};

uint32_t ID(const Seat s);
Seat seat(const BoardingPass &bp);

namespace day_05 {
uint32_t part_one(std::vector<BoardingPass> &in);
uint32_t part_two(std::vector<BoardingPass> &in);
} // namespace day_05
