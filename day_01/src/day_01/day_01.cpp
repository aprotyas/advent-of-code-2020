#include <day_01/day_01.h>

uint32_t day_01::part_one(std::vector<uint32_t> input, uint32_t target){
    /*
     *  Using a set to look for pairs
     *  Time complexity O(n), space complexity O(n)
     */
    std::set<uint32_t> s;

    for(auto n {std::begin(input)}; n != std::end(input); n++){
        // if the complement of current number exists, return product
        if(s.find(target - *n) != s.end()){
            return *n * (target - *n);
        }
        // else, add current number to set
        s.insert(*n);
    }
    return 0; // unsuccessful
}

uint32_t day_01::part_two(std::vector<uint32_t> input, uint32_t target){
    /*
     *  Sort the input vector and use a double pointer sliding window approach
     *
     *  Sorting required so that we can guarantee sliding window size fixes
     *  do not mess up discovery of triplets that satisfy the target condition
     *
     *  Time complexity O(n^2), space complexity O(1)
     */
    std::sort(input.begin(), input.end()); // deep copy
    uint32_t sz = input.size();
    for(uint32_t i = 0; i < sz - 2; i++){
        /*
         *  The idea is that we define left/right pointers in the range
         *  (current_iteration_id, vector_size)
         *
         *  For every triplet formed by the numbers at current_iter_idx,
         *  left pointer, and right pointer, we check whether they meet
         *  the condition. If not, adjust left/right pointer accordingly.
         *
         *  This adjustment works only because the vector has been sorted!
         */
        uint32_t l = i + 1;  // left pointer
        uint32_t r = sz - 1; // right pointer
        while(l < r){
            uint32_t sum = input[i] + input[l] + input[r];
            if(sum == target){
                return input[i] * input[l] * input[r];
            }
            else if(sum < target){
                l++;
            }
            else{ //sum > target
                r--;
            }
        }
    }
    return 0;
}
