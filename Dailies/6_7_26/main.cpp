#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode { // Definition for a binary tree node.
    int val;  // Root
    TreeNode* left;  /* Ptr Left ← */   TreeNode* right; /* Ptr Right → */
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // Constructor with NO val
    TreeNode( int x ) : val(x), left(nullptr), right(nullptr) {} // Constructor WITH val
    TreeNode( int x, TreeNode* left, TreeNode* right ) : val(x), left(left), right(right) {} // Construct with val, left, right
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap; // Maps values to TreeNode pointers
        unordered_set<int> children; // Stores values which are children in the descriptions

        for (const auto& group : descriptions) { // Iterate through descriptions to create nodes/ setup tree structure
            // Extract parent value, child value, and whether it is a left child (1) or right child (0)
            int parentValue = group[0];
            int childValue = group[1];
            bool isLeft = group[2];

            // Create parent and child nodes if not already created
            if (!nodeMap.contains(parentValue)) nodeMap[parentValue] = new TreeNode(parentValue);
            if (!nodeMap.contains(childValue)) nodeMap[childValue] = new TreeNode(childValue);

            // Attach child node to parent's left or right branch
            if (isLeft) nodeMap[parentValue]->left = nodeMap[childValue];
            else nodeMap[parentValue]->right = nodeMap[childValue];

            children.insert(childValue);  // Mark child as a child in the set
        }

        for (auto& entry : nodeMap) {  // Find and return the root node
            auto& value = entry.first;
            auto& node = entry.second;
            if (!children.contains(value)) return node; // Root node found
        }

        return nullptr; // Should not occur, according to problem statement
    }
};

void printArray(const vector<vector<int>>& arr ) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << "[";
        for (int j=0; j<arr[i].size(); j++) {
            cout << arr[i][j];
            if (j == arr[i].size() - 1) cout << "";
            else cout << ",";
        }
        cout << "]";
        if (i == arr.size() - 1) cout << "";
        else cout << ", ";
    }
    cout << "]";
}

void printTreeVisual(TreeNode* root, string indent, bool isRight) {
    if (root == nullptr) return;

    // Process the right child first with an increased indentation
    printTreeVisual(root->right, indent + (isRight ? "     " : " |   "), true);

    // Print the current node data along with branches
    cout << indent;
    if (isRight) cout << " /-- ";
    else cout << " \\-- ";
    cout << root->val << "\n";

    // Process the left child with an increased indentation
    printTreeVisual(root->left, indent + (isRight ? " |   " : "     "), false);
}

int main() {
    Solution sol;

    // Example 1: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]] → expected: [50,20,80,15,17,19]
    vector<vector<int>> nums1 = {{20,15,1}, {20,17,0}, {50,20,1}, {50,80,0}, {80,19,1}};
    cout << "Input: "; printArray(nums1);
    TreeNode* ans1 = sol.createBinaryTree(nums1);
    cout << "\nOutput: \n";  printTreeVisual(ans1, "", true); cout<<endl<<endl;

    // Example 2: descriptions = [[1,2,1],[2,3,0],[3,4,1]] → expected: [1,2,null,null,3,4]
    vector<vector<int>> nums2 = {{1,2,1}, {2,3,0}, {3,4,1}};
    cout << "Input: "; printArray(nums2);
    TreeNode* ans2 = sol.createBinaryTree(nums2);
    cout << "\nOutput: \n";  printTreeVisual(ans2, "", true);

    return 0;
}
