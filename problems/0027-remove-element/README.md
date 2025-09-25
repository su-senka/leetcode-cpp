# Remove Element – In-Place Array Filtering

Given:

* `vector<int> nums` – input array
* `int val` – value to remove

**Goal**

1. Move all elements *not equal* to `val` into the **front** of `nums`.
2. Return the count `k` of those remaining elements.
3. Anything beyond the first `k` positions can be ignored.

Time must be **O(n)** and extra space **O(1)**.

---

Use **two pointers**:

* `i` – reads every element.  
* `write` – next position to store a value we keep.

For each element:

```cpp
if (nums[i] != val)
    nums[write++] = nums[i];
