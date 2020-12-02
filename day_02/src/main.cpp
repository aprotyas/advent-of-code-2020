#include <day_02/day_02.h>
#include <utils/utils.h>

int main(int argc, char * argv[]){
    std::cout << "----- Advent of Code 2020, Day 02 -----" << std::endl;
    std::string input_fname {"input"};
    std::vector<Password> input {day_02::read_file(input_fname)};
    uint32_t result_part_one {day_02::part_one(input)};
    uint32_t result_part_two {day_02::part_two(input)};
    std::cout << "First answer: " << result_part_one << std::endl;
    std::cout << "Second answer: " << result_part_two << std::endl;
    return 0;
}
