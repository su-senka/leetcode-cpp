class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        string cur;
        cur.reserve(2 * n);

        function<void(int, int)> dfs;

        dfs = [&](int open, int close){
            if ((int)cur.size() == 2 * n){
                res.push_back(cur);
                return;
            }
            if (open < n){
                cur.push_back('(');
                dfs(open + 1, close);
                cur.pop_back();     // backtracking
            }
            if (close < open){
                cur.push_back(')');
                dfs(open, close + 1);
                cur.pop_back();
            }
        };

        dfs(0, 0);
        return res;
    }
};
