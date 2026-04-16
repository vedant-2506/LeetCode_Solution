#include <iostream>


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
    ListNode* middleNode(ListNode* head) {
       
        ListNode* f=head;
        ListNode* s=head;

        while(f != nullptr && f->next != nullptr ){
            s=s->next;
            f=f->next->next;
        }

        return s;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middle = s.middleNode(head);
    cout << "Middle node value: " << middle->val << endl;

    return 0;
}