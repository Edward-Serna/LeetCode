#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

    }
};

void printGrid (vector<vector<int>> grid) {
    for (int i = 0; i <= grid.size()-1; i++) {
        cout << "[";
        for (int j = 0; j<grid[0].size(); j++) {
            cout << "[" << grid[i][j] << "]" ;
            if (j != grid[i].size()-1)
                cout << ",";
        }
        cout <<  "]" << endl;
    }

}

int main() {
    Solution sol;

    // Example 1: grid = [[40,10],[30,20]], k = 1 → expected [[10,20],[40,30]]
    vector<vector<int>> list1 = {{40, 10}, {30, 20}};
    cout << "Example 1 input:  \n";
    printGrid(list1);
    vector<vector<int>> resultList1 = sol.rotateGrid(list1, 1);
    // cout << "Example 1 Output:  \n";
    // printGrid(list1);

    // cout << endl;
    return 0;
}