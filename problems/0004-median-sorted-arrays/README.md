# Median of Two Sorted Arrays

Given two sorted arrays `nums1` and `nums2`, find their median in **O(log (m+n))** time.

---

## Key Idea
Instead of merging the arrays, think of finding a **partition** of the combined data:

* All elements on the **left side** of the partition are ≤ all elements on the **right side**.
* The left side contains exactly half of the total elements.

If we can find such a cut, the median is either:
* the maximum of the left side (when the total length is odd), or
* the average of the max of the left side and the min of the right side (when the total length is even).

---

## Binary-Search Procedure
1. Let the smaller array be `A` (size `m`), the other `B` (size `n`).

2. We want to choose `i` elements from `A` and `j` from `B` so that  
   `i + j = (m + n + 1) / 2`  (left side size).

3. Use binary search on `i` in `[0, m]`. For each `i`, compute `j = totalLeft - i`.

4. Let:
   * `Aleft  = i > 0 ? A[i-1] : -∞`
   * `Aright = i < m ? A[i]   : +∞`
   * `Bleft  = j > 0 ? B[j-1] : -∞`
   * `Bright = j < n ? B[j]   : +∞`

5. We found the correct partition when:
   `Aleft <= Bright AND Bleft <= Aright`

6. If `Aleft > Bright`, move the binary search **left** (`hi = i - 1`). Else move **right** (`lo = i + 1`).

---

## Complexity
* **Time:** `O(log min(m, n))` — we only binary search the smaller array.  
* **Space:** `O(1)` — just a few variables.
