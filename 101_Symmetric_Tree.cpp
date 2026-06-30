#include<iostream>
#include<stack>

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
    bool isSymmetric(TreeNode* root) {

    //     // DFS using 2 stack  Tc = O(n) Sc = O(n)
    //     if(root == nullptr) return true;

    //     stack<TreeNode* >lstk;
    //     stack<TreeNode* >rstk;

    //    lstk.push(root->left);
    //    rstk.push(root->right);

    //     while(!lstk.empty() && !rstk.empty()){
    //         TreeNode* left = lstk.top();
    //         lstk.pop();

    //         TreeNode* right = rstk.top();
    //         rstk.pop();

    //         if(left == nullptr && right == nullptr) continue;

    //         if(left == nullptr || right == nullptr) return false;

    //         if(left->val != right->val) return false;

    //         lstk.push(left->left);
    //         lstk.push(left->right);

    //         rstk.push(right->right);
    //         rstk.push(right->left);
    //     }
        
    //     return lstk.empty() && rstk.empty() ;

        // 2nd approch using mirror  TC = O(n) SC = O(n)

         return isMirror(root->left , root->right); 
    }

    bool isMirror(TreeNode* t1 , TreeNode* t2){
        if(!t1 && !t2) return true;

        if(!t1 || !t2 || t1->val != t2->val ) return false ;

        bool left = isMirror(t1->left , t2->right);
        bool right = isMirror(t1->right , t2->left);

        return left && right ;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);

    if(result){
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}