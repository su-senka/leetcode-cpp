# Best Time to Buy and Sell Stock

You are given an array `prices` where `prices[i]` represents the price of a stock on the i-th day.
You must choose one day to buy and a later day to sell to maximize profit.
Return the maximum profit that can be achieved.
If no profit is possible, return 0.

**Constraints**

* 1 ≤ prices.length ≤ 10⁵
* 0 ≤ prices[i] ≤ 10⁴

---

## Approach

1. Track the lowest price seen so far (`minPrice`).
2. For each day’s price:

   * Update `minPrice` if the current price is lower.
   * Calculate the profit if sold today (`price - minPrice`) and update `maxProfit` if it’s higher.
3. Return `maxProfit` after scanning all prices.

## Complexity

* **Time:** O(n) — single pass through the array.
* **Space:** O(1) — only two variables are used.
