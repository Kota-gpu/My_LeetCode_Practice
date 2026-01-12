/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void hasPathSum_Helper(struct TreeNode* root, int sum, int target, bool *isTarget){
    sum = sum + root->val;
    if(root->left == NULL && root->right == NULL) {
        if(target == sum) *isTarget = true;
        return;
    }
    if(root->left !=NULL) hasPathSum_Helper(root->left, sum, target, isTarget);
    if(root->right !=NULL) hasPathSum_Helper(root->right, sum, target, isTarget);
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    bool isTarget = false;
    if(root == NULL) return false;
    hasPathSum_Helper(root, 0, targetSum, &isTarget);
    return isTarget;
}