#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        // Creates empty vector with the size of the nums vector
        vector<long long> result(n, 0); 
        for (int i = 0; i <= n-1;  i++){ 
            long long idxSum = 0;
            for (int j = 0; j <= n-1; j++){ 
                if (nums[i] == nums[j]){
                    idxSum += abs(i - j );
                }
            }
            result.at(i) = idxSum;
        }
        return result;
        
    }
};

int main()
{
    vector<int> nums1 = {1, 3, 1, 1, 2};
    Solution example1;
    vector<long long> result1 = example1.distance(nums1);
    for (long long dist : result1) 
        cout << dist << " ";
    
    cout << endl;
    
    vector<int> nums2 = {0, 5, 3};
    Solution example2;
    vector<long long> result2 = example2.distance(nums2);
    for (long long dist : result2) 
        cout << dist << " ";
}