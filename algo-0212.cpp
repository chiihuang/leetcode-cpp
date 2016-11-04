class Solution {
public:
    int width, height;
    struct Node {
        string word;
        Node* next[26];
        int numOfNexts;
        Node(): numOfNexts(0) {
            fill_n(next, 26, nullptr);
        }
    };
    void dfs(vector<vector<char>>& board, int i, int j, Node* node, vector<string>& ret){
        char c = board[i][j];
        if (c == '#') return;
        Node* next = node->next[c - 'a'];
        if (!next) return;
        if (next->word.size()) {
            ret.push_back(next->word);
            next->word.clear();
        }
        if (next->numOfNexts == 0){
            node->next[c - 'a'] = nullptr;
            node->numOfNexts--;
            return;
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, next, ret);
        if (j > 0) dfs(board, i, j - 1, next, ret);
        if (i + 1 < width) dfs(board, i + 1, j, next, ret);
        if (j + 1 < height) dfs(board, i, j + 1, next, ret);
        board[i][j] = c;
    }
    Node* buildTrie(vector<string>& words){
        Node* root = new Node();
        for(auto w: words){
            Node* cur = root;
            for(auto c: w){
                if (!cur->next[c - 'a']) {
                    cur->numOfNexts++;
                    cur->next[c - 'a'] = new Node();
                }
                cur = cur->next[c - 'a'];
            }
            cur->word = w;
        }
        return root;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        width = board.size();
        height = width ? board[0].size() : 0;
        Node* root = buildTrie(words);
        vector<string> ret;
        for(int i = 0; i < width; i++)
            for(int j = 0; j < height; j++)
                dfs(board, i, j, root, ret);
        return ret;
    }
};
