#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for (const int n : nums) {
            if (n < min) min = n;
        }
        return min;
    }
};

void printArray( const vector<int>& arr ) {
    for (const auto val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    Solution sol;
    // Example 1: nums = [nums = [1,3,5]] → expected: 1
    vector arr1 = {2, 6, 3};
    cout << "Input: \n";
    printArray(arr1);
    cout << "Output: \n" << sol.findMin(arr1) << endl;

    return 0;
}
