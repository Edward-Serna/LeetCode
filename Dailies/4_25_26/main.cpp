#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxDistance( int side, vector<vector<int>>& points, int k ) {
        vector<int> MD_of_Points;
        int minVal = 0;
        for (auto i : points) {
            for (auto j : points) {
                if (i == j)
                    continue;
                int MD = abs(i[0] - j[0]) + abs(i[1] - j[1]);
                MD_of_Points.emplace_back(MD);
            }
        }

        for (auto i : MD_of_Points) {
            if (minVal == 0) {
                minVal = i;
            }
            else if (i < minVal) {
                minVal = i;
            }
        }
        return minVal;
    }
};

int main() {
    const int side1 = 2; // Side length
    vector<vector<int>> points1 = {{0, 2}, {2, 0}, {2, 2}, {0, 0}}; // 4-points of square (x,y)
    int k1 = 4;
    Solution example1;
    cout << example1.maxDistance(side1, points1, k1) << endl;

    int side2 = 2;
    vector<vector<int>> points2 = {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
    int k2 = 2;
    Solution example2;
    cout << example2.maxDistance(side2, points2, k2) << endl;

    int side3 = 2;
    vector<vector<int>> points3 = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
    int k3 = 5;
    Solution example3;
    cout << example3.maxDistance(side3, points3, k3);
}
