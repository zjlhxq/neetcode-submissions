class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto curr = root;
        for(char c: word) {
            if(!curr->children.contains(c)) {
                curr->children[c] = new TrieNode;
            }

            curr = curr->children[c];
        }

        curr->is_word = true;
    }
    
    bool search(string word) {
        auto curr = root;
        for( char c: word) {
            if(!curr->children.contains(c)) return false;
            curr = curr->children[c];
        }

        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        for( char c: prefix) {
            if(!curr->children.contains(c)) return false;

            curr = curr->children[c];
        }

        return true;
    }

private:
    class TrieNode {
    public:
        bool is_word;
        unordered_map<char, TrieNode*> children;

        TrieNode(): is_word(false) {}
    };

    TrieNode * root;

};
