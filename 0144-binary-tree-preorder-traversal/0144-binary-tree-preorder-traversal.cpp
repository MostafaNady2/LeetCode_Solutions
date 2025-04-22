/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void visit(vector<int>& v, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        v.push_back(node->val);
        visit(v, node->left);
        visit(v, node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        visit(v,root);
        return v;
    }
};