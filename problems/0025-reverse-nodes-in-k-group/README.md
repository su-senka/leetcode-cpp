# Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes in groups of size `k`.
If the number of nodes is not a multiple of `k`, the remaining nodes at the end remain in their original order.
Only node links may be changed—node values cannot be modified.

**Constraints**

* 1 ≤ k ≤ n ≤ 5000
* 0 ≤ Node.val ≤ 1000
* Follow-up: Achieve O(1) extra memory.

---

## Approach

1. Use a dummy node before the list head to simplify pointer handling.
2. For each group of size `k`:

   * Check that `k` nodes remain.
   * Reverse the group in place using pointer manipulation.
   * Reconnect the reversed group to the rest of the list.
3. Stop when fewer than `k` nodes remain.

## Complexity

* **Time:** O(n) — each node is visited and reversed once.
* **Space:** O(1) — only a few pointers are used.
