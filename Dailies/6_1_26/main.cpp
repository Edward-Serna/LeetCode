#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if (cost.size()==1) return cost[0];
        if (cost.size()==2) return cost[0] + cost[1];
        sort(cost.begin(), cost.end(), std::greater<int>());
        int minCost = 0;
        for (int i=0; i<cost.size(); i++) {
            if (i==cost.size()-1) {
                minCost +=cost[i];
            }
            else {
                minCost += cost[i] + cost[i+1];
            }
            i+=2;
        }
        return minCost;
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

    // Example 1: cost = [1,2,3] → expected: 5
    vector<int> nums1 = {1,2,3};
    cout << "Input: \n";
    printArray(nums1);
    cout << "Output: \n" << sol.minimumCost(nums1) << endl << endl;

    // Example 2: cost = [6,5,7,9,2,2] → expected: 23
    vector<int> nums2 = {6,5,7,9,2,2};
    cout << "Input: \n";
    printArray(nums2);
    cout << "Output: \n" << sol.minimumCost(nums2) << endl << endl;

    // Example 3: cost = [5,5] → expected: 10
    vector<int> nums3 = {5,5};
    cout << "Input: \n";
    printArray(nums3);
    cout << "Output: \n" << sol.minimumCost(nums3) << endl << endl;

    // Example 4: cost = [3,3,3,1] → expected: 7
    vector<int> nums4 = {3,3,3,1};
    cout << "Input: \n";
    printArray(nums4);
    cout << "Output: \n" << sol.minimumCost(nums4);

    return 0;
}
