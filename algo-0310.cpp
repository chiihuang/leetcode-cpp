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
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        vector<set<int>> adj(n);
        vector<int> leaves;
        
        for(auto i = 0; i < n; i++) adj[i] = {};
        for(auto e : edges){
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
        }

        // find leafs
        for(auto i = 0; i < n; i++)
            if(adj[i].size() == 1) leaves.push_back(i);
        
        while(!leaves.empty()){
            vector<int> next_leaves;
            for(auto c : leaves){
                for(auto j : adj[c]){
                    adj[j].erase(c);
                    if (adj[j].size() == 1) next_leaves.push_back(j);
                }
            }
            if (next_leaves.size() == 0) return leaves;
            leaves = next_leaves;
        }
        return {};
    }
};
