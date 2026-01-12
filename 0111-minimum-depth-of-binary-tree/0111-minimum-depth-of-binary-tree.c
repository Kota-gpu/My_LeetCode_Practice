/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth_Helper(struct TreeNode* root, int depth){
    if(root->left == NULL && root->right == NULL) return depth;
    int left_level = -1;
    int right_level = -1;
    if(root->left != NULL) left_level = minDepth_Helper(root->left, depth + 1);
    if(root->right != NULL) right_level = minDepth_Helper(root->right, depth + 1);

    if(root->left == NULL) return right_level;
    if(root->right == NULL) return left_level;
    return (left_level < right_level)? left_level : right_level;
}

int minDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    return minDepth_Helper(root, 1);
}