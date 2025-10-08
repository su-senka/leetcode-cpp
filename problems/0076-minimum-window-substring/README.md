# LC-76: Minimum Window Substring

**Difficulty:** Hard

**Tags:** strings, sliding-window, two-pointers, hashing

**Link:** [https://leetcode.com/problems/minimum-window-substring/](https://leetcode.com/problems/minimum-window-substring/)

---

## Problem Summary

Given strings `s` (length m) and `t` (length n), return the shortest substring of `s` that contains every character of `t` **with multiplicity**. If none exists, return `""`. The answer is guaranteed unique for each testcase.

**Constraints (key ones):**

* 1 ≤ m, n ≤ 10⁵
* `s` and `t` contain uppercase/lowercase English letters
* Case-sensitive; duplicates in `t` must be matched in the window

---

## Intuition

A growing window can eventually cover all of `t`. Once it does, we should shrink from the left to make it minimal. Counts tell us when we’ve met each character’s quota.

---

## Approach

1. Build `need` counts from `t`, and track `required` distinct characters to satisfy.
2. Expand right pointer over `s`, updating `have` counts; when a char meets its quota, increment `formed`.
3. While `formed == required`, record the current window as a candidate, then shrink from the left by decrementing counts and moving the left pointer until the window becomes invalid.
4. Continue until the right pointer reaches the end; return the best recorded window or `""`.

**Correctness (brief):**
The window only shrinks when it already satisfies all requirements, ensuring any recorded window is valid. The first time shrinking breaks validity, we’ve passed the minimal left boundary for that right, so recording before shrinking captures the true minimum for that segment.

---

## Complexity

* **Time:** O(m + n) — one pass to build `need`, and each pointer moves forward at most `m` steps.
* **Space:** O(1) with fixed-size ASCII arrays (or O(k) for hashmap), where k is alphabet size in `t`.
