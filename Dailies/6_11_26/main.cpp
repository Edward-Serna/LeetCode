#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    static int dfs(vector<vector<int>>& adj, const int node, const int par) {
        int depth = 0; // Initialize depth
        for (const auto &val : adj[node]) {
            if (val == par) continue;
            depth = max(depth, 1 + dfs(adj, val, node)); // Recursively travel through with new node start
        }
        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> weightedNodes(edges.size() + 2);
        for (auto &edge : edges) { // Assign weights for edges
            int top = edge[0];                      int bottom = edge[1];
            weightedNodes[top].push_back(bottom);   weightedNodes[bottom].push_back(top);
        }
        const int depth = dfs(weightedNodes, 1, -1); // Finds depth of graph
        int result = 1;
        for (int i = 1; i < depth; i++) { // Depth >= 1, Verification Phase
            result = (result * 2) % MOD;
        }
        return result;
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
    cout << "\nOutput: "<< sol.assignEdgeWeights(nums2);

    return 0;
}
