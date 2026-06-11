#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        return 0;
    }
};

void printArray(const vector<vector<int>> &arr) {
    cout << "[";
    for (int i=0; i<arr.size(); i++) {
        cout << "{";
        for (int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j];
            if (j==arr[i].size()-1) cout << "";
            else cout << ",";
        }
        cout << "}";
        if (i==arr.size()-1) cout << "";
        else cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1: edges = [[1,2]] → expected: 1
    vector<vector<int>> nums1 = {{1,2}};
    cout << "Input: "; printArray(nums1);
    cout << "\nOutput: "<< sol.assignEdgeWeights(nums1) <<endl<<endl;

    // Example 2: edges = [[1,2],[1,3],[3,4],[3,5]] → expected: 2
    vector<vector<int>> nums2 = {{1,2}, {1,3}, {3,4}, {3,5}};
    cout << "Input: "; printArray(nums2);
    cout << "\nOutput: "<< sol.assignEdgeWeights(nums2) <<endl<<endl;

    return 0;
}
