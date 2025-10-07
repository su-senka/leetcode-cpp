# Add Binary

Given two binary strings `a` and `b`, return their sum as a binary string. Lengths up to 10⁴, digits are only `0/1`, no leading zeros (except `"0"`).

## Core idea

Do **grade-school addition in base 2** from right to left with a single **carry**.

## Complexity

* **Time:** `O(max(|a|, |b|))`
* **Space:** `O(max(|a|, |b|))` for the result buffer.
