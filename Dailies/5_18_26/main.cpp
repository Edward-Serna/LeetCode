#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);

        vector<bool> visited(n);
        visited[0] = true;

        queue<int> q;
        q.push(0);

        int step = 0;
        while (!q.empty()) {
            for (int queueIdx = q.size(); queueIdx > 0; --queueIdx) {
                int i = q.front();
                q.pop();
                if (i == n - 1) return step; // Reached to last index

                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);

                for (auto const nextIdx : next) {
                    if (nextIdx >= 0 && nextIdx < n && !visited[nextIdx]) {
                        visited[nextIdx] = true;
                        q.push(nextIdx); // Visit this nextIdx later
                    }
                }
                // Clear the pending nextIdx locations from startIdx (Ex. negative Idx)
                next.clear(); // Avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
    }
};

void printArray( const vector<int>& arr ) {
    for (const auto val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    Solution sol;
    // Example 1: arr = [100,-23,-23,404,100,23,23,23,3,404] → expected: 3
    vector arr1 = {100,-23,-23,404,100,23,23,23,3,404};
    cout << "Input: \n";
    printArray(arr1);
    cout << "Output: \n" << sol.minJumps(arr1) << endl;

    // Example 2: arr = [7] → expected: 0
    vector arr2 = {7};
    cout << "Input: \n";
    printArray(arr2);
    cout << "Output: \n" << sol.minJumps(arr2) << endl;

    // Example 3: arr = [7,6,9,6,9,6,9,7] → expected: 1
    vector arr3 = {7,6,9,6,9,6,9,7};
    cout << "Input: \n";
    printArray(arr3);
    cout << "Output: \n" << sol.minJumps(arr3);

    return 0;
}
