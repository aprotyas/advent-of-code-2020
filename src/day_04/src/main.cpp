#include <day_04/day_04.h>
#include <utils/utils.h>

int main(int argc, char *argv[]) {
    std::cout << "----- Advent of Code 2020, Day 04 -----" << std::endl;
    std::string input_fname{"input"};
    std::vector<std::string> input_lines{utils::read_file(input_fname)};
    std::vector<Passport> input{day_04::parse_input(input_lines)};
    uint32_t result_part_one{day_04::part_one(input)};
    uint32_t result_part_two{day_04::part_two(input)};
    std::cout << "First answer: " << result_part_one << std::endl;
    std::cout << "Second answer: " << result_part_two << std::endl;
    return 0;
}
