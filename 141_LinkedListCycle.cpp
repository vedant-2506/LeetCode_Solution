#include<iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* F = head;
        ListNode* S = head;

        while(F!=NULL && F->next != NULL){
            F=F->next->next;
            S=S->next;

            if(F == S) return true;
        }

        return false;
        
    }
};

int main(){
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    Solution s;
    cout<<s.hasCycle(head)<<endl;

    return 0;
}