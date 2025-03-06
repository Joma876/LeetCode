#include <unordered_map>
#include <vector> 

class Solution {
public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        std::unordered_map<int, int> Items; 
        std::vector<int> ReturnVector; 

        for (int x = 1; x <= grid.size() * grid.size(); x++) {
            Items[x] = 0; 
        }

        for (auto it : grid) {
            for (auto SubIt : it) {
                Items[SubIt]++; 
            }
        }

        for (auto it : Items) {
            if (it.second == 0) ReturnVector[1] = it.first; 
            if (it.second == 2) ReturnVector[0] = it.first; 
        }

        return ReturnVector;
    }
};