class Solution {
public:
    bool isValid(string s) {
        static const unordered_map<char, char> match = {
            {')', '('}, {']', '['}, {'}', '{'}};

        stack<char> st;

        for (char c : s) {
            // it's a closing bracket
            if (match.count(c)) {
                if (st.empty() || st.top() != match.at(c)) {
                    return false;
                } else {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }

        return st.empty();
    }
};
