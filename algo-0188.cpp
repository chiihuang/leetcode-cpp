class Solution {
public:
    int simpleMaxProfit(vector<int>& prices){
        int ret = 0, len = prices.size();
        for(int i = 0; i + 1 < len; i++){
            ret += max(prices[i + 1] - prices[i], 0);
        }
        return ret;
    }
    int part(vector<int>& nums, int start, int end){
        //if (end - start < 2) return end;
        int lo = start + 1, hi = end, target = nums[start];
        while(lo <= hi){
            if (nums[lo] < target && nums[hi] > target)
                swap(nums[lo++], nums[hi--]);
            if (nums[lo] >= target) lo++;
            else if (nums[hi] <= target) hi--;
        }
        swap(nums[hi], nums[start]);
        return hi;
    }
    void shuffle(vector<int>& nums){
        srand(time(NULL));
        int len = nums.size();
        for(int i = 0; i < len; i++){
            swap(nums[i], nums[rand() % len]);
        }
    }
    void kth(vector<int>& nums, int k){
        if (k <= 0 || k >= nums.size()) return;
        // shuffle(nums);
        int hi = nums.size() - 1, lo = 0;
        while(true){
            int pos = part(nums, lo, hi);
            if (pos == k - 1) break;
            else if (pos > k - 1) hi = pos - 1;
            else lo = pos + 1;
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (k > len / 2) return simpleMaxProfit(prices);
        int v = 0, p = 0;
        stack<pair<int, int>> vp_pairs;
        vector<int> profits;
        
        while(v < len){
            for(v = p; v + 1 < len && prices[v] >= prices[v + 1]; v++);
            for(p = v + 1; p + 1 < len && prices[p] <= prices[p + 1]; p++);
            if (v >= len || p >= len) break;
            while(!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]){
                profits.push_back(prices[vp_pairs.top().second] - prices[vp_pairs.top().first]);
                vp_pairs.pop();
            }
            while(!vp_pairs.empty() && prices[p] > prices[vp_pairs.top().second]){
                profits.push_back(prices[vp_pairs.top().second] - prices[v]);
                v = vp_pairs.top().first;
                vp_pairs.pop();
            }
            vp_pairs.push(make_pair(v, p));
        }
        
        while(!vp_pairs.empty()){
            profits.push_back(prices[vp_pairs.top().second] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        
        int ret = 0;
        kth(profits, k);
        for(int i = 0; i < k && i < profits.size(); i++)
            ret += profits[i];
        
        return ret;
    }
};
