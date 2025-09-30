# N-Queens Solver

Place `n` queens on an `n x n` chessboard such that no two queens attack each other.  
Queens attack horizontally, vertically, and diagonally.

## Approach
- Use **backtracking (DFS)**: place queens row by row.
- Track attacked columns and diagonals using **bitmasks**:
  - `cols`: occupied columns
  - `diag (\)`: occupied descending diagonals
  - `anti (/ )`: occupied ascending diagonals
- At each row:
  - Compute available columns in O(1) with bit operations.
  - Place a queen, recurse to the next row, and backtrack.

## Complexity
- **Time Complexity:**  
  Exponential in nature (~O(n!)), since we explore permutations with pruning.  

- **Space Complexity:**  
  - O(n) recursion depth.  
  - O(n²) total to store board configurations in the result.  
  - O(1) extra for bitmask state.
  
