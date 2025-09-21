# Palindrome Number

Check if an integer reads the same forward and backward **without** strings.

## Method
- Reject negatives and numbers ending with `0` (except `0`).
- Reverse only half the digits until `reversedHalf >= x`.
- Palindrome if `x == reversedHalf` (even length)  
  or `x == reversedHalf / 10` (odd length).

## Complexity
* **Time:** `O(log10 |x|)` — we check half the digits.
* **Space:** `O(1)` — constant extra memory.
