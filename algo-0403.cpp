class Solution {
public:
    bool myCross(set<int>& smap, int node, int dist){
        if (node == 0) return dist == 1;

        auto next_dist = dist - 1;
        auto next_node = node - next_dist;
        bool result = false;
        if (next_dist > 0 && next_node >= 0 && smap.find(next_node) != smap.end()) {
            result = myCross(smap, next_node, next_dist);
        }
        
        next_dist = dist;
        next_node = node - next_dist;
        if (result) return true;
        else if (next_dist > 0 && next_node >= 0 && smap.find(next_node) != smap.end()) {
            result = myCross(smap, next_node, next_dist);
        }

        next_dist = dist + 1;
        next_node = node - next_dist;

        if (result) return true;
        else if (next_dist > 0 && next_node >= 0 && smap.find(next_node) != smap.end()) {
            result = myCross(smap, next_node, next_dist);
        }

        return result;
    }
    bool canCross(vector<int>& stones) {
        set<int> smap;
        for(auto s : stones){
            smap.insert(s);
        }
        
        auto iter = smap.rbegin();
        auto len = stones.size();
        int max_step = ceil(sqrt(*iter * 2));
        for(int i = len - 1; i > 0; i--){
            auto s = stones[i];
            auto dist = *iter - s;
            if (dist > max_step)
              break;
            auto result = myCross(smap, s, dist);
            if (result) return true;
        }
        return false;
    }
};
