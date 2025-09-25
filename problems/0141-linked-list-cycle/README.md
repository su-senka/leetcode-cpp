# Detect Cycle in a Linked List – Quick Guide

Determine whether a singly linked list has a cycle.

---

## Problem
Given the head of a linked list, return **true** if there is a cycle  
(i.e. you can reach some node again by repeatedly following `next`),  
otherwise return **false**.

Constraints: up to 10⁴ nodes, O(1) extra memory preferred.

---

## Core Idea – Two-Pointer Method (Floyd)
* **slow** pointer: moves 1 step
* **fast** pointer: moves 2 steps
* Walk the list:
  * If `fast` or `fast->next` becomes `nullptr` → **no cycle**.
  * If at any point `slow == fast` → **cycle detected**.

### Complexity
* **Time:** O(n) – each node is visited at most a few times.
* **Space:** O(1) – only two pointers.

