# LC-643: Maximum Average Subarray I

**Difficulty:** Easy

**Tags:** Arrays, Sliding Window

**Link:** [https://leetcode.com/problems/maximum-average-subarray-i/](https://leetcode.com/problems/maximum-average-subarray-i/)

---

## Problem Summary

You’re given an integer array `nums` and an integer `k`.
Find the contiguous subarray of length `k` that has the **maximum average value**, and return that average.
An answer within `1e-5` of the correct result is accepted.

**Constraints (key ones):**

* `1 ≤ k ≤ n ≤ 10⁵`
* `-10⁴ ≤ nums[i] ≤ 10⁴`
* The subarray length is fixed (`k`), ensuring a single pass solution is possible.

---

## Intuition

When all candidate subarrays are the same size, you only need to track their sums — not recompute each one.
A **fixed-size sliding window** perfectly fits this structure.

---

## Approach

1. Compute the sum of the first `k` elements — the initial window.
2. Slide the window one step at a time:

   * Add the incoming element (right end).
   * Subtract the outgoing element (left end).
3. Track the **maximum window sum** as you slide.
4. Divide the best sum by `k` to get the maximum average.

**Correctness (brief):**
Every contiguous segment of size `k` is considered exactly once.
Since each shift updates the sum in O(1), the algorithm always finds the max possible average efficiently.

---

## Complexity

* **Time:** O(n) — one pass through the array.
* **Space:** O(1) — constant auxiliary storage.
