/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#define T TreeLinkNode
class Solution {
public:
    T* get_next(T*& parent, bool& left) {
        T* ret = nullptr;
        while(!ret && parent) {
            if (left) {
                ret = parent->right;
                left = false;
            } else {
                parent = parent->next;
                if (!parent) return ret;
                ret = parent->left;
                left = true;
            }
        }
        return ret;
    }
    void connect(TreeLinkNode *root) {
        T* cur = root;
        while(cur){
            bool left = true;
            T* n1 = cur->left ? cur->left : get_next(cur, left);
            T* n2 = get_next(cur, left);
            T* head = n1;
            while(n2) {
                n1->next = n2;
                n1 = n2;
                n2 = get_next(cur, left);
            }
            cur = head;
        }
    }
};
