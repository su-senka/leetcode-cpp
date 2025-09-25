# Detect the Starting Node of a Linked-List Cycle (C++)

Determine **where** a cycle begins in a singly linked list, or return `nullptr` if no cycle exists.

Given `head` of a linked list:

* Return the node where the cycle starts.
* If there is no cycle, return `nullptr`.
* Extra memory must be **O(1)**.

---

## Key Idea – Floyd’s Two-Phase Algorithm

1. **Cycle Detection**  
   *Use two pointers:*  
   * `slow` moves 1 step.  
   * `fast` moves 2 steps.  
   * If `fast` reaches `nullptr` → **no cycle**.  
   * If `slow == fast` → a cycle exists. Stop there.

2. **Find Cycle Entry**  
   * Let `L` = distance from head to cycle start.  
   * Let `x` = distance from cycle start to meeting point.  
   * Pointer math shows `L = C - x` (where `C` is the cycle length).  
   * Reset one pointer to `head` and leave the other at the meeting point.  
   * Move both one step at a time → they meet at the **cycle start**.
