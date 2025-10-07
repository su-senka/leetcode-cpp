class Solution {
public:
    string addBinary(string a, string b) {
        int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;

    std::string out;
    out.reserve(std::max(a.size(), b.size()) + 1);

    while (i >= 0 || j >= 0 || carry) {
        int ai = (i >= 0) ? (a[i--] - '0') : 0;
        int bi = (j >= 0) ? (b[j--] - '0') : 0;

        int sum = ai + bi + carry;
        out.push_back(char('0' + (sum & 1))); 
        carry = sum >> 1;                      
    }

    std::reverse(out.begin(), out.end());
    return out;
    }
};
