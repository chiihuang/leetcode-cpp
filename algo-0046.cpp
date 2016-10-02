class Solution {
public:
    void swap(int& a, int& b){
        auto t = a;
        a = b;
        b = t;
    }
    void dfs(vector<vector<int>>& ret, vector<int>& nums, int start){
        if (start >= nums.size()) {
            ret.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            swap(nums[i], nums[start]);
            dfs(ret, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(ret, nums, 0);
        return ret;
    }
};
