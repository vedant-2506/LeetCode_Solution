#include<iostream>
#include<unordered_set>

using namespace std;

  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> st;

        ListNode* curr = headA;
        while(curr!=NULL){
            st.insert(curr);
            curr=curr->next;
        }

        ListNode* temp = headB;
        while(temp != NULL ){
            if(st.find(temp) != st.end() ){
                return temp;
            }
            temp = temp->next;
        }

        return NULL;


        
    }
};

int main(){
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}