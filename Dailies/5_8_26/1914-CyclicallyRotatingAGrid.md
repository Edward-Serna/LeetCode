# 1914. Cyclically Rotating a Grid [Medium]
> You are given an `m x n` integer matrix `grid`, where `m` and `n` are **both** even integers, and an integer `k`. 
> The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:\
![img.png](resources/img.png)\
A cyclic rotation of the matrix is done by cyclically rotating **each layer** in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the **counter-clockwise** direction. An example rotation is shown below:\
![img_1.png](resources/img_1.png)\
Return _the matrix after applying `k` cyclic rotations to it._

## Example 1:
![img_2.png](resources/img_2.png)\
**Input:** `grid = [[40,10],[30,20]], k = 1`\
**Output:** `[[10,20],[40,30]]`\
**Explanation:** `The figures above represent the grid at every state.`

## Example 2:
![img_3.png](resources/img_3.png) ![img_4.png](resources/img_4.png) ![img_5.png](resources/img_5.png)\
**Input:** `grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2`\
**Output:** `[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]`\
**Explanation:** `The figures above represent the grid at every state.`

## Constraints:
- `m == grid.length`
- `n == grid[i].length`
- `2 <= m, n <= 50`
- Both `m` and `n` are **even** integers.
- `1 <= grid[i][j] <= 5000`
- `1 <= k <= 10^9`

# Note
> https://leetcode.com/problems/cyclically-rotating-a-grid

**SOLUTION**
```C++

```
### Time Complexity Analysis
**Time complexity:** 

**Space complexity:**