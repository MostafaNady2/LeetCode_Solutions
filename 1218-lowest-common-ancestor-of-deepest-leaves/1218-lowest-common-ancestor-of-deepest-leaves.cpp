/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int mx = 0;
    TreeNode* ans = nullptr;

public:
    int dfs(TreeNode* node, int depth) {
        if (node == nullptr) {
            return depth - 1;
        }
        int left = dfs(node->left, depth + 1);
        int right = dfs(node->right, depth + 1);
        mx = max(mx, max(left, right));
        if (left == right && left == mx) {
            ans = node;
        }
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};