#include <algorithm>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        nums1.resize(m);
        nums1.insert(nums1.end(), std::make_move_iterator(nums2.begin()), std::make_move_iterator(nums2.end()));
        std::sort(nums1.begin(), nums1.end());
    }
};