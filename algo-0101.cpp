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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        deque<TreeNode*> q = { root->left, root->right };
        while(!q.empty()){
            auto left = q.front(); q.pop_front();
            auto right = q.back(); q.pop_back();
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val == right->val){
                q.push_front(left->right);
                q.push_front(left->left);
                q.push_back(right->left);
                q.push_back(right->right);
                continue;
            }
            return false;
        }
        return true;
    }
};
