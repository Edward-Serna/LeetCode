//
// Created by serna on 4/25/2026.
//
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// [Solution can be found after Main]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int idx = 1;

        for(int i=0; i<nums.size(); i++){
            if (nums[i] != nums[idx - 1]) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};

void printArray(const vector<int> &arr) {
    cout << "[ ";
    for (const auto val: arr)
        cout << val << " ";
    cout << "]" << endl;
}

int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 2};
    cout << "Input: \n";
    printArray(nums1);
    cout << "Output: " << sol.removeDuplicates(nums1)<< endl;
    printArray(nums1);
    cout << endl;

    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    cout << "Input: \n";
    printArray(nums2);
    cout << "Output: " << sol.removeDuplicates(nums2) << endl;
    printArray(nums2);

    return 0;
}

//////////////////////////////
//   [Leet Code Solution]   //
//////////////////////////////
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.size() == 0) return 0;
//         int res = 1;
//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i] != nums[i - 1]){
//                 nums[res] = nums[i];
//                 res++;
//             }
//         }
//         return res;
//     }
// };