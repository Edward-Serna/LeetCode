# 2161. Partition Array According to Given Pivot [Medium]
> You are given a **0-indexed** integer array `nums` and an integer `pivot`. Rearrange `nums` such that the following conditions are satisfied:
>  - Every element less than `pivot` appears **before** every element greater than `pivot`.
>  - Every element equal to `pivot` appears **in between** the elements less than and greater than `pivot`.
>  - The **relative order** of the elements less than `pivot` and the elements greater than `pivot` is maintained.
>    - More formally, consider every `pi`, `pj` where `pi` is the new position of the `ith` element and `pj` is the new position of the `jth` element. If `i < j` and **both** elements are smaller (_or larger_) than `pivot`, then `pi < pj`.
>
> Return `nums` _after the rearrangement_.

## Example 1:
**Input:** `nums = [9,12,5,10,14,3,10], pivot = 10`\
**Output:** `[9,5,3,10,10,12,14]`\
**Explanation:** 
```Markdown
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
```

## Example 2:
**Input:** `nums = [-3,4,3,2], pivot = 2`\
**Output:** `[-3,2,4,3]`\
**Explanation:**
```Markdown
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
```

## Constraints:
- `1 <= nums.length <= 10^5`
- `-10^6 <= nums[i] <= 10^6`
- `pivot` equals to an element of `nums`.

## Note
> https://leetcode.com/problems/partition-array-according-to-given-pivot
 
### SOLUTION [Approach 1: Dynamic Lists]
```markdown
Intuition
When we rearrange nums, we know that it is composed of three sections, from left to right:

The elements less than pivot.
The elements equal to pivot.
The elements greater than pivot.
Thus, one approach is to use dynamic lists to build each of the three sections. To do this, we can iterate through nums, left to right, and append each element into its corresponding dynamic list based on its comparison with pivot. This way, as we process each element, their relative position is maintained within their list. After iterating, we can stitch together the three lists to obtain the final rearranged result.

Algorithm
Declare three dynamic lists less, equal, and greater for all elements less than, equal to, and greater than pivot, respectively.
Iterate through each element num in nums:
If num < pivot: append num to less.
If num > pivot: append num to greater.
Else: append num to equal.
Stitch together the dynamic lists:
Append all elements of equal to less.
Append all elements of greater.
Return the resulting list.
```
```C++
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        list<int> less;
        list<int> equal;
        list<int> greater;

        for (auto num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num > pivot) {
                greater.push_back(num);
            } else {
                equal.push_back(num);
            }
        }

        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());

        vector<int> ans;
        for (auto num : less) {
            ans.push_back(num);
        }
        return ans;
    }
};
```
### Complexity Analysis

**Time complexity:** `O(N)`

**Space complexity:** `O(N)`