class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string& word) {
        auto curr = root;
        for(char c: word) {
            int index = c - 'a';
            if(!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }
        curr->is_word = true;
    }
    
    bool search(string& word) {
        return searchHelper(word, 0, root);
    }

private:
    class TrieNode {
        public:
            bool is_word;
            vector<TrieNode*> children;
        TrieNode() : is_word(false), children(26, nullptr) {

        }
    };

    bool searchHelper(string& word,int index, TrieNode* curr ) {
        if(!curr) return false;

        if(index == word.size()) return curr->is_word;

        char ch = word[index];
        if( ch == '.') {
            for(int i=0; i<26; i++) {
                if(curr->children[i]) {
                    if(searchHelper(word, index + 1, curr->children[i])){
                        return true;
                    }
                }
            }
            return false;
        } else {
            int searchIndex = ch - 'a';
            return searchHelper(word, index + 1, curr->children[searchIndex]);
        }

    };



    TrieNode* root;
};
