# 1306. Jump Game III [Medium]
> Given an array of non-negative integers `arr`, you are initially positioned at `start` index of the array. When you are at index `i`, you can jump to `i + arr[i]` or `i - arr[i]`, check if you can reach any index with value 0.
> 
> Notice that you can not jump outside of the array at any time.

## Example 1:
**Input:** `arr = [4,2,3,0,3,1,2], start = 5`\
**Output:** `true`\
**Explanation:** \
`All possible ways to reach at index 3 with value 0 are:`\
`index 5 -> index 4 -> index 1 -> index 3`\
`index 5 -> index 6 -> index 4 -> index 1 -> index 3`

## Example 2:
**Input:** `arr = [4,2,3,0,3,1,2], start = 0`\
**Output:** `true`\
**Explanation:** \
`One possible way to reach at index 3 with value 0 is:`\
`index 0 -> index 4 -> index 1 -> index 3`

## Example 3:
**Input:** `arr = [3,0,2,1,2], start = 2`\
**Output:** `false`\
**Explanation:** \
`There is no way to reach at index 1 with value 0.`

## Constraints:
- `1 <= arr.length <= 5 * 104`
- `0 <= arr[i] < arr.length`
- `0 <= start < arr.length`

# Note
> https://leetcode.com/problems/jump-game-iii

**SOLUTION**
```C++
class Solution {
public:
    bool canReach(vector<int>& A, int cur) {
        if(cur < 0 || cur >= size(A) || A[cur] < 0) return false;                  // out of bounds OR already visited ? return false
        A[cur] *= -1;       // mark as visited by making -ve
        return !A[cur] || canReach(A, cur + A[cur]) || canReach(A, cur - A[cur]);  // return true if A[cur] == 0 or recurse for both possible jumps
    }
};
```
### Complexity Analysis

**Time complexity:** `O(N)`, where `N` is the number of elements in input array. Each element is only visited once.

**Space complexity:** `O(N)`, required for recursive stack. In worst case, the recursion depth is equal to `N` when every different elements are recursed one after another.
