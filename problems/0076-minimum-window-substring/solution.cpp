class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        // count requirements from t
        array<int, 128> need{}; need.fill(0);
        int required = 0;                             
        for (char c : t) {
            if (need[c] == 0) required++;
            need[c]++;
        }

        // sliding window state
        array<int, 128> have{}; have.fill(0);
        int formed = 0;

        int bestLen = INT_MAX, bestL = 0;
        int l = 0;

        for (int r = 0; r < (int)s.size(); ++r){
            char cr = s[r];

            if (need[cr] > 0){
                have[cr]++;

                if (have[cr] == need[cr]){
                    formed++;
                }
            }

            // When valid, shrink from left to minimize
            while (formed == required){
                if (r - l + 1 < bestLen){
                    bestLen = r - l + 1;
                    bestL = l;
                }

                char cl = s[l];
                if (need[cl] > 0){
                    have[cl]--;

                    if (have[cl] < need[cl]){
                        formed--;
                    }
                }

                ++l;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};
