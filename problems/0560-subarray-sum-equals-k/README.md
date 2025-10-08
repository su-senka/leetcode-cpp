# Subarray Sum Equals K

Given an array of integers and a target `k`, count how many **contiguous subarrays** add up to `k`.
ecking every possible subarray (which is O(n²)), we use **prefix sums** to keep track of all possible starting points efficiently.

## Approach

As we move through the array:

1. Keep a running prefix sum.
2. Store how many times each prefix sum has appeared.
3. At each step, check if `(current_sum - k)` exists — every occurrence of that prefix marks a valid subarray ending here.

This transforms the problem into a single linear pass with a running frequency map of prefix sums.

## Complexity

* **Time:** O(n) — single scan
* **Space:** O(n) — prefix sum frequencies
