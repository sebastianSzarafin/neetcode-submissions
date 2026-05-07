#include <array>

class PrefixTree {
private:
    struct Node {
        std::array<Node*, 26> children;
        bool is_end_of_word = false;

        Node() {
            children.fill(nullptr);
        }
    };

    Node* root = new Node();

public:
    PrefixTree() {

    }

    void insert(std::string word) {
        Node* p = root;
        for (std::size_t i = 0; i < word.size(); ++i) {
            Node** c = &p->children[word[i] - 'a'];
            if (!(*c)) { *c = new Node(); }
            p = *c;
        }
        p->is_end_of_word = true;
    }

    bool search(std::string word) {
        Node* p = root;
        for (std::size_t i = 0; i < word.size(); ++i) {
            Node* c = p->children[word[i] - 'a'];
            if (!c) { return false; }
            p = c;
        }
        return p->is_end_of_word;
    }

    bool startsWith(std::string prefix) {
        Node* p = root;
        for (std::size_t i = 0; i < prefix.size(); ++i) {
            Node* c = p->children[prefix[i] - 'a'];
            if (!c) { return false; }
            p = c;
        }
        return true;
    }
};