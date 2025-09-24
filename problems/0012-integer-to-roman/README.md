# Integer to Roman

Convert an integer in the range **1 – 3999** to its Roman numeral representation.

## Key Rules
- Symbols and values: **I 1, V 5, X 10, L 50, C 100, D 500, M 1000**.
- Only **I, X, C, M** can repeat, at most three times in a row.
- Subtractive pairs handle digits starting with 4 or 9:  
  **IV, IX, XL, XC, CD, CM**.

## Approach
Use a **greedy** method:
1. Prepare an ordered list of values and their symbols, including subtractive pairs.
2. Repeatedly take the largest value ≤ the remaining number,
   append its symbol, and subtract it.
3. Continue until the number reaches zero.

## Complexity
- **Time:** O(1) — fixed list of symbols, constant work.
- **Space:** O(1) — output string only.

Example:  
`3749 → "MMMDCCXLIX"` (3000 = MMM, 700 = DCC, 40 = XL, 9 = IX)
