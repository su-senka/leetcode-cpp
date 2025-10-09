class Solution {
private:
    int next(int n) {
        int total = 0;
        while (n > 0) {
            int digit = n % 10;
            total += digit * digit;
            n /= 10;
        }
        return total;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);

        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }

        return fast == 1;
    }
};
