#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> idx; // value -> index
      
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            if (auto it = idx.find(need); it != idx.end())
                return {it->second, i};
            idx[nums[i]] = i;
        }
      
        return {};
    }
};
