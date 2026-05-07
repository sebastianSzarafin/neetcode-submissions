class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        const int m = candidates.size();

        std::vector<std::vector<int>> result;
        
        std::sort(candidates.begin(), candidates.end());

                        for (auto s : candidates) {
                    std::cout << s << "\t";
                }
                std::cout << "\n";

        std::queue<std::tuple<std::vector<int>, int, int>> q;
        q.push({{}, 0, 0});
        
        while (!q.empty()) {
            const int n = q.size();
            int i = 0;
            while (i < n) {
                const auto& [subset, start, sum] = q.front();

                for (auto s : subset) {
                    std::cout << s << "\t";
                }
                std::cout << ",\t" << start << "\n";

                int c = start;
                while (c < m) {
                    if (start < c && 0 < c && candidates[c - 1] == candidates[c]) {
                        c++;
                        continue;
                    }

                    std::vector<int> new_subset = subset;
                    new_subset.emplace_back(candidates[c]);
                    int new_sum = sum + candidates[c];

                    const int diff = new_sum - target;
                    if (diff == 0) {
                        result.emplace_back(new_subset);
                    }
                    else if (diff < 0) {
                        q.push({new_subset, c + 1, new_sum});
                    }

                    c++;
                }

                q.pop();
                i++;
            }
        }

        return result;
    }
};
