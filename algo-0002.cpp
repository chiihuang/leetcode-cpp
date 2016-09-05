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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int reg = 0;
        ListNode* head = NULL;
        ListNode* cur = head;
        while(l1 != NULL || l2 != NULL){
            int sum = reg;
            if (l1 != NULL) sum += l1->val;
            if (l2 != NULL) sum += l2->val;
            int base = sum % 10;
            reg = sum / 10;
            if (cur == NULL) {
                cur = new ListNode(base);
                head = cur;
            } else {
                cur->next = new ListNode(base);
                cur = cur->next;
            }
            
            // iter
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (reg != 0) cur->next = new ListNode(reg);
        return head;
    }
};
