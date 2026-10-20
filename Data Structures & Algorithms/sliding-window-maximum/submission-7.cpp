class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int>> q{};

        for (int i = 0; i < k; ++i) {
            q.push({nums[i], i});
        }

        std::vector<int> result{};

        for (int i = k; i < nums.size(); ++i) {
            result.emplace_back(q.top().first);
            while (!q.empty() && q.top().second <= i - k) {
                q.pop();
            }
            q.push({nums[i], i});
        }
        result.emplace_back(q.top().first);

        return result;
    }
};
