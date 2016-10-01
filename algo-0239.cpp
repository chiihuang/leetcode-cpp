class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto len = nums.size();
        vector<int> ret;
        deque<int> dq;
        
        if (len == 0 || k == 0) return ret;
        // init
        for(auto i = 0; i < k; i++){
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        ret.push_back(nums[dq.front()]);
        
        for(auto i = k; i < len; i++){
            if(i - dq.front() >= k) dq.pop_front();
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};
