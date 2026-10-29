class Trie {
private:
    struct Node {
        std::array<Node*, 26> m_children{};
        bool m_isWordEnd = false;

        Node() {
            m_children.fill(nullptr);
        }
    };

    Node* m_head = new Node();

public:
    void insert(const std::string& word) {
        Node* p = m_head;
        for (int i = 0; i < word.size(); ++i) {
            Node** c = &p->m_children[word[i] - 'a'];
            if (!(*c)) { *c = new Node(); }
            p = *c;
        }
        p->m_isWordEnd = true;
    }

    bool find(const std::string& word) {
        Node* p = m_head;
        for (int i = 0; i < word.size(); ++i) {
            Node* c = p->m_children[word[i] - 'a'];
            if (!c) { return false; }
            p = c;
        }
        return p->m_isWordEnd;
    }
};

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        const int n = s.size();

        Trie trie{};
        int t = 0;
        for (const auto& w : wordDict) {
            trie.insert(w);
            t = std::max(t, static_cast<int>(w.size()));
        }

        std::vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n; i >= 0; --i) {
            for (int j = std::max(0, i - t); j < i; ++j) {
                if (!dp[j] && dp[i]) {
                    dp[j] = trie.find(s.substr(j, i - j));
                }
            }
        }

        return dp[0];
    }
};