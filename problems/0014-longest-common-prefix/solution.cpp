class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        auto [min, max] = minmax_element(strs.begin(), strs.end());
        
        const string& a = *min;
        const string& b = *max;

        size_t i = 0;
        size_t L = std::min(a.size(), b.size());

        while (i < L && a[i] == b[i]) ++i;

        return a.substr(0, i);
    }
};
