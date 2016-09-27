/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = NULL;
        ListNode* cur = ret;
        while(l1 != NULL || l2 != NULL) {
            auto & n = ((l2 == NULL) || ((l1 != NULL) && l1->val < l2->val))
                ? l1
                : l2;
            if (ret != NULL) {
                cur->next = new ListNode(n->val);
                cur = cur->next;
            } else {
                ret = new ListNode(n->val);
                cur = ret;
            }
            n = n->next;
        }
        return ret;
    }
};
