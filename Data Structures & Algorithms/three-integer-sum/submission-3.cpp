class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);

        const auto n = nums.size();

        std::vector<std::vector<int>> result{};

        for(std::size_t i = 0; i < n - 2; ++i) {
            if (i && nums[i - 1] == nums[i]) { continue; }
            std::size_t j = i + 1;
            std::size_t k = n - 1;
            while (j != k) {
                const auto sum = nums[j] + nums[k];
                if (sum < -nums[i]) {
                     ++j;
                }
                else if (sum > -nums[i]) { 
                    --k;
                }
                else {
                    result.emplace_back(std::vector{nums[i], nums[j], nums[k]}); 
                    do {
                        ++j;
                    }
                    while (j != k && nums[j - 1] == nums[j]);
                }
            }
        }

        return result;
    }
};
