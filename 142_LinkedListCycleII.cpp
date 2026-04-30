#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* S = head;
        ListNode* F = head;

        while(F != nullptr && F->next != nullptr ){

            S = S->next;
            F = F->next->next;

            if(S == F){
                ListNode* temp = head;

                while(temp != S){
                    temp = temp->next;
                    S = S->next;
                }

                return temp;
            }
            
        }

        return nullptr;
    }
};

int main(){
    Solution sol;
    
    // Test Case 1: List with cycle
    ListNode *head1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    
    head1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // Cycle starts at node2
    
    ListNode *result1 = sol.detectCycle(head1);
    if(result1 != nullptr) {
        cout << "Test 1 - Cycle detected at node with value: " << result1->val << endl;
    } else {
        cout << "Test 1 - No cycle detected" << endl;
    }
    
    // Test Case 2: List without cycle
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    
    ListNode *result2 = sol.detectCycle(head2);
    if(result2 != nullptr) {
        cout << "Test 2 - Cycle detected at node with value: " << result2->val << endl;
    } else {
        cout << "Test 2 - No cycle detected" << endl;
    }
    
    // Test Case 3: Single node with cycle
    ListNode *head3 = new ListNode(1);
    head3->next = head3;  // Points to itself
    
    ListNode *result3 = sol.detectCycle(head3);
    if(result3 != nullptr) {
        cout << "Test 3 - Cycle detected at node with value: " << result3->val << endl;
    } else {
        cout << "Test 3 - No cycle detected" << endl;
    }
    
    return 0;
}