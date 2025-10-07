# Pow

Compute (x^n) for real `x` and integer `n`, including negative `n`. Constraints guarantee the result fits in a normal double range.

## Approach

Use **exponentiation by squaring** (binary exponentiation). It reduces work from (O(n)) to **(O(\log n))** by:

* Halving the exponent each step,
* Squaring the base each step,
* Multiplying into the answer only when the current exponent bit is 1.

## Complexity

* **Time:** (O(\log n)) multiplies
* **Space:** (O(1))
