# Search in Rotated Sorted Array

- Input:  
  - A rotated sorted array `nums` of unique integers.  
  - An integer `target`.  
- Output:  
  - The index of `target` if found, otherwise `-1`.

Even though the array is rotated, at any step of binary search:

* **One half is always sorted.**
* We can check if the target lies in the sorted half:

  * If yes → continue searching in that half.
  * If no → search the other half.

## Complexity

* **Time:** `O(log n)` — binary search halves the space each iteration.
* **Space:** `O(1)` — only pointers used.
