#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        char startChar = ' ';
        int k = 0;
        if (grid.size() == 1  && grid[0].size() == 1) {
            return false;
        }
        if (grid.size() == 1  && grid[0].size()>1) {
            return false;
        }
        if (grid.size() > 1 && grid[0].size() == 1) {
            return false;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = k; j < grid.size(); j ++) {
                if (startChar == ' ') {     // Init
                    startChar = grid[i][j];
                    continue;
                }
                if (j == grid.size()-1) {   // End of row
                    k = j;
                    continue;
                }
                if (j<grid.size()-1 && grid[i][j+1] != startChar) { // Move Check Right
                    if (grid[i+1][j] != startChar) { // Move Check Down
                        return false;
                    }
                }

            }
        }
        return true;
    }
};

int main() {
    // vector<vector<char>> grid1 = {
    //     {'a', 'a', 'a', 'a'},
    //     {'a', 'b', 'b', 'a'},
    //     {'a', 'b', 'b', 'a'},
    //     {'a', 'a', 'a', 'a'}
    // };
    // Solution example1;
    // cout << example1.containsCycle(grid1) << endl;
    //
    // vector<vector<char>> grid2 = {
    //     {'c', 'c', 'c', 'a'},
    //     {'c', 'd', 'c', 'c'},
    //     {'c', 'c', 'c', 'c'},
    //     {'f', 'c', 'c', 'c'}
    // };
    // Solution example2;
    // cout << example2.containsCycle(grid2) << endl;
    //
    // vector<vector<char>> grid3 = {
    //     {'a', 'a', 'a'},
    //     {'a', 'b', 'b'},
    //     {'a', 'b', 'b'},
    //     {'a', 'a', 'a'}
    // };
    // Solution example3;
    // cout << example3.containsCycle(grid3) << endl;

    vector<vector<char>> grid4 = {
        {'a', 'a'}
    };
    Solution example4;
    cout << example4.containsCycle(grid4) << endl;

    vector<vector<char>> grid5 = {
        {'b'}, {'b'}
    };
    Solution example5;
    cout << example5.containsCycle(grid5);
}
