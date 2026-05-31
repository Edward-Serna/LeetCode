#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        if (asteroids.size()==1 && asteroids[0] <= mass) return true;
        long totalMass = mass;
        while (!asteroids.empty()) {
            bool change = false;
            for (int i = asteroids.size()-1; i>=0; i--) { // Traverse list
                if (totalMass>=asteroids[i] ) {
                    // if (totalMass >=INT_MAX)  return false;
                    totalMass+= asteroids[i];
                    asteroids.erase(asteroids.begin()+i);
                    change = true;
                }
            }
            if (!change ) return false;
        }
        return true;
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

    // Example 1: mass = 10, asteroids = [3,9,19,5,21] → expected: true
    int mass1 = 10;
    vector<int> nums1 = {3,9,19,5,21};
    cout << "Input: \n";
    printArray(nums1);
    cout << "Output: \n" << sol.asteroidsDestroyed(mass1, nums1) << endl << endl;

    // Example 2: mass = 5, asteroids = [4,9,23,4] → expected: false
    int mass2 = 5;
    vector<int> nums2 = {4,9,23,4};
    cout << "Input: \n";
    printArray(nums2);
    cout << "Output: \n" << sol.asteroidsDestroyed(mass2, nums2);


    return 0;
}
