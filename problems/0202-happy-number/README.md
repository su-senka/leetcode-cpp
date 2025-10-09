# LC-202: Happy Number (C++)

**Difficulty:** Easy

**Tags:** math, hashing, two-pointers, simulation

**Link:** [https://leetcode.com/problems/happy-number/](https://leetcode.com/problems/happy-number/)

---

## Problem Summary

Starting with any positive integer `n`, repeatedly replace it by the **sum of the squares of its digits**.
If this process eventually reaches `1`, the number is *happy*; otherwise, it falls into a repeating cycle and is *unhappy*.
Return whether `n` is happy.

**Constraints (key ones):**

* 1 ≤ n ≤ 2³¹ − 1
* Process always terminates in either `1` or a cycle.

---

## Intuition

This behaves like a **linked list traversal**: each number leads deterministically to the next (`sum of squares of digits`).
If there’s a cycle that doesn’t include 1, the process will loop forever — exactly the same pattern as a linked list cycle.

---

## Approach

1. Define a helper `next(n)` that returns the sum of the squares of `n`’s digits.
2. Use two pointers (`slow`, `fast`):

   * `slow` moves one step → `slow = next(slow)`
   * `fast` moves two steps → `fast = next(next(fast))`
3. If `fast` becomes `1`, `n` is happy.
4. If `slow == fast` before reaching `1`, a cycle exists → not happy.

**Correctness (brief):**
The process is deterministic, so cycles and termination points behave exactly like linked list nodes.
Floyd’s algorithm guarantees we’ll detect a loop in O(1) space.

---

## Complexity

* **Time:** O(log n) per iteration — each step reduces the number’s magnitude; bounded small cycle size.
* **Space:** O(1) — only constant variables.
