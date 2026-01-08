/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

# define MAX_L 100

void postorder(struct TreeNode* root, int *length, int *ans){
    if(root == NULL) return;
    postorder(root->left, length, ans);
    postorder(root->right, length, ans);
    ans[*length] = root->val;
    (*length) = (*length) + 1;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = (int*)malloc(MAX_L*sizeof(int));
    int length = 0;
    postorder(root, &length, ans);
    (*returnSize) = length;
    return ans;
}