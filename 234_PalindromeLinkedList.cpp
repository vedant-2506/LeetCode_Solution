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


ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* F =head;
        ListNode* S =head;

        while(F != nullptr && F->next != nullptr){
            S=S->next;
            F=F->next->next;
        }

        ListNode* right  = reverse(S);
        ListNode* left = head;

        while(right != nullptr ){
            if(right->val != left->val) return false;
            right = right->next;
            left = left->next;
        }

        return true;
        
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;
    bool result = sol.isPalindrome(head);
    std::cout << (result ? "True" : "False") << std::endl;

    return 0;
}