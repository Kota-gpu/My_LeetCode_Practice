/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode NODE;
NODE* addNode(int num){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->val = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE* ToBST_helper(int down, int up, int *nums, NODE *root){
    if(up < down) return NULL;
    int mid = (up + down) / 2;
    root = addNode(nums[mid]);
    root->left = ToBST_helper(down, mid-1, nums, root->left);
    root->right = ToBST_helper(mid+1, up, nums, root->right);
    return root;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    NODE *root;
    root = ToBST_helper(0, numsSize-1, nums, root);
    return root;
}