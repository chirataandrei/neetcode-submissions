struct TrieNode {
    TrieNode *children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

bool search_helper(const string &word, TrieNode *curr, int depth)
{
    if (word[depth] == '\0') {
        return curr->isEnd;
    }

    if (word[depth] == '.') {
        for (int i = 0; i < 26; i++) {
            if (curr->children[i] != nullptr) {
                if (search_helper(word, curr->children[i], depth + 1)) {
                    return true;
                }
            }
        }
        return false;
    } else {
        int index = word[depth] - 'a';

        if (curr->children[index] != nullptr) {
            return search_helper(word, curr->children[index], depth + 1);
        }
        return false;
    }
    
}


class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;

        for (int i = 0; word[i] != '\0'; i++) {
            int index = word[i] - 'a';
            
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            } 

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        return search_helper(word, root, 0);
    }
};
