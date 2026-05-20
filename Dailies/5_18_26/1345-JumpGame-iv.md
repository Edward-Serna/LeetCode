# 1345. Jump Game IV [Hard]
> Given an array of integers `arr`, you are initially positioned at the first index of the array.
>
> In one step you can jump from index `i` to index:
> - `i + 1` where: `i + 1 < arr.length`.
> - `i - 1` where: `i - 1 >= 0`.
> - `j` where: `arr[i] == arr[j]` and `i != j`.
>
> Return _the minimum number of steps_ to reach the **last index** of the array.
>
> Notice that you can not jump outside of the array at any time.

## Example 1:
**Input:** `arr = [100,-23,-23,404,100,23,23,23,3,404]`\
**Output:** `3`\
**Explanation:** `You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.`

## Example 2:
**Input:** `arr = [7]`\
**Output:** `0`\
**Explanation:** `Start index is the last index. You do not need to jump.`

## Example 3:
**Input:** `arr = [7,6,9,6,9,6,9,7]`\
**Output:** `1`\
**Explanation:** `You can jump directly from index 0 to index 7 which is last index of the array.`

## Constraints:
- `1 <= arr.length <= 5 * 104`
- `-108 <= arr[i] <= 108`

# Note
> https://leetcode.com/problems/jump-game-iv/

**SOLUTION**
```C++
class Solution {
public:
    int steps(int i,
              vector<int>& nums,
              unordered_map<int, vector<int>>& mp,
              vector<int>& vis) {
        if (i >= nums.size() - 1) return 0;
        if (vis[i]) return INT_MAX;
        vis[i] = 1;
        int ans = INT_MAX;
        vector<int>& temp = mp[nums[i]];
        int next = steps(i + 1, nums, mp, vis);
        if (next != INT_MAX)
            ans = min(ans, 1 + next);
        if (i >= 1) {
            next = steps(i - 1, nums, mp, vis);
            if (next != INT_MAX)
                ans = min(ans, 1 + next);
        }
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] != i) {
                next = steps(temp[j], nums, mp, vis);
                if (next != INT_MAX)
                    ans = min(ans, 1 + next);
            }
        }
        vis[i] = 0;
        return ans;
    }

    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);
        vector<int> vis(arr.size(), 0);
        return steps(0, arr, mp, vis);
    }
};
```
### Complexity Analysis

**Time complexity:** `O(n)`

**Space complexity:** `O(n)`
