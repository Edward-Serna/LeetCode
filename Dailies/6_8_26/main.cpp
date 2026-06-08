#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0;  int equal = 0;
        for (const int num : nums) { // Determine the count of values less & equal to pivot
            if (num < pivot) less++;
            else if (num == pivot) equal++;
        }

        vector<int> ans(nums.size());
        int lessIdx = 0; // Start idx for less
        int equalIdx = less; // Start idx for Equal
        int greaterIdx = less + equal; // Start idx for greater
        for (const int num : nums) { // Insert at locations
            if (num < pivot) {
                ans[lessIdx] = num;
                lessIdx++;
            } else if (num > pivot) {
                ans[greaterIdx] = num;
                greaterIdx++;
            } else {
                ans[equalIdx] = num;
                equalIdx++;
            }
        }
        return ans;
    }
};

void printArray(const vector<int> &arr) {
    cout << "[";
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i];
        if (i==arr.size()-1) cout << "";
        else cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1: nums = [9,12,5,10,14,3,10], pivot = 10 → expected: [9,5,3,10,10,12,14]
    vector<int> nums1 = {9,12,5,10,14,3,10};
    constexpr int pivot1 = 10;
    cout << "Input: "; printArray(nums1); cout << ", " << pivot1;
    cout << "\nOutput: "; printArray(sol.pivotArray(nums1, pivot1)); cout<<endl<<endl;

    // Example 2: nums = [-3,4,3,2], pivot = 2 → expected: [-3,2,4,3]
    vector<int> nums2 = {-3,4,3,2};
    constexpr int pivot2 = 2;
    cout << "Input: "; printArray(nums2); cout << ", " << pivot2;
    cout << "\nOutput: "; printArray(sol.pivotArray(nums2, pivot2));;

    return 0;
}
