# Valid Parentheses

Determine whether a string of brackets is **valid**.  
A string is valid if:
1. Every opening bracket has a matching closing bracket of the same type.
2. Brackets close in the correct order.

## Key Insight
The bracket that closes **last** must match the bracket that opened **most recently**. That is exactly a **Last-In, First-Out (LIFO)** pattern → use a **stack**.

---

## Complexity
* **Time:** `O(n)` – each character is processed once.
* **Space:** `O(n)` – worst case all opening brackets are stacked.
