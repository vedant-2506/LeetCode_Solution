#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr){

            ListNode* temp = curr->next;

            if(curr->val == temp->val){
                curr->next = temp->next;
            }
            
            if(curr->val != temp->val){
            curr = curr->next;
            }
        }
        
        return head;
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    // Print the resulting list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}