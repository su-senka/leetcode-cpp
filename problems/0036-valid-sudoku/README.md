# Validate a 9×9 Sudoku Board

Given a 9×9 grid:

* Each **row** must contain the digits `1–9` **without repetition**.
* Each **column** must contain the digits `1–9` **without repetition**.
* Each of the nine **3×3 sub-boxes** must contain the digits `1–9` **without repetition**.
* Empty cells are represented by `'.'` and can be ignored.

> **Note:** A board can be *valid* even if it is not *solvable*.

---

## Approach

1. **Track rows, columns, and boxes**  
   * `row[9][9]` – `row[r][d]` is true if digit `d` has been seen in row `r`.
   * `col[9][9]` – `col[c][d]` is true if digit `d` has been seen in column `c`.
   * `box[9][9]` – `box[b][d]` is true if digit `d` has been seen in 3×3 sub-box `b`.

2. **Map a cell to its box**
This yields an index from 0 to 8.

3. **Scan every cell once**  
* Skip if the cell is `'.'`.
* Convert the digit character to an integer index: `num = ch - '1'`.
* If the digit is already marked in the row, column, or box → **invalid**.
* Otherwise, mark it as seen.

---

## Complexity

* **Time:** O(81) → effectively O(1)  
* **Space:** 3 × 9 × 9 booleans ≈ 243 bytes.
