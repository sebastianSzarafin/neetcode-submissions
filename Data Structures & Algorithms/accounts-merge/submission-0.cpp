#include <ranges>

struct UnionFind {
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        rank.resize(n, 0); // rank is initially 0 for all sets
    }

    int find(int x) {
        if (parent[x] != x) {
            // path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    std::vector<int> parent;
    std::vector<int> rank; // for union optimization
};

class Solution {
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
        const int n = accounts.size();

        UnionFind unionFind(n);
        std::map<std::string, int> emailAccountMap{};

        for (int i = 0; i < n; ++i) {
            const auto account = accounts[i];
            for (auto it = account.begin() + 1; it < account.end(); ++it) {
                std::string email = *it;
                if (emailAccountMap.contains(email)) {
                    unionFind.unionSets(i, emailAccountMap.at(email));
                }
                else {
                    emailAccountMap.try_emplace(email, i);
                }
            }
        }

        std::map<int, std::set<std::string>> accountIdEmailMap{};

        for (const auto& id : emailAccountMap | std::views::values) {
            const int rootId = unionFind.find(id);

            accountIdEmailMap.try_emplace(rootId, std::set<std::string>{});
            auto& emailSet = accountIdEmailMap.at(rootId);

            for (auto it = accounts[id].begin() + 1; it < accounts[id].end(); ++it) {
                if (const auto& email = *it; !emailSet.contains(email)) {
                    emailSet.emplace(email);
                }
            }
        }

        std::vector<std::vector<std::string>> result{};
        result.reserve(accountIdEmailMap.size());

        for (const auto& [id, emailSet] : accountIdEmailMap) {
            std::vector<std::string> nameAndEmails{};
            nameAndEmails.emplace_back(accounts[id].front());
            for (const auto& email : emailSet) {
                nameAndEmails.emplace_back(email);
            }
            result.emplace_back(nameAndEmails);
        }

        return result;
    }
};