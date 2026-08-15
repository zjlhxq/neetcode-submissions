class PrefixTree {
private:
    class TrieNode {
    public:
        bool is_word;
        vector<TrieNode*> children;

        TrieNode() : is_word(false), children(26, nullptr) {};
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto curr = root;

        for(char c : word) {
            int index =  c - 'a';
            if(!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->is_word = true; 
    }
    
    bool search(string word) {
        auto curr = root;
        for( char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) return false;

            curr = curr->children[index];
        }

        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;

        for(char c : prefix) {
            int index = c - 'a';
            if(!curr->children[index]) return false;

            curr = curr->children[index];
        }

        return true;
    }
};
