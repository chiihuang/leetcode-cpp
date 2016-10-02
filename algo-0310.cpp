class Solution {
public:
    vector<int> subOptFindMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> deg(n);
        vector<set<int>> rela(n);
        set<int> nodes;
        
        // init
        for(auto i = 0; i < n; i++){
            nodes.insert(i);
            deg[i] = 0;
            rela[i] = {};
        }
        
        for(auto e : edges){
            deg[e.first]++;
            deg[e.second]++;
            rela[e.first].insert(e.second);
            rela[e.second].insert(e.first);
        }

        while(!nodes.empty()){
            // find min degree
            int min_d = n;
            vector<int> cand;
            
            // find leafs
            for(auto it = nodes.begin(); it != nodes.end(); ++it){
                auto i = *it;
                if(deg[i] == min_d){
                    cand.push_back(i);
                } else if (deg[i] < min_d) {
                    cand.clear();
                    cand.push_back(i);
                    min_d = deg[i];
                }
            }
            
            // done
            if (cand.size() == nodes.size()) return cand;
            
            for(auto c : cand){
                for(auto j : rela[c]){
                    rela[j].erase(c);
                    deg[j]--;
                }
                rela[c].clear();
                nodes.erase(c);
            }
        }
        return {};
    }
};
