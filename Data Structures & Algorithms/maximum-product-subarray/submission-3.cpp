class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int result = nums[0];
        int max_prod = nums[0];
        int min_prod = nums[0];
        for (int i = 1; i < n; ++i) {
            int prev_max_prod = max_prod;
            int prev_min_prod = min_prod;
            max_prod = std::max({prev_max_prod * nums[i], prev_min_prod * nums[i], nums[i]});
            min_prod = std::min({prev_max_prod * nums[i], prev_min_prod * nums[i], nums[i]});
            result = std::max(max_prod, result);
        }
        return result;
    }
};
