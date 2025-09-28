class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // bit masks
        rows.fill(ALL);
        cols.fill(ALL);
        boxes.fill(ALL);

        // initialize masks
        empties.clear();
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') {
                    empties.emplace_back(r, c);
                } else {
                    int d = ch - '1';             
                    int b = boxIndex(r, c);
                    uint16_t bit = 1u << d;

                    rows[r] &= ~bit;
                    cols[c] &= ~bit;
                    boxes[b] &= ~bit;
                }
            }
        }

        backtrack(board);
    }

private:
    static constexpr uint16_t ALL = 0x1FF; 
    std::array<uint16_t, 9> rows{}, cols{}, boxes{};
    vector<std::pair<int,int>> empties;

    static inline int boxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    // minimum remaining values
    int selectCell(const vector<vector<char>>& board) {
        int bestIdx = -1;
        int bestCount = 10;

        for (int i = 0; i < (int)empties.size(); ++i) {
            auto [r, c] = empties[i];

            if (board[r][c] != '.') continue; 
            uint16_t avail = rows[r] & cols[c] & boxes[boxIndex(r,c)];
            if (avail == 0) return i; 

            int cnt = __builtin_popcount(avail);
            if (cnt < bestCount) {
                bestCount = cnt;
                bestIdx = i;
                if (cnt == 1) break; 
            }
        }
        return bestIdx;
    }

    bool backtrack(vector<vector<char>>& board) {
        int idx = selectCell(board);
        if (idx == -1) return true; 

        auto [r, c] = empties[idx];
        uint16_t avail = rows[r] & cols[c] & boxes[boxIndex(r,c)];
        if (avail == 0) return false;

        while (avail) {
            uint16_t bit = avail & -avail;             // least significant 1-bit
            int d = __builtin_ctz(bit);                
            place(board, r, c, d, bit);

            if (backtrack(board)) return true;

            remove(board, r, c, d, bit);
            avail &= (avail - 1); 
        }
        return false; // backtrack
    }

    inline void place(vector<vector<char>>& board, int r, int c, int d, uint16_t bit) {
        board[r][c] = static_cast<char>('1' + d);
        rows[r] &= ~bit;
        cols[c] &= ~bit;
        boxes[boxIndex(r, c)] &= ~bit;
    }

    inline void remove(vector<vector<char>>& board, int r, int c, int d, uint16_t bit) {
        board[r][c] = '.';
        rows[r] |= bit;
        cols[c] |= bit;
        boxes[boxIndex(r, c)] |= bit;
    }
};
