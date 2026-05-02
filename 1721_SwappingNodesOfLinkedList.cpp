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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* curr = head;
        for(int i=1; i<k; i++){
           curr = curr->next;
        }
        ListNode* a = curr;

        ListNode* b = head;
        while(curr->next != nullptr){
            curr = curr->next;
            b = b->next;
        }

       swap(a->val , b->val);

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

    int k = 2;
    ListNode* result = sol.swapNodes(head, k);

    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}