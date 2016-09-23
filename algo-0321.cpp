class Solution {
public:
    vector<int> _maxNumber(vector<int>& nums, int k){
        struct D {
            int pos;
            int val;
        };
        struct Compare {
            bool operator()(D a, D b){
                if (a.val < b.val) {
                    return true;
                } else if (a.val > b.val) {
                    return false;
                } else {
                    return a.pos > b.pos;
                }
            };
        };
        priority_queue<D, vector<D>, Compare> pq;
        vector<int> ret;
        int len = nums.size();
        if (len <= 0) return ret;
        
        int i;
        for(i = 0; i < len - k + 1; i++){
            D d;
            d.val = nums[i];
            d.pos = i;
            pq.push(d);
        }
        
        
        int lo = 0;
        while(k > 0){
            auto d = pq.top();
            pq.pop();
            if (d.pos >= lo) {
                ret.push_back(d.val);
                k--;
                lo = d.pos;
                if (i < len) {
                    D d;
                    d.val = nums[i];
                    d.pos = i++;
                    pq.push(d);
                }
            }
        }
        return ret;
    }
    vector<int> mergeMaxNumber(vector<int>& nums1, vector<int>& nums2){
        vector<int> ret;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int pt1 = 0;
        int pt2 = 0;
        while(pt1 < len1 || pt2 < len2){
            if (pt1 >= len1 && pt2 >= len2) {
                break;
            } else if (pt1 >= len1) {
                ret.push_back(nums2[pt2++]);
            } else if (pt2 >= len2) {
                ret.push_back(nums1[pt1++]);
            } else {
                if (nums1[pt1] > nums2[pt2])
                    ret.push_back(nums1[pt1++]);
                else if (nums1[pt1] < nums2[pt2])
                    ret.push_back(nums2[pt2++]);
                else {
                    int np1 = pt1 + 1;
                    int np2 = pt2 + 1;
                    int flag = 0;
                    while(np1 < len1 && np2 < len2) {
                        if (nums1[np1] > nums2[np2]) {
                            flag = 1;
                            break;
                        } else if (nums1[np1] < nums2[np2]) {
                            flag = -1;
                            break;
                        }
                        np1++;
                        np2++;
                    }
                    if (flag == 0) {
                        if (np1 < len1) flag = 1;
                        else flag = -1;
                    }
                    
                    // find out winner
                    if (flag > 0) {
                        ret.push_back(nums1[pt1++]);
                    } else {
                        ret.push_back(nums2[pt2++]);
                    }
                }
            }
        }
        return ret;
    }
    // return true if nums1 > nums2
    bool compare(vector<int>& nums1, vector<int>& nums2){
        for(int i = 0; i < nums1.size(); i++){
            if (nums1[i] > nums2[i])
                return true;
            else if (nums1[i] < nums2[i])
                return false;
        }

        // default is false
        return false;
    }
    void print_vec(vector<int> v){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        for(int i = 0; i < k; i++){
            ret.push_back(-1);
        }

        // k1 for nums1 and k2 for nums2; k2 = k - k1
        for(int k1 = 0; k1 < k + 1; k1++){
            cout << "k1 " << k1 << endl;
            if (k1 > nums1.size() || k - k1 > nums2.size())
                continue;
            auto subnums1 = _maxNumber(nums1, k1);
            // cout << "subnums1";
            // print_vec(subnums1);
            auto subnums2 = _maxNumber(nums2, k - k1);
            // cout << "subnums2";
            // print_vec(subnums2);
            auto subnums = mergeMaxNumber(subnums1, subnums2);
            // print_vec(subnums);
            if (compare(subnums, ret))
                ret = subnums;
            // print_vec(ret);
        }
        return ret;
    }
};
