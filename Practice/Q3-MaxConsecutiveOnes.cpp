//
// Created by serna on 5/31/2026.
//
// https://leetcode.com/problems/max-consecutive-ones
// [Solution can be found after Main]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = 0;
        for(int val:nums){
            if(val==0) count=0;
            else count++;
            if(count>=max) max = count;
        }
        return max;
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
    vector<int> nums1 = {1,0,1,1,0,1};
    cout << "Input:\n";
    printArray(nums1);
    cout << "Output:\n" << example1.findMaxConsecutiveOnes(nums1) << endl;

    return 0;
}

//////////////////////////////
//   [Leet Code Solution]   //
//////////////////////////////
//
//class Solution {
// public:
// int findMaxConsecutiveOnes(vector<int>& nums) {
//     int n = nums.size();
//     int ans = 0;
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         if (nums[i] == 1)
//             cnt++;
//         else
//             cnt = 0;
//
//         ans = max(ans, cnt);
//     }
//     return ans;
// }
// };