# Reverse 32-bit Integer

Given a signed 32-bit integer `x`, return its digits reversed. If the reversed value falls outside `[-2^31, 2^31 - 1]`, return `0`.  
No 64-bit arithmetic allowed.

---

## Key Idea
Rebuild the number digit by digit using integer math:

1. **Pop** the last digit: `d = x % 10`  
2. **Shrink** the source: `x /= 10`  
3. **Check overflow** before adding: ensure `rev * 10 + d` stays in 32-bit range  
4. **Push**: `rev = rev * 10 + d`  
5. Repeat until `x == 0`

---

## Overflow Guard
With `rev` as the partial result and `d` the next digit:

* If `rev > INT_MAX/10`, adding another digit would overflow → **return 0**  
* If `rev == INT_MAX/10`, only `d <= 7` is safe (`INT_MAX` ends with …3647)  
* If `rev < INT_MIN/10`, adding another digit would underflow → **return 0**  
* If `rev == INT_MIN/10`, only `d >= -8` is safe (`INT_MIN` ends with …3648)

These checks keep everything within 32-bit without any 64-bit arithmetic.

---

No special handling needed for negative integers:

* `%` keeps the sign of the dividend (`-123 % 10 == -3`)  
* `/` truncates toward zero (`-123 / 10 == -12`)  

Digits stay negative, so the final result naturally preserves the original sign.

`INT_MAX / 10` looks like a runtime division, but the compiler **evaluates it at compile time**.  
With normal optimization flags, writing it inline is as efficient as precomputing a constant.

---

## Complexity
* **Time:** `O(log10 |x|)` — one iteration per digit  
* **Space:** `O(1)` — constant extra memory
