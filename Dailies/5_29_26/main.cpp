#include <iostream>
#include <vector>

using namespace std;

static int countDigits(int value) {
    int count = 0;
    while (value>0) { // Evaluate total digits
        value /= 10;
        count++;
    }
    return count;
}

class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> totalDigits(0);
        for (int value : nums) {
            float numOfDigits = countDigits(value);
            int sum = 0;
            while (numOfDigits!= 0) { // Evaluate all digits
                int digitCounter = 0;
                while (value>=pow(10,numOfDigits-1)) {// Evaluate Current digit
                    value -= pow(10,numOfDigits-1);
                    digitCounter++;
                }
                sum += digitCounter;
                numOfDigits--; // Move to next RIGHT digit
            }
            totalDigits.push_back(sum);
        }

        int min = totalDigits[0];
        for (const int d : totalDigits)
            if (d<min) min = d;

        return min;
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
    // Example 1: nums = [10,12,13,14] → expected: 1
    vector<int> nums1 = {10, 12, 13, 14};
    cout << "Input: \n";
    printArray(nums1);
    cout << "Output: \n" << sol.minElement(nums1) << endl << endl;

    // Example 2: nums = [1,2,3,4] → expected: 1
    vector<int> nums2 = {1,2,3,4};
    cout << "Input: \n";
    printArray(nums2);
    cout << "Output: \n" << sol.minElement(nums2) << endl << endl;

    // Example 3: nums = [999,19,199] → expected: 10
    vector<int> nums3 = {999,19,199};
    cout << "Input: \n";
    printArray(nums3);
    cout << "Output: \n" << sol.minElement(nums3);

    return 0;
}
