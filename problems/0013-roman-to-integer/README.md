# Roman to Integer

Convert a valid Roman numeral string to its integer value.

---

## Idea
Roman numerals are mostly additive, but six specific “subtractive” pairs
(`IV, IX, XL, XC, CD, CM`) mean **subtract** the smaller value that appears
before a larger one.

---

## Approach – Scan Right to Left
1. Map each symbol to its value.
2. Start from the **rightmost character**, keeping track of the **running total**
   and the **value of the previous (right) symbol**.
3. For each symbol:
   * If its value is **less than** the previous symbol’s value, **subtract** it.
   * Otherwise, **add** it and update the previous value.

---

## Complexity
* **Time:** `O(n)` — one pass over the string.
* **Space:** `O(1)` — fixed lookup table.
