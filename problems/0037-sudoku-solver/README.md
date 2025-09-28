# Sudoku Solver

Fill a 9×9 grid so that:

* **Rows**: Each digit `1–9` appears exactly once.  
* **Columns**: Each digit `1–9` appears exactly once.  
* **3×3 Boxes**: Each digit `1–9` appears exactly once.

Empty cells are `'.'`.  Input is guaranteed to have **one unique solution**.

---

## Key Optimizations

### 1. Bit Masks
* For each row, column, and box we keep a 9-bit mask.
* Bit `i` set ⇒ digit `(i+1)` is **still available**.
* Checking candidates is a single bitwise AND.

### 2. MRV Heuristic
* Always pick the empty cell with the fewest legal digits.
* Cuts the search tree drastically.

### 3. Early Exit
* Once the unique solution is found, unwind immediately.

---

## Algorithm Outline

1. **Initialize** masks:
   * `rows[9]`, `cols[9]`, `boxes[9]` start as `0b111111111` (all digits free).
   * For every filled cell, clear the corresponding digit from these masks.

2. **Backtrack**:
   * Select the empty cell with the fewest available digits.
   * Iterate through each candidate bit:
     * Place digit.
     * Update masks.
     * Recurse.
     * If dead end, undo.

3. **Stop** when no empty cells remain.

---

## Complexity

* **Time:** Worst-case exponential, but with MRV + bit masks typical puzzles solve in milliseconds.  
* **Space:** O(1) extra—just a few arrays and the recursion stack.
