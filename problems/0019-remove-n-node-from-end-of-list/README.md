# Remove Nth Node From End of List

Delete the **n-th node from the end** of a singly linked list in one pass.

## Problem
Given the head of a linked list and an integer `n`, remove the node that is `n`
places from the end and return the new head.

Constraints:
* `1 <= list length <= 10^5`
* `1 <= n <= list length`

## Approach
- Create a **dummy head** node pointing to the original head to simplify edge cases
  (e.g., deleting the first node).
- Use two pointers:
  1. **Fast** pointer advances `n + 1` steps ahead of the **slow** pointer.
  2. Move both pointers together until `fast` reaches the end.
- At this point, `slow` is **one node before** the target.
- Relink: `slow->next = slow->next->next` to remove the target node.

## Complexity
* **Time:** O(L) – every node is visited at most once, where L is the list length.
* **Space:** O(1) – only a few pointer variables are used.
