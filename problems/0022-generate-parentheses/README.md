# Generate Parentheses

Produce all well-formed strings of **n** pairs of parentheses.

## Idea
Build the string step-by-step with **backtracking**:
* You may add `'('` while `open < n`.
* You may add `')'` while `close < open`.
* When the string length is `2n`, record it.

The `push → recurse → pop` pattern lets one buffer explore every branch.

## Complexity
* **Results:** n-th Catalan number (e.g. n=8 → 1 430 strings).
* **Time:** Θ(Cₙ) – proportional to the output size.
* **Space:** O(n) recursion depth plus O(n) for the current path.
