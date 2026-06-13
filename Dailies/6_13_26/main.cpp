#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (const string word : words) {
            int total_weight = 0;
            for (auto  c: word){
                total_weight += weights[c-97];
            }
            result += static_cast<char>(122-(total_weight%26));
        }
        return result;
    }
};

void printArray(const vector<string> &words, const vector<int>& weights) {
    cout << "Words: [";
    for (int i=0; i<words.size(); i++) {
        cout << words[i];
        if (i==words.size()-1) cout << "]\n";
        else cout << ",";
    }
    cout << "Weights: [";
    for (int i=0; i<weights.size(); i++) {
        cout << weights[i];
        if (i==weights.size()-1) cout << "]";
        else cout << ",";
    }
}

int main() {
    Solution sol;

    // Example 1:
    // words = ["abcd","def","xyz"],
    // weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2] → expected: "rij"
    vector<string> words1 = {"abcd","def","xyz"};
    vector<int> weights1 = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    printArray(words1, weights1);
    cout << "\nOutput: "<< sol.mapWordWeights(words1, weights1) <<endl<<endl;

    // Example 2:
    // words = ["a","b","c"],
    // weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1] → expected: "yyy"
    vector<string> words2 = {"a","b","c"};
    vector<int> weights2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    printArray(words2, weights2);
    cout << "\nOutput: "<< sol.mapWordWeights(words2, weights2) <<endl<<endl;

    // Example 3:
    // words = ["abcd"],
    // weights = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5] → expected: "g"
    vector<string> words3 = {"abcd"};
    vector<int> weights3 = {7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5};
    printArray(words3, weights3);
    cout << "\nOutput: "<< sol.mapWordWeights(words3, weights3);

    return 0;
}
