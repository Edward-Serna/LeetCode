#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> eval;
        vector<int> C;
        for(int i=0; i<n; i++){
            eval.push_back(A[i]);
            eval.push_back(B[i]);
            sort(eval.begin(), eval.end());
            int count = 0;
            int x = eval[0];
            for(int j=1; j<eval.size(); j++){
                if(x == eval[j]){
                    count++;
                }
                else
                    x = eval[j];
            }
            C.push_back(count);
        }
        return C;
    }
};

void printArray( const vector<int>& arr ) {
    for (const auto val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    Solution sol;
    // Example 1: A = [1,3,2,4], B = [3,1,2,4] → expected: [0,2,3,4]
    vector A1 = {1,3,2,4};
    vector B1 = {3,1,2,4};
    cout << "Input: \n";
    printArray(A1);
    printArray(B1);

    vector C = sol.findThePrefixCommonArray(A1, B1);
    cout << "Output: \n";
    printArray(C);

    return 0;
}
