class Solution {
private:
    std::vector<std::vector<int>> m_subsets{};

private:
    void backtrack(std::vector<int>& current, const std::vector<int>& nums, const int i, const int target) {
        if (target == 0) {
            m_subsets.emplace_back(current);
            return;
        }

        if (target < 0 || i == nums.size()) {
            return;
        }

        backtrack(current, nums, i + 1, target);

        current.push_back(nums[i]);
        backtrack(current, nums, i, target - nums[i]);
        current.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<int> vec;
        backtrack(vec, nums, 0, target);
        return m_subsets;
    }
};
