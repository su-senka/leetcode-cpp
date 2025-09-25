# Find the Duplicate Number – Constant Space Solution (C++)

**Problem**  
Given an array `nums` of size `n + 1` where each integer is in the range `[1, n]` and exactly one integer is repeated at least once, return that duplicate **without**:

* Modifying the array
* Using more than **O(1)** extra space
* Exceeding **O(n)** time

---

## Key Insight – View as a Linked List

* Treat each **index** as a node.  
* The “next pointer” of node `i` is `nums[i]`.  
* Because all values are in `[1..n]`, following `nums[i]` always lands on a valid index, creating a directed graph of size `n + 1`.
* With `n + 1` nodes mapping into `n` possible next indices, the **pigeonhole principle** guarantees a **cycle**.
* The **entry node of the cycle** corresponds to the **duplicate number**.
