# Remove Duplicates from Sorted Array

Given an integer array `nums` sorted in non-decreasing order, remove duplicates in-place so that each unique element appears only once. The relative order of elements must be preserved.
Return the number of unique elements, `k`.

After modification, the first `k` elements of `nums` should contain the unique values. The rest of the array beyond `k` is irrelevant.

**Constraints**

* 1 ≤ nums.length ≤ 3 * 10⁴
* -100 ≤ nums[i] ≤ 100
* nums is sorted in non-decreasing order

---

## Approach

1. Maintain a pointer `currentIndex` for the last unique element.
2. Traverse the array starting from index 1.
3. Each time a new unique value is found, increment `currentIndex` and overwrite `nums[currentIndex]` with that new value.
4. The unique portion of the array is `nums[0..currentIndex]`.
5. Return `currentIndex + 1` as the count of unique elements.

## Complexity

* **Time:** O(n) — single pass through the array.
* **Space:** O(1) — all operations done in-place.
