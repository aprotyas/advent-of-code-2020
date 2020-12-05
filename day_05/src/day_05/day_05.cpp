#include <day_05/day_05.h>

uint32_t ID(const Seat s) { return s.row * 8 + s.col; }

Seat seat(const BoardingPass &bp) {
    uint32_t row{utils::bin2dec(bp.substr(0, 7), 'F', 'B')};
    uint32_t col{utils::bin2dec(bp.substr(7), 'L', 'R')};
    return {row, col};
}

namespace day_05 {

uint32_t part_one(std::vector<BoardingPass> &in) {
    uint32_t max_ID{};
    for (const BoardingPass &bp : in) {
        uint32_t bp_ID{ID(seat(bp))};
        max_ID = (max_ID < bp_ID) ? bp_ID : max_ID;
    }
    return max_ID;
}

uint32_t part_two(std::vector<BoardingPass> &in) {
    std::vector<uint32_t> ids;
    for (const BoardingPass &bp : in) {
        ids.push_back(ID(seat(bp)));
    }
    std::sort(ids.begin(), ids.end());
    for (size_t i{}; i < ids.size() - 1; i++) {
        if (ids[i + 1] - ids[i] == 2) {
            return ids[i] + 1;
        }
    }
    return 0;
}

} // namespace day_05
