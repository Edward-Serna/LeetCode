//
// Created by serna on 5/31/2026.
//
// https://leetcode.com/problems/shuffle-the-array
// [Solution can be found after Main]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> x(nums.begin(), nums.begin()+n);
        vector<int> y(nums.begin()+n, nums.end());
        vector<int> ans(n*2);
        int idx = 0;
        for (int i=0; i<nums.size(); i+=2){
            ans[i] = x[idx];
            ans[i+1] = y[idx];
            idx++;
        }
        return ans;
    }
};

void printArray(const vector<int> &arr) {
    cout << "[ ";
    for (const auto val: arr)
        cout << val << " ";
    cout << "]" << endl;
}

int main() {
    Solution example1;
    vector<int> nums1 = {2,5,1,3,4,7};
    cout << "Input:\n";
    printArray(nums1);
    nums1 = example1.shuffle(nums1,3);
    cout << "Output:\n";
    printArray(nums1);

    return 0;
}

//////////////////////////////
//   [Leet Code Solution]   //
//////////////////////////////
/// class Solution {
// public:
// vector<int> shuffle(vector<int>& nums, int n) {
//     vector<int> ans(2 * n);
//     for (int i = 0; i < 2 * n; i++) {
//         if (i % 2 == 0) {
//             ans[i] = nums[i / 2];
//         } else {
//             ans[i] = nums[n + i / 2];
//         }
//     }
//     return ans;
// }
// };