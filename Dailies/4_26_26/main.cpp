#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        char startChar = ' ';
        int k = 0;
        int m = grid.size();
        int n = grid[0].size();

        if ((m==1) && (n>1) || (n==1) && (m>1)) {
            return false;
        }
        if ((m==1) && (n==1)) {
            return false;
        }

        for (int i = 0; i < m; i++) {
            for (int j = k; j < n; j ++) {
                if (startChar == ' ') {     // Init
                    startChar = grid[i][j];
                    continue; // Move Right
                }

                // (Before End) == (Next Move Not Equal [startChar])
                if ((j<(n-1)) && (grid[i][j+1] != startChar)) { // Move Check Right
                    if (i<(n-1) && (grid[i+1][j] != startChar)) { // Move Check Down
                        if (grid[i][j+1] == startChar) { // If Below not != [startChar]
                            return false;
                        }
                        return false;
                    }
                    continue; // Move Right
                }
                if (j == (n-1)) {   // End of row
                    k = j;
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
    //
    // vector<vector<char>> grid4 = {
    //     {'a', 'a'}
    // };
    // Solution example4;
    // cout << example4.containsCycle(grid4) << endl;
    //
    // vector<vector<char>> grid5 = {
    //     {'b'}, {'b'}
    // };
    // Solution example5;
    // cout << example5.containsCycle(grid5) << endl;
    //
    // vector<vector<char>> grid6 = {
    //     {'b'}
    // };
    // Solution example6;
    // cout << example6.containsCycle(grid6) << endl;

    vector<vector<char>> grid7 = {
        {'f', 'a', 'a', 'c', 'b'},
        {'e', 'a', 'a', 'e', 'c'},
        {'c', 'f', 'b', 'b', 'b'},
        {'c', 'e', 'a', 'b', 'e'},
        {'f', 'e', 'f', 'b', 'f'}
    };
    Solution example7;
    cout << example7.containsCycle(grid7);
};
