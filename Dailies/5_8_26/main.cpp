#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int sizeH = grid[0].size();
        int sizeV = grid.size();
        if (sizeH == 1 || sizeV == 1) // Exit if row/ col == 1
            return grid;

        // Math for Count
        if (sizeH%2 || sizeV%2) { // Odd
            if (sizeH%2 == 1)
                sizeH = ((sizeH-1)/2);
            if (sizeV%2 == 1)
                sizeV = ((sizeV-1)/2);
        }
        else {
            sizeH = (sizeH/2);
            sizeV = (sizeV/2);
        }
        int loopCount = sizeV; // Determine loop count
        if (sizeH < sizeV)
            loopCount = sizeH;

        int startV = 0; int startH = 0;
        for (int l = 0; l < loopCount; l++) {
            for (int r = 0; r < k; r++) { // Rotations

                bool done = false;
                int i = startV; int j = startH;
                int mode = 0; int curr = 0; int prev = 0;
                while (!done) {
                    // cout << "curr: " << grid[i][j] << " ";
                    curr = grid[i][j]; // Save
                    grid[i][j] = prev;  // set
                    prev = curr; // save for next move

                    // cout << "change: " << grid[i][j] << endl;
                    if (i == grid.size()-1-startV && j == startH) // BL
                        mode ++;
                    else if (i == grid.size()-1-startV && j == grid[0].size()-1-startH) // BR
                        mode ++;
                    else if (i == startV && j == grid[0].size()-1-startH) // TR
                        mode ++;
                    else if (mode == 3 && i == startV && j == startH) // Start
                        done = true;
                    switch (mode) {
                    case (0): i++;  break;
                    case (1): j++;  break;
                    case (2): i--;  break;
                    case (3): j--;  break;
                    default: break;
                    }

                }
            }
            startH++;
            startV++;
        }
        return grid;
    }
};

void printGrid (vector<vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        cout << "[";
        for (int j = 0; j < grid[0].size(); j++) {
            cout << " " << setw(3) << grid[i][j] << " " ;
            if (j != grid[i].size()-1)
                cout << ",";
        }
        cout <<  "]" << endl;
    }
}

int main() {
    Solution sol;

    // Example 1: grid = [[40,10],[30,20]], k = 1 → expected [[10,20],[40,30]]
    vector<vector<int>> list1 = {{40,10,1,2}, {30,20,3,4}, {40,10,1,2}, {30,20,3,4}};
    cout << "\033[1mEXAMPLE 1\033[0m\nInput: \n";
    printGrid(list1);
    list1 = sol.rotateGrid(list1, 1);
    cout << "Output: \n";
    printGrid(list1);

    return 0;
}