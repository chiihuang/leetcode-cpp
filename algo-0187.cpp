class Solution {
private:
    struct Node{
        int count;
        Node* next[4];
        Node() : count(0) {
            fill_n(next, 4, nullptr);
        }
    };
    int encode(char c){
        switch(c){
            case 'A': return 0;
            case 'T': return 1;
            case 'C': return 2;
            case 'G': return 3;
        }
        return -1;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 11) return {};
        int len = s.size();
        Node* root = new Node();
        vector<string> ret;
        for(int i = 0; i < len - 9; i++){
            Node* cur = root;
            for(int j = 0; j < 10; j++){
                int n = encode(s[i + j]);
                if (!cur->next[n])
                    cur->next[n] = new Node();
                cur = cur->next[n];
            }
            if (2 == ++cur->count)
                ret.push_back(s.substr(i, 10));
        }
        return ret;
    }
};
