# Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes’ values.

**Inorder traversal:** visit nodes in the order
**Left → Node → Right**

---

## Approach

The goal is to traverse the binary tree in inorder without using recursion.
A stack is used to simulate the recursive process manually:

1. Go as far left as possible, pushing nodes onto the stack.
2. When no more left nodes exist, pop from the stack — this node is next in order.
3. Move to the right subtree and repeat.

This ensures nodes are visited in the correct order.

---

## Complexity

* **Time:** O(n) — each node is processed once
* **Space:** O(n) — stack may hold up to n nodes in the worst case
