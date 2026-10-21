class Solution {
private: 
    void backtrack(int& sum, std::vector<int>& current, const std::vector<int>& nums, const int i) {        
        if (i == nums.size()) {
            int x = 0;
            for (const auto n : current) {
                x ^= n;
            }
            sum += x;
            return;
        }

        backtrack(sum, current, nums, i + 1);

        current.push_back(nums[i]);
        backtrack(sum, current, nums, i + 1);
        current.pop_back();
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        std::vector<int> subset{};
        backtrack(sum, subset, nums, 0);
        return sum;
    }
};