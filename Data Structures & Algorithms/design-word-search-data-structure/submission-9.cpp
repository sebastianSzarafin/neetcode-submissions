class WordDictionary {
private:
    struct Node {
        std::array<Node*, 26> children;
        bool is_end = false;

        Node() {
            children.fill(nullptr);
        }
    };

    Node* root;

private:
    bool search(Node* p, const std::string& word, const int i) {
        const int n = word.size();

        if (!p) {
            return false;
        }

        if (i == n) {
            return p->is_end;
        }

        if (word[i] == '.') {
            for (Node* c : p->children) {
                if (!c) { continue; }
                if (search(c, word, i + 1)) { return true; }
            }
            return false;
        }
        else {
            return search(p->children[word[i] - 'a'], word, i + 1);
        }
    }

public:
    WordDictionary() : root(new Node()) {
        
    }
    
    void addWord(string word) {
        Node* p = root;
        for (int i = 0; i < word.size(); ++i) {
            Node** c = &p->children[word[i] - 'a'];
            if (!(*c)) { *c = new Node(); }
            p = *c;
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        return search(root, word, 0);
    }
};
