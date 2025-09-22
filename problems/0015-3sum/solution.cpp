class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        const int n = (int)nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;   // skip same anchor
            if (nums[i] > 0) break;                        // all further > 0

            int L = i + 1, R = n - 1;

            // pruning
            if (L + 1 < n) {
                long minSum = (long)nums[i] + nums[L] + nums[L+1];
                if (minSum > 0) break;                     // too large already
                long maxSum = (long)nums[i] + nums[R] + nums[R-1];
                if (maxSum < 0) continue;                  // too small; next i
            }

            while (L < R) {
                long s = (long)nums[i] + nums[L] + nums[R];
                if (s < 0) ++L;
                else if (s > 0) --R;
                else {
                    res.push_back({nums[i], nums[L], nums[R]});
                    // skip duplicates on both sides
                    int a = nums[L], b = nums[R];
                    while (L < R && nums[L] == a) ++L;
                    while (L < R && nums[R] == b) --R;
                }
            }
        }
        return res;
    }
};
