#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> nums) {
        int const n = nums.size();
        if (n == 1) return true;
        int x = 0;
        while (x != nums.size()){
            for(int i=1; i<n; i++){
                if(nums[i-1]>nums[i]) break;
                if(i==n-1 && nums[i-1]<=nums[i]) return true;
            }
            int prev = nums[0];
            int curr = 0;
            for(int j=1; j<n; j++){
                if(j==n-1) nums[0] = nums[j];
                curr = nums[j];
                nums[j] = prev;
                prev = curr;
            }
            x++;
        }
        return false;
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
    // Example 1: nums = [3,4,5,1,2] → expected: true
    vector array1 = {3, 4, 5, 1, 2};
    cout << "Input: \n";
    printArray(array1);
    cout << "Output: \n" << sol.check(array1) << endl << endl;

    // Example 2: nums = [2,1,3,4] → expected: false
    vector array2 = {2, 1, 3, 4};
    cout << "Input: \n";
    printArray(array2);
    cout << "Output: \n" << sol.check(array2) << endl << endl;

    // Example 2: nums = [1,2,3] → expected: true
    vector array3 = {1, 2, 3};
    cout << "Input: \n";
    printArray(array3);
    cout << "Output: \n" << sol.check(array3);

    return 0;
}
