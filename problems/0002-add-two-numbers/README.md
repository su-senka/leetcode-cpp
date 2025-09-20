# Add Two Numbers

Add two non-negative integers represented as reverse-order linked lists.  
Return the sum as a linked list.

## Solution
We walk both lists, adding corresponding digits plus a carry.  
If `l1` has a node, we **reuse it** by overwriting its value.  
If `l1` runs out first, we **splice** the remaining nodes from `l2` into the result and keep updating those.  
At the end, if there’s a leftover carry, append a new node.

**Why this works:** digit-wise addition with carry mirrors grade-school addition; reusing nodes preserves `O(1)` extra space while covering different-length lists.

## Complexity
- **Time:** `O(max(m, n))`
- **Space:** `O(1)` extra (mutates input lists)

## Notes
- This mutates `l1` (and possibly nodes from `l2` if spliced). If mutation is not desired, build a new list instead.
