# First Missing Positive – O(n) / O(1)

Find the **smallest positive integer** not in an unsorted array.

---

## Idea
* Answer is always in **[1 … n+1]**.
* Use the array itself as a presence map:
  * Each index `i` represents number `i + 1`.
  * Flip the sign at `nums[i]` to mark that number as seen.

---

## Steps
1. **Check for 1** – if absent, return `1`.
2. **Sanitize** – replace values `<=0` or `> n` with `1`.
3. **Mark** – for each `v = abs(nums[i])` in `[1..n]`, set `nums[v-1]` negative.
4. **Scan** – first positive index `i` ⇒ answer `i + 1`; if none, return `n + 1`.
