#include <day_01/day_01.h>
#include <utils/utils.h>

int main(int argc, char * argv[]){
    std::cout << "----- Advent of Code 2020, Day 01 -----" << std::endl;
    std::string input_fname {"input"};
    std::vector<uint32_t> input {day_01::read_file(input_fname)};
    uint32_t target {2020};
    uint32_t result_part_one {day_01::part_one(input, target)};
    uint32_t result_part_two {day_01::part_two(input, target)};
    std::cout << "First answer: " << result_part_one << std::endl;
    std::cout << "Second answer: " << result_part_two << std::endl;
    return 0;
}
