#include<iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return nullptr;


        ListNode* F = head;
        ListNode* S = head;
        ListNode* temp = nullptr;

        while(F != nullptr && F->next != nullptr) {
            F = F->next->next;
            temp = S;
            S = S->next;
        }

           
        temp->next = S->next;

        return head;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = sol.deleteMiddle(head);

    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}