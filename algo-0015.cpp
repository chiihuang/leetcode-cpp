class Solution {
public:
    int parent(int i) {
      return (i - 1) / 2;
    }
    
    int left(int i) {
      return 2 * i + 1;
    }
    
    int right(int i) {
      return 2 * i + 2;
    }
    
    void swap(int& a, int& b){
      int temp = a;
      a = b;
      b = temp;
    }
    
    vector<int> heapSort(vector<int>& nums){
      int len = nums.size();
      for(int i = 0; i < len; i++){
        int pi = parent(i);
        int ci = i;
        while(pi >= 0){
          if(nums[ci] > nums[pi]){
            swap(nums[ci], nums[pi]);
            ci = pi;
            pi = parent(pi);
          } else {
            break;
          }
        }
      }
    
      for(int i = len - 1; i >= 0; i--){
        swap(nums[0], nums[i]);
    
        int ci = 0;
    
        while(true){
          int li = left(ci);
          int ri = right(ci);
          if(li >= i && ri >= i) break;
    
          if (ri >= i) {
            if (nums[ci] < nums[li]) {
              swap(nums[ci], nums[li]);
              ci = li;
            }
            break;
          } else if (li >= i) {
            if (nums[ci] < nums[ri]) {
              swap(nums[ci], nums[ri]);
              ci = ri;
            }
            break;
          } else {
            if (nums[li] > nums[ri] && nums[ci] < nums[li]) {
              swap(nums[ci], nums[li]);
              ci = li;
            } else if (nums[ci] < nums[ri]){
              swap(nums[ci], nums[ri]);
              ci = ri;
            } else {
              break;
            }
          }
        }
      }
      return nums;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        heapSort(nums);
        unordered_map<int, int> ntoi;
        vector<vector<int>> ret;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            ntoi[nums[i]] = i;
        }
        for(int i = 0; i < len; i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < len; j++){
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int target = -nums[i] - nums[j];
                if (ntoi.find(target) != ntoi.end() &&
                    ntoi[target] > j){
                    vector<int> v = {nums[i], nums[j], target};
                    ret.push_back(v);
                }
            }
        }
        return ret;
    }
};
