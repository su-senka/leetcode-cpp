class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;

        string out;
        out.reserve(n);

        int cycle = 2 * numRows - 2;

        // row by row
        for (int r = 0; r < numRows; ++r) {
            for (int i = r; i < n; i += cycle) {
                // vertical hit in the zig
                out.push_back(s[i]);

                // diagonal hit for middle rows
                int j = i + cycle - 2 * r;
                if (r != 0 && r != numRows - 1 && j < n) {
                    out.push_back(s[j]);
                }
            }
        }
        return out;
    }
};
