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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 != nullptr && curr2 != nullptr ){
            if(curr1 -> val <= curr2->val ){
                temp->next= curr1;
                curr1 = curr1->next;
            }
            else{
                temp->next= curr2;
                curr2= curr2->next; 
            }    
            temp = temp->next;
        }

        if(curr1 != nullptr )temp->next = curr1;
        if(curr2 != nullptr )temp->next = curr2;

        return head->next;
    }
};

int main() {
    // Example usage:
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    ListNode* current = mergedList;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up memory (delete the lists)
    // Note: In a real application, you would want to properly manage memory.
    return 0;
}