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
    void maxDepth_Helper(TreeNode* root, int depth, int &max_depth){
        if(root == NULL) return;
        if(depth > max_depth) max_depth = depth;
        maxDepth_Helper(root->left, depth+1, max_depth);
        maxDepth_Helper(root->right, depth+1, max_depth);
    }
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        maxDepth_Helper(root, 0, max_depth);
        return (root == NULL)? 0 : max_depth + 1;
    }
};