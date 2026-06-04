#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minVal = INT_MAX;
        int land_water = INT_MAX;  int water_land = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minVal = min(minVal, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < waterStartTime.size(); i++) {
            land_water = min(land_water, max(waterStartTime[i], minVal) + waterDuration[i]);
        }

        minVal = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            minVal = min(minVal, waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0; i < landStartTime.size(); i++) {
            water_land = min(water_land, max(landStartTime[i], minVal) + landDuration[i]);
        }
        return min(land_water, water_land);
    }
};

void printArray(const vector<int> &arr) {
    cout << "[ ";
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i];
        if (i==arr.size()-1) cout << " ";
        else cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1: landStartTime  = [2,8], landDuration = [4,1],
    //            waterStartTime = [6],   waterDuration = [9]   → expected: 9
    vector<int> landStartTime1  = {2,8}; vector<int> landDuration1  = {4,1};
    vector<int> waterStartTime1 = {6};   vector<int> waterDuration1 = {3};
    cout << "Input: \n";
    printArray(landStartTime1); printArray(waterStartTime1); cout<<endl;
    printArray(landDuration1);  printArray(waterDuration1);
    cout << "\nOutput: \n"
    << sol.earliestFinishTime(landStartTime1, landDuration1,
                             waterStartTime1, waterDuration1) <<endl<<endl;


    // Example 2: landStartTime = [41,59,14],  landDuration  = [8,74,45],
    //            waterStartTime = [41,78], waterDuration = [16,33]   → expected: 9
    vector<int> landStartTime3  = {41,59,14}; vector<int> landDuration3   = {8,74,45};
    vector<int> waterStartTime3 = {41,78}; vector<int> waterDuration3 = {16,33};
    cout << "Input: \n";
    printArray(landStartTime3); printArray(waterStartTime3); cout<<endl;
    printArray(landDuration3);  printArray(waterDuration3);
    cout << "\nOutput: \n"
    << sol.earliestFinishTime(landStartTime3, landDuration3,
                              waterStartTime3, waterDuration3);


    return 0;
}
