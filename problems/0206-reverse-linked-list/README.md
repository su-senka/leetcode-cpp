# LC-206: Reverse Linked List 

**Difficulty:** Easy

**Tags:** linked-list, two-pointers, iteration, recursion

**Link:** [https://leetcode.com/problems/reverse-linked-list/](https://leetcode.com/problems/reverse-linked-list/)

---

## Problem Summary

Given the head of a singly linked list, reverse the list and return the new head.
Reversal means every node’s `next` pointer should point to its previous node instead of its next one.

**Constraints (key ones):**

* 0 ≤ n ≤ 5000
* -10⁴ ≤ Node.val ≤ 10⁴

---

## Intuition

You don’t need to create a new list — the structure already exists.
Each node just needs to **point backward** instead of forward.
By walking once through the list and flipping the `next` pointers, you can fully reverse it **in place**.

---

## Approach

1. Initialize three pointers:

   * `prev = nullptr` — new tail
   * `curr = head` — current node
   * `next` — temporary storage for `curr->next`
2. While `curr` exists:

   * Store `next = curr->next`
   * Reverse link: `curr->next = prev`
   * Advance both: `prev = curr`, `curr = next`
3. When `curr` reaches `nullptr`, `prev` is the new head.
4. Return `prev`.

**Correctness (brief):**
Each iteration preserves the already-reversed portion (`prev`) while moving the boundary one node forward, guaranteeing a full reversal without losing any nodes.

---

## Complexity

* **Time:** O(n) — each node visited once.
* **Space:** O(1) — only three pointers used.

