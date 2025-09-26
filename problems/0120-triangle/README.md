# Minimum Path Sum in a Triangle

Given a triangle (row *i* has *i+1* elements), compute the **minimum path sum** from top to bottom. From `(r, j)` you may move to `(r+1, j)` or `(r+1, j+1)`.

## Approach

* Use **bottom-up dynamic programming**.
* Each cell’s best cost = its value + the **minimum** of its two children below.

## Complexity

* **Time:** `O(N)` where `N` is total elements (≈ `R(R+1)/2`).
* **Space:** `O(R)` with row compression; **O(1)** extra if done in place.
