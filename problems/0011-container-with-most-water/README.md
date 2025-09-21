# Container With Most Water

Find two lines that, with the x-axis, hold the maximum water.

**Idea:**  
Use two pointers at the ends of the array.  
Compute area = (right − left) × min(height[left], height[right]).  
Move the pointer at the shorter line inward to seek a taller boundary.

**Complexity:**  
* **Time:** O(n) — each pointer moves at most once across the array.  
* **Space:** O(1) — only constant extra memory.
