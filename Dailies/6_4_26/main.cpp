#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wave = 0;
        while (num1!=num2+1) {
            vector<int> allDigits;
            int evalNum = num1;
            while (evalNum>0) {
                int right = 0;
                while (evalNum%10!=0) {
                    evalNum--;
                    right++;
                }
                allDigits.push_back(right);
                evalNum/=10;
            }

            int digitsLen = allDigits.size();
            if (digitsLen>2) {
                for (int i=0; i<digitsLen; i++) {
                    if (i==digitsLen-1||i==0) continue;
                    const bool isPeak = allDigits[i]>allDigits[i+1] && allDigits[i]>allDigits[i-1];
                    const bool isValley = allDigits[i]<allDigits[i+1] && allDigits[i]<allDigits[i-1];
                    if (isPeak || isValley)
                        wave++;
                }
            }
            num1++;
        }

        return wave;
    }
};

int main() {
    Solution sol;

    // Example 1: num1 = 120, num2 = 130 → expected: 3
    constexpr int num1_1 = 120; constexpr int num2_1 =  130;
    cout << "Input: " << num1_1 << ", " << num2_1 << endl;
    cout << "Output: " << sol.totalWaviness(num1_1, num2_1) <<endl<<endl;

    // Example 2: num1 = 198, num2 = 202 → expected: 3
    constexpr int num1_2 = 198; constexpr int num2_2 =  202;
    cout << "Input: " << num1_2 << ", " << num2_2 << endl;
    cout << "Output: " << sol.totalWaviness(num1_2, num2_2) <<endl<<endl;

    // Example 3: num1 = 4848, num2 = 4848 → expected: 2
    constexpr int num1_3 = 4848; constexpr int num2_3 =  4848;
    cout << "Input: " << num1_3 << ", " << num2_3 << endl;
    cout << "Output: " << sol.totalWaviness(num1_3, num2_3);

    return 0;
}
