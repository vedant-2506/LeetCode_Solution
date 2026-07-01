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
    bool hasPathSum(TreeNode* root, int targetSum) {
    //    //1st Taking sum of val TC = O(n)  Sc= O(h) worst case:O(n) , balence case:O(logn) 
    //     int sum=0;
    //     return Traves( root , targetSum , sum);

        //2nd substrcrt val from trgetSum 
        //TC = O(n)  Sc= O(h) worst case:O(n) , balence case:O(logn) 
        if(!root) return false;

        if(!root->left && !root->right) 
            return (targetSum == root->val);

        return hasPathSum(root->left , targetSum-root->val)   ||
               hasPathSum(root->right, targetSum-root->val);
    }

    bool Traves( TreeNode* root ,int targetSum ,int sum){
        if(root == nullptr) return false;
        sum += root->val;

        if(root->left == nullptr && root->right == nullptr ) return sum == targetSum;

        return Traves(root->left , targetSum , sum) || Traves(root->right , targetSum , sum) ;
    }

};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    bool result = s.hasPathSum(root, targetSum);

    cout << (result ? "true" : "false") << endl;

    return 0;
}