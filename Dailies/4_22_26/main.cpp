#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for (const string& query : queries) {
            for (const string& word : dictionary) {
                int diffCount = 0;
                for (size_t i = 0; i < query.length(); ++i) {
                    if (query[i] != word[i]) {
                        ++diffCount;
                        if (diffCount > 2) {
                            break;
                        }
                    }
                }
                if (diffCount <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<string> queries1 {"word","note","ants","wood"};
    vector<string> dictionary1 {"wood","joke","moat"};
    Solution solution1;
    vector<string> result1 = solution1.twoEditWords(queries1, dictionary1);
    for (const string& word : result1)
    {
        cout << word << " ";
    }
    cout << endl;

    vector<string> queries2 {"yes"};
    vector<string> dictionary2 {"not"};
    Solution solution2;
    vector<string> result2 = solution2.twoEditWords(queries2, dictionary2);
    if (result2.size() == 0) {
        cout << "empty";
    }
    for (const string& word : result2)
    {
        cout << word << " ";
    }
}