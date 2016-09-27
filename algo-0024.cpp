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
    void debug(ListNode* head){
        while(head != NULL){
            cout << head->val << endl;
            head = head->next;
        }
        return;
    }
    ListNode* swapPairs(ListNode* head) {
        auto prehead = new ListNode(-1);
        prehead->next = head;
        auto current = prehead;
        while(current->next != NULL && current->next->next != NULL){
            auto first = current->next;
            auto second = current->next->next;
            
            current->next = second;
            first->next = second->next;
            second->next = first;

            // go further
            current = current->next->next;
        }

        return prehead->next;
    }
};
