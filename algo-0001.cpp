class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        int len = nums.size();
        const int MAX_VALUE = 50000;
        int hash[2 * MAX_VALUE] = {0};
        for(int i = 0; i < len; i++){
            // found
            if (hash[target - nums[i] + MAX_VALUE] != 0) {
                ret[0] = i;
                ret[1] = hash[target - nums[i] + MAX_VALUE] - 1;
            } else {
                hash[nums[i] + MAX_VALUE] = i + 1; // avoid skipping i=0
            }
        }
        return ret;      
    }
};
