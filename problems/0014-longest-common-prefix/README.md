# Longest Common Prefix

Given an array of strings, return the longest common prefix. If there is no common prefix, return an empty string `""`.

---

## Approach – Min/Max Trick
The longest common prefix of the entire set equals the prefix shared by the
**lexicographically smallest** and **largest** strings.  
All other strings must fall between these two in order, so their shared prefix
cannot be shorter.

1. Find the lexicographically smallest and largest strings with
   `std::minmax_element`.
2. Compare those two strings character by character until they differ.
3. Return the substring up to the point of difference.

---

## Complexity
* **Time:** `O(k + n)`  
  *`n`* to find min and max, *`k`* to compare them,  
  where *`k`* is the length of the resulting prefix.
* **Space:** `O(1)` extra.
