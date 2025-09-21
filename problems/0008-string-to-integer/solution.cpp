class Solution {
public:
    int myAtoi(string s) {
        const int n = (int)s.size();
        int i = 0;

        // skip ASCII spaces
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;

        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // precheck overflow guard
        int x = 0;
        const int cap = (sign == 1) ? INT_MAX : INT_MIN;   
        const int pre  = INT_MAX / 10;                     
        const int lastPos = INT_MAX % 10;                  // 7
        const int lastNeg = -(INT_MIN % 10);               // 8

        while (i < n) {
            char c = s[i];
            if (c < '0' || c > '9') break;
            int d = c - '0';

            // overflow check before multiply/add
            if (sign == 1) {
                if (x > pre || (x == pre && d > lastPos)) return INT_MAX;
                x = x * 10 + d;
            } else {
                if (x < -pre || (x == -pre && d > lastNeg)) return INT_MIN;
                x = x * 10 - d;
            }
            ++i;
        }
        return x;
    }
};
