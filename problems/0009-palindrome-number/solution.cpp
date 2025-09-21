class Solution {
public:
    bool isPalindrome(int x) {
        // negative numbers and numbers ending in 0 (except 0 itself) can't be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;
        while (x > reversedHalf)
        {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
      
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};
