# 1752. Check if Array Is Sorted and Rotated [Easy]
> Given an array `nums`, return `true` _if the array was originally sorted in non-decreasing order, then rotated **some** number of positions (including zero)_. Otherwise, return `false`.
>
> There may be **duplicates** in the original array.
>
> **Note:** An array `A` rotated by `x` positions results in an array `B` of the same length such that `B[i] == A[(i+x) % A. length]` for every valid index `i`.

## Example 1:
**Input:** `nums = [3,4,5,1,2]`\
**Output:** `true`\
**Explanation:** `[1,2,3,4,5] is the original sorted array.`\
`You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].`

## Example 2:
**Input:** `nums = [2,1,3,4]`\
**Output:** `false`\
**Explanation:** `There is no sorted array once rotated that can make nums.`

## Example 3:
**Input:** `nums = [1,2,3]`\
**Output:** `true`\
**Explanation:** `[1,2,3] is the original sorted array.`\
`You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.`

## Constraints:
- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`

# Note
> https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

**SOLUTION**
```C++
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        // Construct the rotated array
        vector<int> checkSorted(n);

        // Iterate through all possible rotation offsets
        for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
            int currIndex = 0;
            for (int index = rotationOffset; index < n; ++index) {
                checkSorted[currIndex++] = nums[index];
            }
            for (int index = 0; index < rotationOffset; ++index) {
                checkSorted[currIndex++] = nums[index];
            }

            // Check if the constructed array is sorted
            bool isSorted = true;
            for (int index = 0; index < n - 1; ++index) {
                if (checkSorted[index] > checkSorted[index + 1]) {
                    isSorted = false;
                    break;
                }
            }

            // If sorted, return true
            if (isSorted) {
                return true;
            }
        }

        // If no rotation makes the array sorted, return false
        return false;
    }
};
```
### Complexity Analysis

**Time complexity:** `O(n^2)`

**Space complexity:** `O(n)`
