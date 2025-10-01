# Largest Rectangle in a Histogram

Given bar heights (width=1), find the **max rectangle area** inside the histogram.
Example: `[2,1,5,6,2,3] → 10`.

## Idea

Use a **monotonic increasing stack of indices**. A shorter bar finalizes areas for taller bars to its left.

## Steps

1. Scan left→right, keep indices with **increasing heights** on the stack.
2. When current height is **lower** than the stack top:

   * Pop `mid`; its height is fixed.
   * **Right boundary** = current index `i`.
   * **Left boundary** = new stack top (or `-1` if empty).
   * **Width** = `i - left - 1`; update area.
3. Append a **sentinel 0** at the end to flush remaining bars.

## Complexity

* **Time:** O(n)
* **Space:** O(n)
  
