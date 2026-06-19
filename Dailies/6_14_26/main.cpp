#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode { // Definition for singly-linked list.
    int val; ListNode *next;
    ListNode() : val(0), next(nullptr) {} // Init[empty]
    ListNode(int x) : val(x), next(nullptr) {} // Init[Value]
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Init[Value, Link]
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head; // Jumps 1 step
        ListNode* fast = head; // Jumps 2 steps
        int maxVal = 0;

        while(fast && fast -> next) { // Get middle of linked list
            fast = fast -> next -> next; // Reaches end
            slow = slow -> next; // Reaches half-way to end
        }

        // Reverse second part of linked list
        ListNode *nextNode, *prev = nullptr;
        while(slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        while(prev) { // Get max sum of pairs
            maxVal = max(maxVal, head -> val + prev -> val);
            prev = prev -> next;
            head = head -> next;
        }
        return maxVal;
    }
};

ListNode* createLinkList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]); // Keeps head ptr available
    ListNode* curr = head; // Traversal ptr

    for (int i=1; i<nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;

    }
    return head; // Return first Link (Head)
}

void deleteList(const ListNode* head) {
    while (head) {
        const ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void printList(const ListNode* head) {
    while (head) {
        const ListNode* temp = head;
        cout<< temp->val;
        if (temp->next==nullptr) cout<<"]";
        else cout << ",";
        head = head->next;
    }
}

int main() {
    Solution sol;

    // Example 1: Input: head = [5,4,2,1] → expected: 6
    const vector<int> list1 = {5,4,2,1};
    ListNode *head1 = createLinkList(list1);
    cout << "Input: ["; printList(head1);
    cout << "\nOutput: "<< sol.pairSum(head1)<<endl<<endl;
    deleteList(head1);

    // Example 2: Input: head = [4,2,2,3] → expected: 7
    const vector<int> list2 = {4,2,2,3};
    ListNode *head2 = createLinkList(list2);
    cout << "Input: ["; printList(head2);
    cout << "\nOutput: "<< sol.pairSum(head2)<<endl<<endl;
    deleteList(head2);

    // Example 3: Input: head = [1,100000] → expected: 100001
    const vector<int> list3 = {1,100000};
    ListNode *head3 = createLinkList(list3);
    cout << "Input: ["; printList(head3);
    cout << "\nOutput: "<< sol.pairSum(head3);
    deleteList(head3);

    return 0;
}
