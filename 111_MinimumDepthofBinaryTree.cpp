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
    int minDepth(TreeNode* root) {

        if(root == nullptr) return 0;

        int rightside = minDepth(root->right);
        int leftside = minDepth(root->left);

        if(rightside == 0) return leftside +1;

        if(leftside == 0) return rightside +1;

        return min(leftside , rightside  )+1;
        
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout<<s.minDepth(root);
    cout<<endl;
    return  0;
}