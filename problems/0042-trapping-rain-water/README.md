# Trapping Rain Water – Key Points

**Goal:**  
Given an array of bar heights, find how many units of water are trapped after rain.

---

## Optimal Approach
* **Two pointers** start at both ends.
* Keep running maxima: `leftMax` and `rightMax`.
* Always move the side with the **lower current height** inward:
  * If left side is lower, water there is `leftMax - height[left]`.
  * Otherwise, water on the right is `rightMax - height[right]`.

Because the shorter side limits the water level, this one pass is enough.

---

## Complexity
* **Time:** O(n) – single sweep of the array.
* **Space:** O(1) – only a few variables.
