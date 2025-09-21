# Regular Expression Matching

Determine if a text string `s` **fully matches** a pattern `p` that supports:
* `.` – matches **exactly one** character
* `*` – matches **zero or more** of the **preceding element** (the char or `.` before it)

The entire string must be matched—no partial matches.

## Examples
| s            | p            | Result | Reason                                              |
|--------------|--------------|--------|-----------------------------------------------------|
| `"aa"`       | `"a"`        | false  | pattern too short                                   |
| `"aa"`       | `"a*"`       | true   | `a*` can match two `a`                            |
| `"ab"`       | `".*"`       | true   | `.*` matches any string                              |
| `"aab"`      | `"c*a*b"`    | true   | `c*` = 0, `a*` = "aa", then `b`                      |

## Approach
Dynamic programming with memoized recursion:

* Let `dp[i][j]` mean: does `s[i:]` match `p[j:]`?
* At each `(i,j)`:
  * Check if current chars match (`p[j]` equals `s[i]` or `.`).
  * If next pattern char is `*`, either
    * **Skip** the pair (`x*`) → `dp[i][j+2]`, or
    * **Use** one occurrence if current matches → `dp[i+1][j]`.
  * Otherwise, consume one char from both → `dp[i+1][j+1]`.

## Complexity
- **Time:** `O(n * m)` — where `n` is the length of `s` and `m` is the length of `p`.
- **Space:** `O(n * m)` for the memoization table.
