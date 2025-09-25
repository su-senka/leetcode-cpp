class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int L = 0, R = n - 1;
        int leftMax = 0, rightMax = 0;
        long long water = 0;

        while (L < R){
            if (height[L] < height[R]){
                leftMax = max(leftMax, height[L]);
                water += leftMax - height[L];
                ++L;
            } else {
                rightMax = max(rightMax, height[R]);
                water += rightMax - height[R];
                --R;
            }
        }

        return static_cast<int>(water);
    }
};
