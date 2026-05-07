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
        if(!head||!head->next||k==0)
            return head;

        int len=1;
        ListNode* tail=head;
        while(tail->next){
            tail=tail->next; len++;
        }

        k%=len;
        if(k==0) return head;

        tail->next=head; // circular

        int steps=len-k;
        ListNode* newtail=head;

        for(int i=1;i<steps;i++)
            newtail=newtail->next;

        ListNode* newhead=newtail->next;
        newtail->next=NULL; // break

        return newhead;
    }
};

// Build a linked list from a vector
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]); // First link
    ListNode* cur = head;

    for (int i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// Print a linked list
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

// Free a linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;

    // Example 1: head = [1,2,3,4,5], k = 2 → expected [4,5,1,2,3]
    ListNode* list1 = buildList({1, 2, 3, 4, 5});
    cout << "Example 1 input:  "; printList(list1);
    ListNode* result1 = sol.rotateRight(list1, 2);
    cout << "Example 1 output: "; printList(result1);
    freeList(result1);

    cout << endl;

    // Example 2: head = [0,1,2], k = 4 → expected [2,0,1]
    ListNode* list2 = buildList({0, 1, 2});
    cout << "Example 2 input:  "; printList(list2);
    ListNode* result2 = sol.rotateRight(list2, 4);
    cout << "Example 2 output: "; printList(result2);
    freeList(result2);

    return 0;
}