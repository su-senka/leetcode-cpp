class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;

        for (int r = (int)triangle.size() - 2; r >= 0; --r){
            for (int j = 0; j <= r; ++j){
                triangle[r][j] += min(triangle[r+1][j], triangle[r+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};
