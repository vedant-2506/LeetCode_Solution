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
    ListNode* swapPairs(ListNode* head) {     

        ListNode* temp = new ListNode();
        temp->next=head;
        ListNode* a = head;
        ListNode* result = temp;

        while(a != nullptr && a->next != nullptr){
            ListNode* b = a->next;
            ListNode* c = b->next;
           
           temp->next=b;
           b->next = a;
           a->next = c;
           temp = a;
           a = c; 
        }
        
        return result->next;
        
        
        
        // ListNode* a = head;

        // while(a != nullptr && a->next != nullptr ){
        //     swap(a->val , a->next->val);

        //     a=a->next->next;
        // }

     
        // return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution s;
    ListNode* result = s.swapPairs(head);

    while(result != nullptr){
        cout<<result->val<<" ";
        result=result->next;
    }

    cout<<endl;
}