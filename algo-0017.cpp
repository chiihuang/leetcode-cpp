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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        auto cur = head;
        auto preroot = new ListNode(-1);
        preroot->next = head;
        auto prev = preroot;
        auto skipped = 0;
        while(cur != NULL){
            cur = cur->next;
            if (skipped < n)
                skipped++;
            else {
                prev = prev->next;
            }
        }
        if (prev->next != NULL){
            prev->next = prev->next->next;
        }else
            prev->next = NULL;
        return preroot->next;
    }
};
