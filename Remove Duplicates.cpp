#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::vector<int> UniqueNumbers = { nums[0] };
        for (int it = 0; it < nums.size(); it++) {
            if (nums[it] != UniqueNumbers.back()) UniqueNumbers.push_back(nums[it]);
        }
        nums = UniqueNumbers;
        return nums.size();
    }
};