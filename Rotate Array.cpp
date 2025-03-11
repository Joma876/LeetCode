#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        std::vector<int> Rotated;
        if (nums.size() == 1) return;
        k %= nums.size();
        for (int it = nums.size() - k; it < nums.size(); it++) {
            Rotated.push_back(nums[it]);
        }

        for (int it = 0; it < nums.size() - k; it++) {
            Rotated.push_back(nums[it]);
        }

        nums = Rotated;
    }
};