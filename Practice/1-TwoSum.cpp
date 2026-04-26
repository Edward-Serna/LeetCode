//
// Created by serna on 4/25/2026.
//
// https://leetcode.com/problems/two-sum/
// [Solution can be found after Main]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum( vector<int>& nums, int target ) {
        vector<int> result;

        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    const int target1 = 9;
    Solution example1;
    vector solution1 = example1.twoSum(nums1, target1);
    for (auto i : solution1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> nums2 = {3, 2, 4};
    const int target2 = 6;
    Solution example2;
    vector solution2 = example2.twoSum(nums2, target2);
    for (auto i : solution2) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> nums3 = {3, 3};
    const int target3 = 6;
    Solution example3;
    vector solution3 = example3.twoSum(nums3, target3);
    for (auto i : solution3) {
        cout << i << " ";
    }
}

//////////////////////////////
//   [Leet Code Solution]   //
//////////////////////////////
// class Solution {
// public:
// vector<int> twoSum(vector<int> &nums, int target) {
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             if (nums[j] == target - nums[i]) {
//                 return {i, j};
//             }
//         }
//     }
//     // Return an empty vector if no solution is found
//     return {};
// }
// };