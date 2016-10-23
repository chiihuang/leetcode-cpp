class Solution {
public:
    int findShortestPath(string& beginWord, string& endWord, unordered_set<string>& dict,
        unordered_map<string, vector<string>>& graph) {
        int ret = 2, wlen = beginWord.size();
        dict.erase(beginWord); dict.erase(endWord);
        unordered_set<string> head = { beginWord }, tail = { endWord };
        bool flip = false;
        while(head.size()){
            if (head.size() > tail.size()) {
                swap(head, tail);
                flip = !flip;
            }
            unordered_set<string> nhead;
            bool found = false;
            // find nexts
            int len = head.size(), k = 0;
            for(auto it = head.begin(); k < len; ++it, ++k){
                string cur = *it;
                for(int i = 0; i < wlen; i++){
                    char c = cur[i];
                    for(int j = 0; j < 26; j++){
                        cur[i] = 'a' + j;
                        if (cur[i] == c) continue;
                        if (tail.find(cur) != tail.end()) found = true;
                        if (tail.find(cur) != tail.end() ||
                            dict.find(cur) != dict.end()){
                            if (flip)
                                graph[cur].push_back(*it);
                            else
                                graph[*it].push_back(cur);
                            nhead.insert(cur);
                        }
                    }
                    cur[i] = c;
                }
            }
            
            if (found) return ret;
            for(auto it = nhead.begin(); it != nhead.end(); ++it) dict.erase(*it);
            swap(head, nhead);
            ret++;
        }
        return 0;
    }
    void dfs(vector<vector<string>>& ret, string& beginWord, string& endWord, vector<string>& path, unordered_map<string, vector<string>>& graph){
        if (beginWord == endWord) {
            ret.push_back(path);
            return;
        }
        
        for(auto& next : graph[beginWord]){
            path.push_back(next);
            dfs(ret, next, endWord, path, graph);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, vector<string>> graph;
        int depth = findShortestPath(beginWord, endWord, wordList, graph);
        vector<vector<string>> ret;
        vector<string> path = { beginWord };
        dfs(ret, beginWord, endWord, path, graph);
        return ret;
    }
};
