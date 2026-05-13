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
            cout << " " << setw(5) << grid[i][j] << " " ;
            if (j != grid[i].size()-1)
                cout << ",";
        }
        cout <<  "]" << endl;
    }
}

int main() {
    Solution sol;

    // Example 1: grid = [[40,10],[30,20]], k = 1 → expected [[10,20],[40,30]]
    vector<vector<int>> list1 =
        {{3970,1906,3608,298,3072,3546,1502,773,4388,3115,747,3937},
        {2822,304,4179,1780,1709,1058,3645,681,2910,2513,4357,1038},
        {4471,2443,218,550,2766,4780,1997,1672,4095,161,4645,3838},
        {2035,2350,3653,4127,3208,4717,4347,3452,1601,3725,3060,2270},
        {188,2278,81,3454,3204,1897,2862,4381,3704,2587,743,3832},
        {996,4499,66,2742,1761,1189,608,509,2344,3271,3076,108},
        {3274,2042,2157,3226,2938,3766,2610,4510,219,1276,3712,4143},
        {744,234,2159,4478,4161,4549,4214,4272,701,4376,3110,4896},
        {4431,1011,757,2690,83,3546,946,1122,2216,3944,2715,2842},
        {898,4087,703,4153,3297,2968,3268,4717,1922,2527,3139,1516},
        {1086,1090,302,1273,2292,234,3268,2284,4203,3838,2227,3651},
        {2055,4406,2278,3351,3217,2506,4525,233,3829,63,4470,3170},
        {3797,3276,1755,1727,1131,4108,3633,1835,1345,1293,2778,2805},
        {1215,84,282,2721,2360,2321,1435,2617,1202,2876,3420,3034}};
    cout << "\033[1mEXAMPLE 1\033[0m\nInput: \n";
    printGrid(list1);
    list1 = sol.rotateGrid(list1, 1);
    cout << "Output: \n";
    printGrid(list1);

    return 0;
}