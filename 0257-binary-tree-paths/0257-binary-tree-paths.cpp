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
public:
    void visit(set<string>& v, string s, TreeNode* node, TreeNode* root) {
        if(node==NULL){
            return;
        }
        if (node != root) {
            s += '-';
            s += '>';
        }
        s += to_string(node->val);
        if (node->left == NULL && node->right == NULL) {
            v.insert(s);
            return;
        }
        visit(v, s, node->left,root);
        visit(v, s, node->right,root);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        set<string> v;
        string s;
        visit(v, s, root,root);
        return vector<string>(v.begin(),v.end());
    }
};