class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = { false };
        bool col[9][9] = { false };
        bool box[9][9] = { false };

        for (int r = 0; r < 9; ++r){
            for (int c = 0; c < 9; ++c){
                char ch = board[r][c];
                if (ch == '.') continue;

                int num = ch - '1';
                int b   = (r / 3) * 3 + (c / 3);

                if (row[r][num] || col[c][num] || box[b][num])
                return false;

                row[r][num] = col[c][num] = box[b][num] = true;
            }
        }

        return true;
    }
};
