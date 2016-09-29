class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto len = nums.size();
        if (len <= 0) return 0;
        auto ret = len;
        auto write_cursor = 1;
        auto cur = nums[0];
        for (int i = 1; i < len; i++){
            if (cur == nums[i]) {
                ret--;
            } else {
                nums[write_cursor++] = cur = nums[i];
            }
        }
        return ret;
    }
};
