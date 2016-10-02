class Solution {
public:
    // find first greater or equal than target
    int binSearch(vector<int>& nums, int target){
        int hi = nums.size();
        int lo = 0;
        while(lo < hi){
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] < target){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start = binSearch(nums, target);
        if (start == nums.size() || nums[start] != target) return { -1, -1 };
        
        auto end =  binSearch(nums, target + 1);
        return {start, end - 1};
    }
};
