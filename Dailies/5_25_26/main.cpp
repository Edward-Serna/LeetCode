#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const auto n = s.length();
        if (s.back() & 1) return false;
        vector<int> visited_idxs(n);
        visited_idxs[0] = 1; // Initialize
        vector<int> last(n);

        for(int i = 1; i < n; i++) {
            last[i] = last[i-1]; // Store idx we can jump back to if needed

            if(s[i] == '1') continue; // We cannot visit idx
            const int prevJump = i - minJump;

            if(prevJump >= 0 && last[prevJump] >= i - maxJump) { // Validation of idx
                visited_idxs[i] = true; // We visited that Idx
                last[i] = i; // Store idx in last vector
            }
        }
        return visited_idxs[n-1];
    }
};

int main() {
    Solution sol;
    // Example 1: s = "011010", minJump = 2, maxJump = 3 → expected: true
    const string s1 = "011010";
    constexpr int minJump1 = 2;
    constexpr int maxJump1 = 3;
    cout << "Input: \n" << s1 << endl;
    cout << "Output: \n" << sol.canReach(s1, minJump1, maxJump1) << endl << endl;

    // Example 2: s = "011111000111000001011111010", minJump = 6, maxJump = 8 → expected: true
    const string s2 = "011111000111000001011111010";
    constexpr int minJump2 = 6;
    constexpr int maxJump2 = 8;
    cout << "Input: \n" << s2 << endl;
    cout << "Output: \n" << sol.canReach(s2, minJump2, maxJump2) << endl;

    // Example 3: s = "0000000000", minJump = 2, maxJump = 5 → expected: true
    const string s3 = "0000000000";
    constexpr int minJump3 = 2;
    constexpr int maxJump3 = 5;
    cout << "Input: \n" << s3 << endl;
    cout << "Output: \n" << sol.canReach(s3, minJump3, maxJump3) << endl;

    return 0;
}
