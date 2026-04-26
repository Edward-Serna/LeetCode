# 2615. Sum of Distances [Medium]
> You are given a **0-indexed** integer array `nums`. There exists an array `arr` of length `nums.length`, where `arr[i]` is the sum of `|i - j|` over all `j` such that `nums[j] == nums[i]` and `j != i`. If there is no such `j`, set `arr[i]` to be `0`.\
Return the array `arr`.

## Example 1:
**Input:** ``nums = [1,3,1,1,2] ``\
**Output:** ``[5,0,3,4,0]``\
**Explanation:**
```cpp
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2.
 ```
## Example 2:
**Input:** `nums = [0,5,3]`\
**Output:** `[0,0,0]`\
**Explanation:** 
```cpp
Since each element in nums is distinct, arr[i] = 0 for all i.
```

## Constraints:
```
1 <= nums.length <= 105
0 <= nums[i] <= 109
```

# Time Complexity
**Current complexity:** ``O(N^2)``\
**Suggested complexity:** ``O(N)``\
**Suggestions:** ``Group indices by value and use prefix sums to calculate distances in linear time instead of nested loops.``

## Note
> https://leetcode.com/problems/sum-of-distance

**SOLUTION**
```Cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        vector<long long> res(n);
        for (const auto& p : groups) {
            const auto& group = p.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefixTotal = 0;
            for (int i = 0; i < group.size(); i++) {
                res[group[i]] =
                    total - prefixTotal * 2 + group[i] * (2 * i - group.size());
                prefixTotal += group[i];
            }
        }
        return res;
    }
};
```