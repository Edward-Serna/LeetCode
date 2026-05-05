#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

    }
};

int main() {
    ListNode head = ListNode();
    vector<ListNode> list = {head};
    int k1 = 2;
    Solution example1;
    auto result1 = example1.rotateRight(list, k1);
}
