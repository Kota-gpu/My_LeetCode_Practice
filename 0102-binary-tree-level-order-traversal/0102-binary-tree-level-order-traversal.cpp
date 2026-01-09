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
    void levelOrder_Helper(vector<vector<int>> &levelOrder_arr, TreeNode* root, int depth) {
        if(root == NULL) return;
        if(depth >= levelOrder_arr.size()){
            levelOrder_arr.push_back({});
        }
        levelOrder_arr[depth].push_back(root->val);
        levelOrder_Helper(levelOrder_arr, root->left, depth+1);
        levelOrder_Helper(levelOrder_arr, root->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder_Helper(ans, root, 0);
        return ans;
    }
};