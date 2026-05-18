#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector visited(arr.size(), false); // Each Idx NOT visited (false)
        queue<int> steps;

        steps.emplace(start);

        while (!steps.empty()){
            int i = steps.front(); // Grab front of step queue and set i (curr idx)
            steps.pop();

            if (i < 0 || i >= arr.size() || visited[i])
                continue;
            if (arr[i] == 0)
                return true;

            visited[i] = true;
            steps.push(i + arr[i]);
            steps.push(i - arr[i]);
        }

        return false;
    }
};


void printArray( const vector<int>& arr ) {
    for (const auto val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    Solution sol;
    // Example 1: arr = [4,2,3,0,3,1,2], start = 5 → expected: true
    vector arr1 = {4,2,3,0,3,1,2};
    const int start1 = 5;
    cout << "Input: \n";
    printArray(arr1);
    cout << "Output: \n" << sol.canReach(arr1, start1) << endl;

    // Example 2: arr = [4,2,3,0,3,1,2], start = 0 → expected: true
    vector arr2 = {4,2,3,0,3,1,2};
    const int start2 = 0;
    cout << "Input: \n";
    printArray(arr2);
    cout << "Output: \n" << sol.canReach(arr2, start2) << endl;

    // Example 3: arr = [3,0,2,1,2], start = 2 → expected: false
    vector arr3 = {3,0,2,1,2};
    const int start3 = 2;
    cout << "Input: \n";
    printArray(arr3);
    cout << "Output: \n" << sol.canReach(arr3, start3) << endl;

    // Example 4: arr = [4,2,3,0,3,1,2], start = 5 → expected: true
    vector arr4 = {4,2,3,0,3,1,2};
    const int start4 = 5;
    cout << "Input: \n";
    printArray(arr4);
    cout << "Output: \n" << sol.canReach(arr4, start4) << endl;

    // Example 5: arr = [0,3,0,6,3,3,4], start = 6 → expected: true
    vector arr5 = {0,3,0,6,3,3,4};
    const int start5 = 6;
    cout << "Input: \n";
    printArray(arr5);
    cout << "Output: \n" << sol.canReach(arr5, start5) << endl;

    // Example 6: arr = [4,4,1,3,0,3], start = 2 → expected: true
    vector arr6 = {4, 4, 1, 3, 0, 3};
    const int start6 = 2;
    cout << "Input: \n";
    printArray(arr6);
    cout << "Output: \n" << sol.canReach(arr6, start6);

    return 0;
}
