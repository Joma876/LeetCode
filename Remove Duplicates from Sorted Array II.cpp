#include <algorithm>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int> nums) {
        for (int it = 2; it < nums.size(); it++) {
            if (nums[it - 2] == nums[it - 1] && nums[it - 1] == nums[it]) {
                std::rotate(nums.begin() + it - 1, nums.begin() + it, nums.end());
                nums.pop_back();
                it--;
            }
        }
        return nums.size();
    }
};