#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        // TC = O(h), SC = O(h)
        if (!root) return nullptr;

        if (root->val == val) return root;

        if (root->val > val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertBST(root->right, val);
    }

    return root;
}

int main() {
    TreeNode* root = nullptr;
    int n, value, target;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n < 0) {
        cout << "Number of nodes cannot be negative.\n";
        return 1;
    }

    cout << "Enter " << n << " values for the BST:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertBST(root, value);
    }

    cout << "Enter the value to search: ";
    cin >> target;

    Solution solution;
    TreeNode* result = solution.searchBST(root, target);

    if (result) {
        cout << "Value " << target << " found in the BST.\n";
    } else {
        cout << "Value " << target << " not found in the BST.\n";
    }

    return 0;
}
