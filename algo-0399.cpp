class Solution {
public:
    double dfs(unordered_map<string, unordered_map<string, double>>& m, set<string>& vi, string& from, string& to){
        if (m.find(from) == m.end() || vi.find(from) != vi.end()) return -1;
        if (from == to) return 1;
        vi.insert(from);
        auto nexts = m[from];
        for(auto it = nexts.begin(); it != nexts.end(); ++it){
            string next = it->first;
            double weight = it->second;
            double result = dfs(m, vi, next, to);
            if(result < 0) continue;
            return weight * result;
        }
        return -1;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> m;
        for(int i = 0; i < equations.size(); i++){
            auto e = equations[i];
            auto v = values[i];
            m[e.first][e.second] = v;
            m[e.second][e.first] = 1 / v;
        }
        
        vector<double> ret;
        
        for(auto q : queries) {
            set<string> vi;
            auto ans = dfs(m, vi, q.first, q.second);
            ret.push_back(ans);
        }
        return ret;
    }
};
