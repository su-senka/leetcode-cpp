class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        function<void(int, unsigned, unsigned, unsigned)> dfs =
            [&](int row, unsigned cols, unsigned diag, unsigned anti) {
                if (row == n) { res.push_back(board); return; }

                unsigned mask = (1u << n) - 1;
                unsigned free = (~(cols | diag | anti)) & mask;

                while (free) {
                    unsigned p = free & -free;   // pick lowest available bit
                    free ^= p;
                    int c = __builtin_ctz(p);    // column index

                    board[row][c] = 'Q';
                    dfs(row + 1, cols | p, (diag | p) << 1, (anti | p) >> 1);
                    board[row][c] = '.';         // backtrack
                }
            };

        dfs(0, 0, 0, 0);
        return res;
    }
};
