# Merge Two Sorted Linked Lists
https://github.com/su-senka/leetcode-cpp/tree/main/problems/0022-merge-two-sorted-lists
**Goal**  
Combine two already-sorted singly linked lists into one sorted list by reusing the existing nodes.

**Approach**  
Keep a pointer on each list.  
Always attach the smaller current node to the result and move that list’s pointer forward.  
When one list ends, link the remainder of the other list.

**Complexity**  
- **Time:** O(n + m) — every node is visited once  
- **Space:** O(1) — only a few pointers, no new nodes
