# String to Integer

Converts a string into a 32-bit signed integer following these exact rules:

1. **Whitespace** – Ignore all leading spaces.
2. **Sign** – Optional `+` or `-` determines positivity or negativity.
3. **Digits** – Read consecutive digits only; stop at first non-digit.
4. **Clamp** – If value exceeds 32-bit signed range (`[-2^31, 2^31-1]`), return `INT_MIN` or `INT_MAX`.

## Complexity
* **Time:** O(n) — single pass over the string.
* **Space:** O(1) — constant extra memory.

## Example
```cpp
Solution sol;
int x = sol.myAtoi("   -042");   // x == -42
int y = sol.myAtoi("1337c0d3");  // y == 1337
