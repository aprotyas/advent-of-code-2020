#include <day_05/day_05.h>
#include <utils/utils.h>

int main(int argc, char *argv[]) {
    std::cout << "----- Advent of Code 2020, Day 05 -----" << std::endl;
    std::string input_fname{"input"};
    std::vector<BoardingPass> input{utils::read_file(input_fname)};
    uint32_t result_part_one{day_05::part_one(input)};
    uint32_t result_part_two{day_05::part_two(input)};
    std::cout << "First answer: " << result_part_one << std::endl;
    std::cout << "Second answer: " << result_part_two << std::endl;
    return 0;
}
