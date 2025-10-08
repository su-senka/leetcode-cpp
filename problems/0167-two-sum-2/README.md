# LC-167: Two Sum II – Input Array Is Sorted

**Difficulty:** Medium  
**Tags:** Arrays, Two-Pointers, Binary Search  
**Link:** https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

---

## Problem Summary

Given a **1-indexed, sorted** array of integers, find two numbers that add up to a specific target.
You must return their indices (1-based), ensuring each element is used at most once.
Exactly one valid pair exists. The solution must use **constant extra space**.

**Constraints:**

* 2 ≤ n ≤ 3×10⁴
* -1000 ≤ numbers[i], target ≤ 1000
* Array is sorted in non-decreasing order.
* Exactly one solution exists.

---

## Intuition

Because the array is sorted, increasing one pointer raises the sum while decreasing the other lowers it.
This predictable relationship makes the **two-pointer technique** ideal.

---

## Approach

1. Start one pointer at the beginning (`left`) and one at the end (`right`).
2. Compute the current sum of the two pointed elements.
3. If the sum matches the target, those are the indices.
4. If the sum is too small, move the left pointer right.
5. If the sum is too large, move the right pointer left.
6. Stop when the correct pair is found.

**Correctness:**
Because the array is sorted, moving pointers only discards impossible pairs — ensuring the correct one is found exactly once.

---

## Complexity

* **Time:** O(n) — Each element is considered at most once.
* **Space:** O(1) — Only two pointers are used, no extra structures.
