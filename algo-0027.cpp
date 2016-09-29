class Solution {
public:
    void swap(int& a, int& b){
        auto temp = a;
        a = b;
        b = temp;
    }
    int removeElement(vector<int>& nums, int val) {
        auto olen = nums.size();
        int len = 0;
        for(int i = 0; i < olen; i++){
            if (nums[i] != val){
                swap(nums[len++], nums[i]);
            }            
        }
        return len;
    }
};
