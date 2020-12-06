#include <day_06/day_06.h>
#include <utils/utils.h>

int main(int argc, char *argv[]) {
    std::cout << "----- Advent of Code 2020, Day 06 -----" << std::endl;
    std::string input_fname{"input"};
    std::vector<std::string> input{utils::read_file(input_fname)};
    std::vector<Group> groups{day_06::parse_groups(input)};
    uint32_t result_part_one{day_06::part_one(groups)};
    uint32_t result_part_two{day_06::part_two(groups)};
    std::cout << "First answer: " << result_part_one << std::endl;
    std::cout << "Second answer: " << result_part_two << std::endl;
    return 0;
}
