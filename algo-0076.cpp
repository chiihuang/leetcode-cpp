/**
 * NOT SO GOOD SOLUTION
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int len = s.size(), uniques = 0;
        int* hist = new int[256]{0};
        // build histogram
        for(char c : t) if (hist[c]++ == 0) uniques++;
        // deque
        queue<int>* index = new queue<int>[256]();
        map<int, int> m;
        string ret;
        for(int i = 0; i < len; i++){
            char c = s[i];
            if (!hist[c]) continue;
            index[c].push(i);
            if (index[c].size() > hist[c]) {
                m.erase(index[c].front());
                index[c].pop();
            } else if (index[c].size() == hist[c])
                uniques--;
            m[i] = c;
            if (uniques == 0) {
                int first = m.begin()->first;
                if (ret.size() == 0 || ret.size() > i - first + 1) {
                    ret = s.substr(first, i - first + 1);
                }
                index[s[first]].pop();
                uniques++;
                m.erase(first);
            }
        }
        
        return ret;
    }
};
