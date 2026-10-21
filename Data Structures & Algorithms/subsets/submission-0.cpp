class Solution {
private:
    std::vector<std::vector<int>> m_subsets{};

private:
    void backtrack(std::vector<int>& current, const std::vector<int>& nums, const int i) {
        if (i == nums.size()) {
            m_subsets.emplace_back(current);
            return;
        }

        backtrack(current, nums, i + 1);

        current.push_back(nums[i]);
        backtrack(current, nums, i + 1);
        current.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> vec;
        backtrack(vec, nums, 0);
        return m_subsets;
    }
};
