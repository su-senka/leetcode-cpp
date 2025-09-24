class Solution {
public:
    string intToRoman(int num) {
        static const vector<pair<int, string>> vals = {
            {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
            {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"},
            {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}
        };

        string res;

        for (auto [value, symbol] : vals) {
            while (num >= value) {
                res += symbol;
                num -= value;
            }
        }
        
        return res;
    }
};
