# Longest Univalue Path in a Binary Tree

* We need the **length of the longest path** in a binary tree where every node has the **same value**.
* The length is measured in **edges**, not nodes.
* The path does not have to pass through the root.

### Traversal Strategy

* Use **post-order DFS**: process children first, then compute values for the current node.
* At each step:

  1. Get left/right arms from children.
  2. If child matches parent’s value, extend arm by 1; otherwise reset to 0.
  3. Update global maximum with `leftArm + rightArm`.
  4. Return `max(leftArm, rightArm)` upward.

### Time & Space Complexity

* **Time:** **O(n)**
  You visit each node exactly once.

* **Space:** **O(h)** for the recursion stack
  Where **h** is the tree height.

  * **Balanced tree:** **O(log n)**
  * **Skewed tree:** **O(n)** (worst case)
