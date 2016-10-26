class Solution1 {
public:
    void msort(vector<int>& ret, vector<int>& nums, int* pos, int lo, int hi){
        if (hi - lo < 2) return;
        int mid = lo + (hi - lo) / 2;
        msort(ret, nums, pos, lo, mid);
        msort(ret, nums, pos, mid, hi);
        int* rep = new int[hi - lo];
        move(pos + lo, pos + hi, rep);
        int l = 0, r = mid - lo, semicount = 0;
        for(int i = 0; i < hi - lo; i++){
            if (r >= hi - lo || l < mid - lo && nums[rep[l]] <= nums[rep[r]]) {
                ret[rep[l]] += semicount;
                pos[i + lo] = rep[l++];
            } else {
                semicount++;
                pos[i + lo] = rep[r++];
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len, 0);
        int* pos = new int[len];
        iota(pos, pos + len, 0);
        msort(ret, nums, pos, 0, len);
        return ret;
    }
};
