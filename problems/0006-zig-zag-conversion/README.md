# Zigzag Conversion

Convert a string into its “zigzag” reading order across a given number of rows.

## Problem
Given a string `s` and an integer `numRows`, write the characters in a zigzag
pattern (down then diagonally up) and read line-by-line.

Constraints:
* `1 <= s.length <= 1000`
* `1 <= numRows <= 1000`

## Approach
- One full zigzag cycle length: `cycle = 2 * numRows - 2`.
- For each row `r`:
  - Add characters at indices `i = r + k*cycle`.
  - For middle rows (`0 < r < numRows-1`) also add the diagonal character  
    `j = i + cycle - 2*r` if in range.

## Complexity
* **Time:** O(n) – each character visited once.
* **Space:** O(1) extra – output string only.
