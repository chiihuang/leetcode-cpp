class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        // cout << s<< endl;
        unordered_map<int, int> m;
        int i = 0, j = 0;
        for (i = 0; i < s; i++) {
            m[nums[i]] = i;
        }
        for (i = 0; i < s; i++) {
            if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i){
                // cout << target - nums[i] << endl;
                j = m[target - nums[i]];
                break;
            }
        }
        vector<int> ret(2);
        ret[0] = i;
        ret[1] = j;
        return ret;      
    }
};
