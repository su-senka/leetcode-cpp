class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;         

        int currentIndex = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[currentIndex]) {
                ++currentIndex;
                nums[currentIndex] = nums[i];
            }
        }
        return currentIndex + 1;
    }
};
