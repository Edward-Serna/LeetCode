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
// class Solution {
// public:
//     bool canReach(string s, int minJump, int maxJump) { // 48 = '0', 49 = '1'
//         auto const n = s.length(); // String Size (Ex1: 6)
//         bool allZero = true;
//         for (auto const c : s) {
//             if (c == '1') allZero = false;
//         }
//         if (allZero) return true;
//         int i = 0;  //// char move = s.at(1);
//         vector<int> q;
//
//         while (i<n) {
//             if (!q.empty()) {
//                 i = q.back();
//                 q.pop_back();
//             }
//             if (i == n-1) break;
//             const int left = i+minJump-1; // Determine start jump
//             int right = i+maxJump; // Determine end jump
//
//             while (right != left) { // Add gap to queue
//                 if (right<n && s.at(right)=='0') {
//                     q.push_back(right);
//                 }
//
//                 right--;
//             }
//
//             if (q.empty())
//                 return false;
//         }
//         return true;
//     }
// };

int main() {
    Solution sol;
    // Example 1: s = "011010", minJump = 2, maxJump = 3 → expected: true
    const string s1 = "011010";
    constexpr int minJump1 = 2;
    constexpr int maxJump1 = 3;
    cout << "Input: \n" << s1 << endl;
    cout << "Output: \n" << sol.canReach(s1, minJump1, maxJump1) << endl << endl;

    // Example 2: s = "011111000111000001011111010", minJump = 6, maxJump = 8 → expected: true
    // string s2 = "011111000111000001011111010";
    // int minJump2 = 6;
    // int maxJump2 = 8;
    // cout << "Input: \n" << s2 << endl;
    // cout << "Output: \n" << sol.canReach(s2, minJump2, maxJump2) << endl;

    // Example 3: s = "0000000000", minJump = 2, maxJump = 5 → expected: true
    // string s2 = "0000000000";
    // int minJump2 = 2;
    // int maxJump2 = 5;
    // cout << "Input: \n" << s2 << endl;
    // cout << "Output: \n" << sol.canReach(s2, minJump2, maxJump2) << endl;

    return 0;
}
