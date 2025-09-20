class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        // Transform: "^#a#b#c#$" to unify odd/even palindromes
        string t;
        t.reserve(2 * s.size() + 3);
        t.push_back('^');
        for (char c : s) {
            t.push_back('#');
            t.push_back(c);
        }
        t += "#$";

        int n = (int)t.size();
        vector<int> P(n, 0); // P[i] = radius around center i in transformed string
        int C = 0, R = 0;    // current center and right boundary (exclusive)

        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * C - i;
            if (i < R) P[i] = min(R - i, P[mirror]);

            // expand around i
            while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) ++P[i];

            // update center and right boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // find longest
        int center = 0, maxLen = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                center = i;
            }
        }

        // map back to original string
        int start = (center - maxLen) / 2; // due to separators
        return s.substr(start, maxLen);
    }
};
