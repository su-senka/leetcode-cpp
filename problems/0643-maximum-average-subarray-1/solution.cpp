class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        long long windowSum = 0;
        for (int i = 0; i < k; ++i){
            windowSum = windowSum + nums[i];
        }

        long long maxSum = windowSum;

        for (int i = k; i < (int)nums.size(); ++i){
            windowSum = windowSum + nums[i];
            windowSum = windowSum - nums[i - k];

            if (windowSum > maxSum){
                maxSum = windowSum;
            }
        }

        return static_cast<double>(maxSum) / static_cast<double>(k);
    }
};
