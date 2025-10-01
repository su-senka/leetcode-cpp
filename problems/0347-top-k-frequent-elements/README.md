# Top K Frequent Elements

Find the `k` most frequent elements in an array `nums`.
The answer is guaranteed to be unique, and you must do better than `O(n log n)`.

### Idea

1. **Count frequencies** of each element using a hash map.
2. **Create buckets** where `bucket[f]` holds all numbers appearing exactly `f` times.
3. **Collect results** by scanning buckets from highest frequency down until `k` elements are chosen.

### Complexity

* **Time:** `O(n)`

  * Count once, distribute once, scan once.
* **Space:** `O(n)`

  * Buckets + frequency map.

* Bucket sort avoids the `log n` overhead of heaps/sorting.
