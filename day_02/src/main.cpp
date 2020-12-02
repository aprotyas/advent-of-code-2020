#include <day_02/day_02.h>
#include <utils/utils.h>

int main(int argc, char * argv[]){
    std::cout << "----- Advent of Code 2020, Day 02 -----" << std::endl;
    std::string input_fname {"input"};
    std::vector<day_02::part1::Password> input_part1 {day_02::part1::read_file(input_fname)};
    std::vector<day_02::part2::Password> input_part2 {day_02::part2::read_file(input_fname)};
    uint32_t result_part_one {day_02::part_one(input_part1)};
    uint32_t result_part_two {day_02::part_two(input_part2)};
    std::cout << "First answer: " << result_part_one << std::endl;
    std::cout << "Second answer: " << result_part_two << std::endl;
    return 0;
}
