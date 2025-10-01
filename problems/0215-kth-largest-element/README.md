# Find Kth Largest Element in an Array

Return the **kth largest element** in an array (not necessarily distinct), without sorting the whole array.

## Approach

Use a **min-heap** of size `k`:

* Push numbers into the heap.
* Remove the smallest when size > k.
* The top is the `k`th largest.

## Complexity

* **Time:** `O(n log k)`
* **Space:** `O(k)`
