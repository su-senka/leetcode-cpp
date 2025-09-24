# Letter Combinations of a Phone Number

Generate all possible letter strings from a digit string (2–9) using the phone keypad mapping.

## Problem
Given a string `digits` (each char in `'2'..'9'`), return **all** letter combinations it can represent.  
If `digits` is empty, return `[]`.

Constraints:
* `0 <= digits.length <= 4`
* `digits[i] ∈ {'2','3','4','5','6','7','8','9'}`

## Approach
- Map digits to letters: `2→abc, 3→def, 4→ghi, 5→jkl, 6→mno, 7→pqrs, 8→tuv, 9→wxyz`.
- **Backtracking (DFS)** with a fixed-length buffer:
  - Maintain index `i` into `digits` and a mutable string `cur` of length `digits.size()`.
  - At each level, iterate over the letters for `digits[i]`, set `cur[i]` to each letter, recurse to `i+1`.
  - When `i == digits.size()`, append `cur` to results.
- Optimizations:
  - Precompute total result count and `reserve` that capacity in the vector.
  - Use in-place writes (`cur[i] = letter`) and store results with `emplace_back` to avoid extra copies.

## Complexity
* **Time:** Θ(3^n–4^n) — every combination must be generated (`n = digits.length`).
* **Space:** O(n) extra — recursion depth and the fixed-size working buffer (excluding the output vector).
