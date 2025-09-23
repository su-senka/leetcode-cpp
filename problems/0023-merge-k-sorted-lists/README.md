# Merge k Sorted Lists

Merge `k` sorted linked lists into a single sorted linked list and return it.

---

## Approach 

1. **Heap Initialization**  
   Put the head node of every non-empty list into a min-heap keyed by node value.

2. **Repeated Extraction**  
   * Pop the smallest node from the heap and append it to the result list.  
   * If that node has a `next`, push the `next` node into the heap.

Because each list is individually sorted, the next node for the merged list must
always be the smallest among the current heads, and the heap provides that in
`O(log k)` time.

---

## Complexity
* **Time:** `O(N log k)`  
  *N* = total number of nodes across all lists,  
  *k* = number of input lists (heap size).
* **Space:** `O(k)` extra for the heap (the result reuses the original nodes).
