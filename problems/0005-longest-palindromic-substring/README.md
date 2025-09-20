# Manacher’s Algorithm

Find the **longest palindromic substring** in **O(n)** time.

## Core Idea
Transform the string so every palindrome has odd length:

`s = "babad" → t = "^#b#a#b#a#d#$"`

Maintain:
- `P[i]`: radius of palindrome centered at `i`
- `C`: center of the rightmost palindrome found
- `R`: its right boundary (exclusive)

## Key Step
For each position `i`:

`mirror = 2*C - i // symmetric index`

`if i < R: P[i] = min(R - i, P[mirror]) // reuse known radius`

`while t[i + 1 + P[i]] == t[i - 1 - P[i]]: P[i] += 1 // expand outward`


* **mirror** – index opposite `i` around `C`  
* **reuse** – start from the minimum guaranteed radius  
* **expand** – grow only beyond the known boundary

## Result
The index with the largest `P[i]` maps back to the original string and
gives the longest palindromic substring.
