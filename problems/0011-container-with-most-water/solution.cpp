class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int best = 0;

        while (l < r)
        {
            best = max(best, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }

        return best;
    }
};
