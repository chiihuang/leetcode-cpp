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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        // init pq
        multimap<int, int> pq;
        ListNode* prehead = new ListNode(-1);
        auto cur = prehead;
        
        for(int i = 0; i < k; i++){
            if (lists[i] != NULL) {
                pq.insert(pair<int, int>(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        
        // if pq is not empty
        while(!pq.empty()){
            // pop one
            auto top = pq.begin();
            auto val = top->first;
            auto li = top->second;
            pq.erase(top);
            
            // append string
            cur->next= new ListNode(val);
            cur = cur->next;

            // fill pq
            if(lists[li] != NULL){
                pq.insert(pair<int, int>(lists[li]->val, li));
                lists[li] = lists[li]->next;
            }
        }
        
        // done
        return prehead->next;
    }
};
