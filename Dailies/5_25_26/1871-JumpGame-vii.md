# 1871. Jump Game VII [Medium]
> You are given a **0-indexed** binary string `s` and two integers `minJump` and `maxJump`. In the beginning, you are standing at index `0`, which is equal to `'0'`. You can move from index `i` to index `j` if the following conditions are fulfilled:
>
> - `i + minJump <= j <= min(i + maxJump, s.length - 1)`, and
> - `s[j] == '0'`.
>
> Return `true` _if you can reach index `s.length - 1` in `s`, or `false` otherwise_.

## Example 1:
**Input:** `s = "011010", minJump = 2, maxJump = 3`\
**Output:** `true`\
**Explanation:** \
`In the first step, move from index 0 to index 3.`\
`In the second step, move from index 3 to index 5.`

## Example 2:
**Input:** `s = "01101110", minJump = 2, maxJump = 3`\
**Output:** `false`

## Constraints:
- `2 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.
- `s[0] == '0'`
- `1 <= minJump <= maxJump < s.length`

# Note
> https://leetcode.com/problems/jump-game-vii/

**SOLUTION**
```C++
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n), pre(n);
        f[0] = 1;
        // since we start dynamic programming from i=minJump, we need to
        // precompute the prefix sums for the part [0, minJump)
        for (int i = 0; i < minJump; ++i) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; ++i) {
            int left = i - maxJump, right = i - minJump;
            if (s[i] == '0') {
                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
                f[i] = (total != 0);
            }
            pre[i] = pre[i - 1] + f[i];
        }
        return f[n - 1];
    }
};
```
### Complexity Analysis

**Time complexity:** `O(n)`

**Space complexity:** `O(n)`