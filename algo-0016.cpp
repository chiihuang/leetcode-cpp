class Solution {
public:
    int twoSumClosest(vector<int>& nums, int start, int target) {
        int ret = nums[start] + nums[start + 1];
        for(int i = start; i < nums.size() - 1; i++){
            int subtarget = target - nums[i];
            
            // binary search starts
            int hi = nums.size();
            int lo = i + 1;
            int mid = lo;
            while(hi > lo){
                mid = (hi + lo) / 2;
                if (nums[mid] == subtarget) {
                    break;
                } else if (nums[mid] > subtarget) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (abs(subtarget - nums[mid]) < abs(target - ret)){
                ret = nums[mid] - subtarget + target;
            }
        }
        return ret;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int subtarget = target - nums[i];
            int best = twoSumClosest(nums, i + 1, subtarget);
            if (abs(best - subtarget) < abs(ret - target))
                ret = best - subtarget + target;
        }
        return ret;
    }
};
