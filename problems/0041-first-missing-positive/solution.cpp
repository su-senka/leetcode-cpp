class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool hasOne = false;

        for (int x : nums){
            if (x == 1){
                hasOne = true;
                break;
            }
        }

        if (!hasOne){
            return 1;
        }

        for (int& x : nums){
            if (x <= 0 || x > n){
                x = 1;
            }
        }

        // use index (v-1) as a flag for value v by flipping sign.
        for (int i = 0; i < n; ++i){
            int v = abs(nums[i]);

            if (nums[v - 1] > 0){
                nums[v - 1] = -nums[v - 1];
            }
        }

        for (int i = 0; i < n; ++i){
            if (nums[i] > 0){
                return i+1;
            }
        }

        return n+1;
    }
};
