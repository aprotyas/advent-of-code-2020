#include <day_03/day_03.h>
#include <utils/utils.h>

int main(int argc, char *argv[]) {
    std::cout << "----- Advent of Code 2020, Day 03 -----" << std::endl;
    std::string input_fname{"input"};
    std::vector<std::string> input_lines{utils::read_file(input_fname)};
    World input{day_03::parse_input(input_lines)};
    uint32_t result_part_one{day_03::part_one(input)};
    uint32_t result_part_two{day_03::part_two(input)};
    std::cout << "First answer: " << result_part_one << std::endl;
    std::cout << "Second answer: " << result_part_two << std::endl;
    return 0;
}
