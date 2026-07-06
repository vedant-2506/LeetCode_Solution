#include<iostream>

using namespace std;

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p == nullptr && q == nullptr) return true;

       if(p == nullptr || q == nullptr) return false;

       return (p->val == q->val &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }
};

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(p, q);
    cout << (result ? "The trees are the same." : "The trees are not the same.") << endl;

    // Clean up memory
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}