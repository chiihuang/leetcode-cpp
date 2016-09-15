class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int area_max = 0;
        int low = 0;
        int high = len - 1;
        while(low < high) {
            area_max = max(area_max, (high - low) * min(height[low], height[high]));
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return area_max;
    }
};
