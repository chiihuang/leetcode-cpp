class Solution {
public:
    void bt(vector<vector<int>>& ret, vector<int> nums, int start){
        if (start >= nums.size()){
            ret.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[start]) {
                swap(nums[i], nums[start]);
                bt(ret, nums, start + 1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        bt(ret, nums, 0);
        return ret;
    }
};
