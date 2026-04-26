#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int Left = 0, Right = 0, Blank = 0;
        for (auto c : moves){
            cout << c;
            if (c == 'R'){
                Right++;
            }
            else if(c == 'L'){
                Left++;
            }
            else
                Blank++;
        }
        cout << endl;
        return (abs(Left - Right) + Blank);
    }
};

int main()
{
    string moves1 = "L_RL__R";
    Solution example1;
    cout << example1.furthestDistanceFromOrigin(moves1) << endl;

    string moves2 = "_R__LL_";
    Solution example2;
    cout << example2.furthestDistanceFromOrigin(moves2) << endl;
    
    string moves3 = "_______";
    Solution example3;
    cout << example3.furthestDistanceFromOrigin(moves3);

    // string moves4 = "R_";
    // Solution example4;
    // cout << example4.furthestDistanceFromOrigin(moves4) << endl;
}