class PrefixTree {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isWordEnd;

        TrieNode() {
            isWordEnd = false;
            for(int i=0; i<26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode * root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(char c: word) {
            int index = c - 'a';
            if(!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }

            cur = cur->children[index];
        }
        cur->isWordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            int index = c - 'a';
            if (!cur->children[index]) return false;

            cur = cur->children[index];
        }
        return cur->isWordEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(!cur->children[index]) return false;
            cur = cur->children[index];
        }

        return true;
    }
};
