#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        const int len = nums.size();
        if (len == 1) return {0};
        vector<int> leftSum(len); vector<int> rightSum(len);
        int left = 0; int right = 0;
        for (int i=0; i<len; i++) {
            leftSum[i] = left;
            left += nums[i];

            rightSum[(len-1)-i] = right;
            right += nums[(len-1)-i];
        }

        vector<int> ans;
        for (int j=0; j<len; j++) {
            ans.push_back(abs(leftSum[j]-rightSum[j]));
        }

        return ans;
    }
};

void printArray(const vector<int> &arr) {
    cout << "[ ";
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i];
        if (i==arr.size()-1) cout << " ";
        else cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1: nums = [10,4,8,3] → expected: [15,1,11,22]
    vector<int> nums1 = {10,4,8,3};
    cout << "Input: \n"; printArray(nums1);
    cout << "\nOutput: \n"; printArray(sol.leftRightDifference(nums1));

    // Example 2: nums = [1] → expected: [0]
    vector<int> nums2 = {1};
    cout << "\n\nInput: \n"; printArray(nums2);
    cout << "\nOutput: \n"; printArray(sol.leftRightDifference(nums2));

    return 0;
}
