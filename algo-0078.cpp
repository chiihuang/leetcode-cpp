class Solution {
public:
    // sol 1: iterative
    vector<vector<int>> subsets_sol1(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back({});
        for(auto n : nums){
            auto len = ret.size();
            for(int i = 0; i < len; i++){
                ret.push_back(ret[i]);
                ret.back().push_back(n);
            }
        }
        return ret;
    }
    // sol 2.1: recursion ver 1
    vector<vector<int>> recur_1(vector<int>& nums, int start){
        int len = nums.size();
        if (len <= 0 || start >= len) return {{}};
        vector<vector<int>> ret;
        auto subret = recur_1(nums, start + 1);
        for(auto sub : subret){
            ret.push_back(sub);
            sub.push_back(nums[start]);
            ret.push_back(sub);
        }
        return ret;
    }
    // sol 2.2: backtracking
    void bt(vector<vector<int>>& ret, vector<int>& nums, int start, vector<int>& base){
        ret.push_back(base);
        
        int len = nums.size();
        for(int i = start; i < len; i++){
            base.push_back(nums[i]);
            bt(ret, nums, i + 1, base);
            base.pop_back();
        }
    }
    vector<vector<int>> recur_2(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> empty;
        bt(ret, nums, 0, empty);
        return ret;
    }
    // sol 3: bitwise
    
    vector<vector<int>> bitwise(vector<int>& nums){
        vector<vector<int>> ret;
        auto len = nums.size();
        auto comb_len = pow(2, len);
        for(auto i = 0; i < comb_len; i++){
            vector<int> elem;
            for(auto j = 0; j < len; j++){
                if ((i & 1 << j) > 0)
                    elem.push_back(nums[j]);
            }
            ret.push_back(elem);
        }
        return ret;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return bitwise(nums);
    }
};
