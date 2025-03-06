#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> SmallerThanPivot;
        vector<int> BiggerThanPivot;
        int SameAsPivot = 0;
        for (int it = 0; it < nums.size(); it++) {
            if (nums[it] < pivot) SmallerThanPivot.push_back(nums[it]);
            if (nums[it] > pivot) BiggerThanPivot.push_back(nums[it]);
            if (nums[it] == pivot) SameAsPivot++;
        }

        nums.clear();

        nums.insert(nums.end(), make_move_iterator(SmallerThanPivot.begin()), make_move_iterator(SmallerThanPivot.end()));
        nums.insert(nums.end(), SameAsPivot, pivot);
        nums.insert(nums.end(), make_move_iterator(BiggerThanPivot.begin()), make_move_iterator(BiggerThanPivot.end()));

        return nums;
    }
};
