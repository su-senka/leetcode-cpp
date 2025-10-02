# Binary Tree Maximum Path Sum

* We need the maximum sum of values along *any path* in a binary tree.
* A path is any sequence of connected nodes, and it doesn’t have to include the root.
* Each node can appear at most once in a path.
  
### Key Insights

1. **Two perspectives at each node:**

   * **Upward Contribution:** the best path sum that *extends upward* from this node to its parent. This must choose at most one child.
   * **Through-Node Candidate:** the best path that *passes through* this node, possibly taking both children.

3. **Handling negatives:**

   * If a child path contributes a negative sum, it only lowers the total.
   * Safest approach: ignore negative contributions (treat them as zero).

4. **Traversal strategy:**

   * Use **post-order DFS**: compute left gain, right gain, then process the current node.
   * Maintain a **global maximum** as you visit each node.

Think of each node as a possible "bridge":

* **What can I pass upward?** One side only.
* **What’s the best if I stop here?** Both sides if they help.
