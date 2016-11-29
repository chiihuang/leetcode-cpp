/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int& inp, int& postp, TreeNode* end) {
        if (postp < 0) return nullptr;
        TreeNode* ret = new TreeNode(postorder[postp--]);
        if (inp >= 0 && inorder[inp] != ret->val){
            ret->right = buildTree(inorder, postorder, inp, postp, ret);
        }
        inp--;
        if (!end || (inp >= 0 && inorder[inp] != end->val)){
            ret->left = buildTree(inorder, postorder, inp, postp, end);
        }
        
        return ret;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inp = inorder.size() - 1, postp = inp;
        return buildTree(inorder, postorder, inp, postp, nullptr);
    }
};
