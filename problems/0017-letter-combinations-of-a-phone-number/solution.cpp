class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        static const string map[10] = {
        "", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };

        size_t total = 1;
        for (char d : digits) {
            int choices = map[d - '0'].size();
            if (choices == 0) return {};          // invalid digit check
            total *= choices;
        }

        vector<string> res;
        res.reserve(total);                       // avoid reallocations

        string cur(digits.size(), '\0');          // fixed-size buffer

        function<void(size_t)> dfs = [&](size_t i){
            if (i == digits.size()){
                res.emplace_back(cur);
                return;
            }
                
            const string& letters = map[digits[i] - '0'];

            for (char c : letters){
                cur[i] = c;
                dfs(i+1);
            }

        })

        dfs(0);
        return res;
    }
};
