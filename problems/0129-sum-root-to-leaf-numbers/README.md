# Sum Root to Leaf Numbers

Given a binary tree where each node stores a digit (0–9), every root-to-leaf path forms a number by concatenating digits. The task is to return the **sum of all root-to-leaf numbers**. A leaf is a node with no children.

---

## Approach

* Traverse the tree (DFS or BFS).
* Carry a running number: `current = current * 10 + node.val`.
* When reaching a leaf, add `current` to the total.
* Sum across all paths.

---

## Complexity

* **Time:** O(n), since each node is visited once.
* **Space:** O(h), where h is tree height (O(log n) balanced, O(n) skewed, ≤ 10 by constraints).
