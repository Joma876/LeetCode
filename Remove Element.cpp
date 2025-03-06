#include <algorithm>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove_if(nums.begin(), nums.end(), [&](int num) {return num == val; }), nums.end());
        return nums.size();
    }
};
