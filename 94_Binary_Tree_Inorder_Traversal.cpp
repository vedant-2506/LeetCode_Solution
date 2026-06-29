#include<iostream>
#include<stack>
#include<vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        ////1st approch TC = O(n)  SC=O(n)
        // vector<int>ans;
        // Traves( root ,ans);
        // return ans; 

        //2nd approch using stack TC = O(n) SC = O(n)
        vector<int>ans;
        stack<TreeNode*>stk;
        TreeNode* curr = root;

        while(curr != nullptr || !stk.empty() ){

            while(curr != nullptr){
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            
            ans.push_back(curr->val);

            curr = curr->right;
        }

        return ans;
    }

    void Traves(TreeNode* root , vector<int>&ans){
        if(root == nullptr) return;

        Traves(root->left , ans);
        ans.push_back(root->val);

        Traves(root->right , ans);
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}