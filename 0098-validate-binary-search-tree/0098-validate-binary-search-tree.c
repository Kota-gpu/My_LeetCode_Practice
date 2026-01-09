/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_L 10000

void inorderTraversal(struct TreeNode* root, int *arr, int *parser){
    if(root == NULL) return;
    inorderTraversal(root->left, arr, parser);
    arr[*parser] = root->val;
    (*parser) = (*parser) + 1;
    inorderTraversal(root->right, arr, parser);
}

bool isValidBST(struct TreeNode* root) {
    int array[MAX_L];
    int parser = 0;
    inorderTraversal(root, array, &parser);
    for(int i=0; i<parser-1; i++){
        if(array[i] >= array[i+1]) return 0;
    }
    return 1;
}