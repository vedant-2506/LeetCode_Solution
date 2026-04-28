#include<iostream>
#include<stack>

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
    ListNode* removeNodes(ListNode* head) {
    
        ListNode* curr = head;

        stack<ListNode*> stk;

        while(curr != nullptr){
            while(!stk.empty() && stk.top()->val  < curr->val){
                stk.pop();
            }
            stk.push(curr);
            curr = curr->next;
        } 

       ListNode* next = nullptr;
        while(!stk.empty()){
            stk.top()->next = next;  
            next = stk.top();
            stk.pop();
        }

        return next; 
    }
};

int main(){
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    Solution sol;
    ListNode* result = sol.removeNodes(head);

    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}