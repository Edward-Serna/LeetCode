# 3300. Minimum Element After Replacement With Digit Sum [Easy]
> You are given an integer array `nums`.\
> You replace each element in `nums` with the **sum** of its digits.\
> Return the minimum element in `nums` after all replacements.

## Example 1:
**Input:** `nums = [10,12,13,14]`\
**Output:** `1`\
**Explanation:** \
`nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.`

## Example 2:
**Input:** `nums = [1,2,3,4]`\
**Output:** `1`\
**Explanation:** \
`nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.`

## Example 3:
**Input:** `nums = [999,19,199]`\
**Output:** `10`\
**Explanation:** \
`nums becomes [27, 10, 19] after all replacements, with minimum element 10.`

## Constraints:
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 104`

## Note
> https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description
> 
> ### Intuition
> 
> For an element `x`, the sum of its digits `dig` can be calculated as follows:
> - Take the last digit of `x`, which is `x mod 10`, and add it to `dig`.
> - Remove the units digit of x by updating `x` to `⌊x/10⌋`. This causes the tens digit to become the units digit, the hundreds digit to become the tens digit, and so on.
> - Stop the process when `x` becomes `0`.
> After computing `dig` for each element, we can update the answer ans accordingly.
>
> Note that every element in `nums` is at most `10^4`, so we can initially set `ans` to a value greater than `36=4×9`.
 
### SOLUTION
```C++
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 37;
        for (int num : nums) {
            int dig = 0;
            while (num) {
                dig += num % 10;
                num /= 10;
            }
            ans = min(ans, dig);
        }
        return ans;
    }
};
```
### Complexity Analysis

**Time complexity:** `O(nlogD)`

**Space complexity:** `O(1)`