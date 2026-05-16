#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        for (int a : nums) {
            if (a >= n || a < n - 1 && count[a] > 0 || a == n - 1 && count[a] > 1)
                return false;
            count[a]++;
        }
        return true;
    }
};

void printArray( const vector<int>& arr ) {
    for (const auto val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    Solution sol;
    // Example 1: nums = [2, 1, 3] → expected: false [0]
    vector arr1 = {2, 6, 3};
    cout << "Input: \n";
    printArray(arr1);
    cout << "Output: \n" << sol.isGood(arr1) << endl;

    // Example 2: nums = [1, 3, 3, 2] → expected: true [1]
    vector arr2 = {1, 3, 3, 2};
    cout << "Input: \n";
    printArray(arr2);
    cout << "Output: \n" << sol.isGood(arr2) << endl;

    // Example 3: nums = [1, 1] → expected: true [1]
    vector arr3 = {1, 1};
    cout << "Input: \n";
    printArray(arr3);
    cout << "Output: \n" << sol.isGood(arr3) << endl;

    // Example 4: nums = [3, 4, 4, 1, 2, 1] → expected: false [0]
    vector arr4 = {3, 4, 4, 1, 2, 1};
    cout << "Input: \n";
    printArray(arr4);
    cout << "Output: \n" << sol.isGood(arr4) << endl;

    // Example 5: nums = [5, 7, 3, 1, 5, 2, 6, 4] → expected: false [0]
    vector arr5 = {5, 7, 3, 1, 5, 2, 6, 4, 0};
    cout << "Input: \n";
    printArray(arr5);
    cout << "Output: \n" << sol.isGood(arr5) << endl;
    return 0;
}
