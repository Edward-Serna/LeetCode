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
    int removeDuplicates( vector<int>& nums ) {
        if (nums.empty()) return 0;

        int k = 1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != nums[k - 1]) {
                nums[k] = nums[j];
                k++;
            }
        }
        return k;
    }
};


int main() {
    vector<int> nums1 = {1, 1, 2};
    Solution example1;
    cout << "Removed: " << example1.removeDuplicates(nums1) << " results" << endl;
    for (auto i : nums1) {
        cout << i << " ";
    }

    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    Solution example2;
    cout << "Removed: " << example2.removeDuplicates(nums2) << " results" << endl;
    for (auto i : nums2) {
        cout << i << " ";
    }
}

//////////////////////////////
//   [Leet Code Solution]   //
//////////////////////////////
