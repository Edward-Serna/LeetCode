#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefixes;
        for (int val : arr1) {
            while (!arr1Prefixes.count(val) && val > 0) {
                arr1Prefixes.insert(val); // Insert the current value as a prefix
                val /= 10; // Generate the next shorter prefix by removing the last digit
            }
        }
        int longestPrefix = 0;
        // Step 2: Check each number in arr2 for the longest matching prefix
        for (int val : arr2) {
            while (!arr1Prefixes.count(val) && val > 0) {
                // Reduce val by removing the last digit if not found in the prefix set
                val /= 10;
            }
            if (val > 0) {

                // Length of the matched prefix using log10 to determine the number of digits
                longestPrefix = max(longestPrefix, static_cast<int>(log10(val) + 1));
            }
        }
        return longestPrefix;
    }
};

void printArray( const vector<int>& arr ) {
    cout << "[ ";
    for (const auto val : arr)
        cout << val << " ";
    cout << "]" << endl;
}

int main() {
    Solution sol;
    // Example 1: arr1 = [1,10,100], arr2 = [1000] → expected: 3
    vector A1 = {1,10,100};
    vector B1 = {1000};
    cout << "Input: \n";
    printArray(A1);
    printArray(B1);
    cout << "Output: \n" << sol.longestCommonPrefix(A1, B1) << endl;

    return 0;
}
